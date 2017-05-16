#pragma once

#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "Colors.h"
#include <vector>

class Lake
{
public:
	class Float
	{
		RectF boundingBox;
		Vec2 pos;
		int width;
		static constexpr int height = 40;
		static constexpr Color color = Colors::MakeRGB(165, 122, 11);
		static constexpr int constSpeed = 50; //Make random
		int speed;

		Graphics& gfx;
	public:
		Float(int yPos, int width, int direction, Graphics& gfx);
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

	std::vector<Float> floats;
	static constexpr int waitTime = 120; //Make random every new turn
	int delay = 0, i = waitTime;

	Graphics& gfx;
public:
	Lake(float yPos, Graphics& gfx);
	void draw();
	void update(float dt);
	std::vector<Float> getFloats();
	RectF getBoundingBox();
};