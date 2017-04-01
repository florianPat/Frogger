#include "Coin.h"

Coin::Coin(TileMap& tileMap) : tileMap(tileMap)
{
	reset();
}

void Coin::update(float dt)
{
	static float dtElapsed = 0;
		tileMap.setTileTypeAtPos(TileMap::TileType::Coin, pos);

	dtElapsed += dt;
	if (dtElapsed > 1.0f)
	{
		dtElapsed = 0;
		pos.x -= 1;
		if (pos.x == -1)
		{
			reset();
		}
	}
}

void Coin::reset()
{
	pos.x = tileMap.getTileMapWith() - 1;
	pos.y = tileMap.getTileMapHeight() / 2;
}
