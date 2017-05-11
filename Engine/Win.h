#pragma once

#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"

class Win
{
	Vec2 pos;
	static constexpr int width = Graphics::ScreenWidth, height = 32;
	RectF boundingBox;
public:
	Win();
	RectF getBoundingBox();
};