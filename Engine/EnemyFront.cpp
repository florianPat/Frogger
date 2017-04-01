#include "EnemyFront.h"

EnemyFront::EnemyFront(Player& player, TileMap& tileMap, UpdateFrequency& uf, EnemyBack& enemyBack) : player(player), 
			tileMap(tileMap), uf(uf), pos(0, 0), rng(), dist(0, tileMap.getTileMapHeight()-1), enemyBack(enemyBack)
{
	reset();
}

void EnemyFront::update(float dt, float updateFrequency)
{
	static float dtElapsed = 0;
	tileMap.setTileTypeAtPos(TileMap::TileType::EnemieFront, pos);

	dtElapsed += dt;
	if (dtElapsed > updateFrequency)
	{
		dtElapsed = 0;
		pos.x -= 1;
		if (pos.x == -1 || (player.getPos().x == pos.x && player.getPos().y == pos.y))
		{
			if (pos.x != -1)
			{
				uf.setUpdateFrequency(uf.getUpdateFrequency() * updateFrequencyMultiply);
				enemyBack.setColums(enemyBack.getColums() + 1);
			}
			reset();
		}
	}
}

void EnemyFront::reset()
{
	do
	{
		pos.x = tileMap.getTileMapWith() - 1;
		pos.y = dist(rng);
	} while (tileMap.getTileTypeAtpos(pos) != TileMap::TileType::Blank);
	tileMap.setTileTypeAtPos(TileMap::TileType::EnemieFront, pos);
}
