#pragma once

#include "TileMap.h"
#include "UpdateFrequency.h"
#include "Player.h"
#include "Vec2.h"

class EnemyBack
{
public:
	EnemyBack(TileMap& tileMap, Player& player, UpdateFrequency& uf);
	void update(float dt, float updateFrequency);
	void setColums(int newColums);
	int getColums();
private:
	int nColums;
	TileMap& tileMap;
	Player& player;
	UpdateFrequency& uf;
};

