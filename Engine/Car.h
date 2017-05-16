#pragma once

#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Car
{
	Vec2 pos;
	RectF boundingBox;
	int width, height;
	int speed;
	static constexpr Color color = Colors::Red;

	Graphics& gfx;
public:
	Car(float yPos, Graphics& gfx, int speed);
	void update(float dt);
	void draw();
	RectF getRect();
};