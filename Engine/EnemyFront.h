#pragma once

#include "Vec2.h"
#include "TileMap.h"
#include "UpdateFrequency.h"
#include "Player.h"
#include <random>

class EnemyFront
{
public:
	EnemyFront(Player& player, TileMap& tileMap, UpdateFrequency& uf);
	void update(float dt, float updateFrequency);
private:
	void reset();
private:
	Vec2 pos;
	TileMap& tileMap;
	Player& player;
	UpdateFrequency& uf;
	std::mt19937 rng;
	std::uniform_int_distribution<int> dist;
	static constexpr float updateFrequencyMultiply = 1.2f;
};

