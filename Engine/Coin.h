#pragma once

#include "Vec2.h"
#include "TileMap.h"
#include "Player.h"
#include "UpdateFrequency.h"

class Coin
{
public:
	Coin(TileMap& tileMap, Player& player, UpdateFrequency& uf);
	void update(float dt, float updateFrequency);
private:
	void reset();
private:
	Vec2 pos;
	TileMap& tileMap;
	Player& player;
	UpdateFrequency& uf;
};

