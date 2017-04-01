#include "Coin.h"

Coin::Coin(TileMap& tileMap, Player& player, UpdateFrequency& uf) : tileMap(tileMap), player(player), uf(uf),
																	rng(), dist(0, tileMap.getTileMapHeight()-1)
{
	reset();
}

void Coin::update(float dt, float updateFrequency)
{
	static float dtElapsed = 0;
	tileMap.setTileTypeAtPos(TileMap::TileType::Coin, pos);

	dtElapsed += dt;
	if (dtElapsed > updateFrequency)
	{
		dtElapsed = 0;
		pos.x -= 1;
		if (pos.x == -1 || (player.getPos().x == pos.x && player.getPos().y == pos.y))
		{
			reset();
			if (pos.x != -1)
			{
				uf.setUpdateFrequency(uf.getUpdateFrequency() * 0.9f);
			}
		}
	}
}

void Coin::reset()
{
	pos.x = tileMap.getTileMapWith() - 1;
	pos.y = dist(rng);
}
