#include "Car.h"

Car::Car(float yPos, Graphics & gfx) : gfx(gfx), width(48), height(48), pos(752, yPos),
										boundingBox(pos, width, height)
{
}

void Car::update(float dt)
{
	pos.x -= speed * dt;

	if (pos.x < 0)
		pos.x = gfx.ScreenWidth - width;

	boundingBox.left = pos.x;
	boundingBox.top = pos.y;
	boundingBox.right = pos.x + width;
	boundingBox.bottom = pos.y + height;
}

void Car::draw()
{
	gfx.DrawRect(boundingBox, color);
}

RectF Car::getRect()
{
	return boundingBox;
}
