#include "EnemyBack.h"

EnemyBack::EnemyBack(TileMap& tileMap, Player& player, UpdateFrequency& uf) : nColums(1), tileMap(tileMap), uf(uf),
					player(player)
{
}

void EnemyBack::update(float dt, float updateFrequency)
{
	static float dtElapsed = 0;

	dtElapsed += dt;
	if (dtElapsed > updateFrequency)
	{
		dtElapsed = 0;
		for (int y = 0; y < tileMap.getTileMapHeight() - 1; ++y)
		{
			if (tileMap.getTileTypeAtpos(Vec2(nColums - 1, y)) == TileMap::TileType::Player)
			{
				//Game Over Condition true!
				uf.setUpdateFrequency(100.0f);
			}
		}
	}

	for (int y = 0; y < tileMap.getTileMapHeight(); ++y)
	{
		for (int x = 0; x < nColums; ++x)
		{
			tileMap.setTileTypeAtPos(TileMap::TileType::EnemieBack, Vec2(x, y));
		}
	}
}

void EnemyBack::setColums(int newColums)
{
	nColums = newColums;
}

int EnemyBack::getColums()
{
	return nColums;
}
