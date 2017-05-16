#include "Car.h"

Car::Car(float yPos, Graphics & gfx, int speed) : gfx(gfx), width(50), height(48), pos(752, yPos),
										boundingBox(pos, width, height), speed(speed)
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
