#include "Lake.h"

Lake::Float::Float(int yPos, int width, int direction, Graphics& gfx) : width(width), 
													boundingBox(pos, width, height), gfx(gfx), direction(direction),
													pos((direction < 0 ? gfx.ScreenWidth - width : 0), yPos)
{
}

void Lake::Float::update(float dt)
{
	if (direction < 0)
	{
		pos.x -= speed * dt;

		if (pos.x < 0)
		{
			direction *= -1;
			pos.x = 0;
		}
	}
	else
	{
		pos.x += speed * dt;

		if (pos.x + width > gfx.ScreenWidth)
		{
			direction *= -1;
			pos.x = gfx.ScreenWidth - width;
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

Lake::Lake(float yPos, Graphics & gfx) : pos(0, yPos), gfx(gfx), 
														boundingBox(pos, gfx.ScreenWidth, gfx.ScreenHeight / 3.0f), 
														floats()
{
	for (int i = 0; i < numFloats; ++i)
	{
		floats.push_back(Float(yPos + i * 40, 100 /*random! #width*/, 1, gfx));
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
		if (i == 0)
		{
			delay++;
			i = waitTime;
		}
		else
		{
			auto it = floats.begin();
			for (int z = 0; z < delay; z++, it++)
			{
				it->draw();
			}
			i--;
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

std::vector<RectF> Lake::getFloatsBoundingBox()
{
	std::vector<RectF> result;

	for (auto it = floats.begin(); it != floats.end(); ++it)
	{
		result.push_back(it->getBoundingBox());
	}

	return result;
}

RectF Lake::getBoundingBox()
{
	return boundingBox;
}
