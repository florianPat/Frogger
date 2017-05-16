#include "Lake.h"

Lake::Float::Float(int yPos, int width, int direction, Graphics& gfx, int constSpeed) : width(width), constSpeed(constSpeed),
													boundingBox(pos, width, height), gfx(gfx), speed(direction > 0 ? constSpeed : -constSpeed),
													pos((direction < 0 ? gfx.ScreenWidth - width : 0.0f), yPos)
{
}

void Lake::Float::update(float dt)
{
	if (speed < 0)
	{
		pos.x += speed * dt;

		if (pos.x < 0)
		{
			speed *= -1;
			pos.x = 0;
		}
	}
	else
	{
		pos.x += speed * dt;

		if (pos.x + width > gfx.ScreenWidth)
		{
			speed *= -1;
			pos.x = gfx.ScreenWidth - (float)width;
		}
	}

	boundingBox.left = pos.x;
	boundingBox.top = pos.y;
	boundingBox.right = pos.x + width;
	boundingBox.bottom = pos.y + height;
}

void Lake::Float::draw()
{
	gfx.DrawRect(boundingBox, color);
}

RectF Lake::Float::getBoundingBox()
{
	return boundingBox;
}

int Lake::Float::getSpeed()
{
	return speed;
}

Lake::Lake(float yPos, Graphics & gfx) : pos(0, yPos), gfx(gfx), 
										 boundingBox(pos, (float)gfx.ScreenWidth, gfx.ScreenHeight / 3.0f), 
										 floats(), rng(), distFloatSpeed(30, 70), distWaitTime(90, 120)
{
	for (int i = 0; i < numFloats; ++i)
	{
		floats.push_back(Float((int)yPos + i * 40, distWaitTime(rng) /*width*/, 1, gfx, distFloatSpeed(rng)));
	}
}

void Lake::draw()
{
	gfx.DrawRect(boundingBox, color);

	if (delay == numFloats)
	{
		for (auto it = floats.begin(); it != floats.end(); ++it)
		{
			it->draw();
		}
	}
	else
	{
		if (waitTime == 0)
		{
			delay++;
			waitTime = distWaitTime(rng);
		}
		else
		{
			auto it = floats.begin();
			for (int z = 0; z < delay; z++, it++)
			{
				it->draw();
			}
			waitTime--;
		}
	}
}

void Lake::update(float dt)
{
	if (delay == numFloats)
	{
		for (auto it = floats.begin(); it != floats.end(); ++it)
		{
			it->update(dt);
		}
	}
	else
	{
		auto it = floats.begin();
		for (int z = 0; z < delay; z++, it++)
		{
			it->update(dt);
		}
	}
}

std::vector<Lake::Float> Lake::getFloats()
{
	std::vector<Float> result;

	for (auto it = floats.begin(); it != floats.end(); ++it)
	{
		result.push_back(*it);
	}

	return result;
}

RectF Lake::getBoundingBox()
{
	return boundingBox;
}
