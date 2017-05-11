#pragma once

#include "Keyboard.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Player
{
	Vec2 pos;
	RectF boundingBox;
	static constexpr Color color = Colors::Green;
	static constexpr int width = 48, height = 48;
	static constexpr float speed = 50.0f;

	Keyboard& kbd;
	Graphics& gfx;
public:
	Player(Keyboard& keyboard, Graphics& graphics, const Vec2& pos);
	void update(float dt);
	void draw();
	bool isColliding(const RectF& other);
};