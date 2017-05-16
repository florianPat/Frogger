#pragma once

#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "Colors.h"
#include <vector>
#include <random>

class Lake
{
public:
	class Float
	{
		Vec2 pos;
		RectF boundingBox;
		int width;
		static constexpr int height = 40;
		static constexpr Color color = Colors::MakeRGB(165, 122, 11);
		int constSpeed;
		int speed;

		Graphics& gfx;
	public:
		Float(int yPos, int width, int direction, Graphics& gfx, int constSpeed);
		void update(float dt);
		void draw();
		RectF getBoundingBox();
		int getSpeed();
	};
private:
	Vec2 pos;
	RectF boundingBox;
	static constexpr Color color = Colors::Blue;
	static constexpr int numFloats = 5;

	std::mt19937 rng;
	std::uniform_int_distribution<int> distFloatSpeed;
	std::uniform_int_distribution<int> distWaitTime;

	std::vector<Float> floats;
	int waitTime = 0;
	int delay = 0;

	Graphics& gfx;
public:
	Lake(float yPos, Graphics& gfx);
	void draw();
	void update(float dt);
	std::vector<Float> getFloats();
	RectF getBoundingBox();
};