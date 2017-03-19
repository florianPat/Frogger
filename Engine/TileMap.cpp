#include "TileMap.h"
#include <assert.h>

void TileMap::setTileTypeAtPos(TileType tileType, Vec2 & pos)
{
	assert(pos.x > 0);
	assert(pos.x < width);
	assert(pos.y > 0);
	assert(pos.y < height);
	tileMap[pos.y * width + pos.x] = tileType;
}

TileMap::TileType TileMap::getTileTypeAtpos(Vec2 & pos)
{
	return tileMap[pos.y * width + pos.x];
}

void TileMap::draw(Graphics & gfx)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			gfx.DrawRect(x*tilesWidth, y*tilesHeight, x*tilesWidth + tilesWidth, y*tilesHeight + tilesHeight, tileMapColors[y*width + x]);
		}
	}
}

void TileMap::update()
{
	for (int i = 0; i < width*height; ++i)
	{
		switch (tileMap[i])
		{
		case TileType::Blank: tileMapColors[i] = blankColor; break;
		case TileType::EnemieBack: tileMapColors[i] = enemieBackColor; break;
		case TileType::EnemieFront: tileMapColors[i] = enemieFrontColor; break;
		case TileType::Coin: tileMapColors[i] = coinColor; break;
		case TileType::Player: tileMapColors[i] = playerColor; break;
		}
	}
}
