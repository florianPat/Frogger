#pragma once

#include "Vec2.h"
#include "TileMap.h"
#include "Player.h"

class Coin
{
public:
	Coin(TileMap& tileMap, Player& player);
	void update(float dt);
private:
	void reset();
private:
	Vec2 pos;
	TileMap& tileMap;
	Player& player;
};

