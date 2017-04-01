#pragma once

#include "Vec2.h"
#include "TileMap.h"

class Coin
{
public:
	Coin(TileMap& tileMap);
	void update(float dt);
private:
	void reset();
private:
	Vec2 pos;
	TileMap& tileMap;
};

