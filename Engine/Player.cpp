#include "Player.h"

Player::Player(Keyboard & keyboard, Graphics & graphics, const Vec2& pos, std::vector<Car>& cars, Lake& lake, Win& win)
	: 
	kbd(keyboard), gfx(graphics), pos(pos), boundingBox(pos, (float)width, (float)height), cars(cars), 
	startingPos(pos), lake(lake), win(win)
{
}

void Player::handleInput(float dt)
{
	Vec2 deltaPos = {};
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		deltaPos.x = -1;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		if (deltaPos.x < 0)
			deltaPos.x = 0;
		else
			deltaPos.x = 1;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		deltaPos.y = 1;
	}
	if (kbd.KeyIsPressed(VK_UP))
	{
		if (deltaPos.y > 0)
			deltaPos.y = 0;
		else
			deltaPos.y = -1;
	}

	deltaPos.Normalize();
	deltaPos *= speed * dt;

	pos += deltaPos;
}

void Player::handlePhysik(bool* isWin)
{
	*isWin = isColliding(win.getBoundingBox());

	for (auto it = cars.begin(); it != cars.end(); ++it)
	{
		if (isColliding(it->getRect()))
		{
			pos = startingPos;
			return;
		}
	}

	if (isColliding(lake.getBoundingBox()))
	{
		bool isInWater = true;

		std::vector<RectF> floatsBox = lake.getFloatsBoundingBox();
		for (auto it = floatsBox.begin(); it != floatsBox.end(); ++it)
		{
			isInWater = !(isColliding(*it));
		}

		if (isInWater)
			pos = startingPos;
	}
}

void Player::update(float dt, bool* isWin)
{
	handleInput(dt);

	handlePhysik(isWin);

	if (pos.x < 0)
		pos.x = 0;
	if (pos.y < 0)
		pos.y = 0;
	if (pos.x + width > gfx.ScreenWidth)
		pos.x = gfx.ScreenWidth - width;
	if (pos.y + height > gfx.ScreenHeight)
		pos.y = gfx.ScreenHeight - height;

	boundingBox.left = pos.x;
	boundingBox.top = pos.y;
	boundingBox.right = pos.x + width;
	boundingBox.bottom = pos.y + height;
}

void Player::draw()
{
	gfx.DrawRect(boundingBox, color);
}

bool Player::isColliding(RectF & other)
{
	return boundingBox.IsOverlappingWith(other);
}
