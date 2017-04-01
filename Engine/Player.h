#pragma once

#include "Vec2.h"
#include "TileMap.h"
#include "Keyboard.h"

class Player
{
public:
	Player(TileMap& tileMap, Keyboard& keyboard);
	void update(float dt, float updateFrequency);
	Vec2& getPos();
private:
	Vec2 pos;
	TileMap& tileMap;
	Keyboard& kbd;
	int tileMapWidth = tileMap.getTileMapWith();
	int tileMapHeight = tileMap.getTileMapHeight();
};

