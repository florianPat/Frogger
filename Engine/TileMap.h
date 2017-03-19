#pragma once

#include "Graphics.h"

class TileMap
{
	static constexpr int tilesWidth = 75, tilesHeight = 50;
	static constexpr int width = (Graphics::ScreenWidth / tilesWidth) - 4;
	static constexpr int height = Graphics::ScreenHeight / tilesHeight / 2; //12x6

	enum class TileType { Blank, Player, EnemieFront, Coin, EnemieBack };
	Color blankColor = Colors::Black, playerColor = Colors::Blue, enemieFrontColor = Colors::Magenta,
		coinColor = Colors::Yellow, enemieBackColor = Colors::Red;
public:
	TileMap() = default;
	void setTileTypeAtPos(TileType tileType, Vec2& pos);
	TileType getTileTypeAtpos(Vec2& pos);
	void draw(Graphics& gfx);
	void update();
private:
	TileType tileMap[width*height] = { TileType::Blank };
	Color tileMapColors[width*height] = { Colors::Black };
};