#pragma once

#include "Keyboard.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include <vector>
#include "Car.h"
#include "Lake.h"

class Player
{
	Vec2 pos;
	Vec2 startingPos;
	RectF boundingBox;
	static constexpr Color color = Colors::Green;
	static constexpr int width = 32, height = 32;
	static constexpr float speed = 50.0f;

	std::vector<Car>& cars;
	Lake& lake;

	Keyboard& kbd;
	Graphics& gfx;
private:
	void handleInput(float dt);
	void handlePhysik();
public:
	Player(Keyboard& keyboard, Graphics& graphics, const Vec2& pos, std::vector<Car>& cars, Lake& lake);
	void update(float dt);
	void draw();
	bool isColliding(RectF& other);
};