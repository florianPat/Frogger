#include "Player.h"

Player::Player(TileMap& tileMap, Keyboard& keyboard) : tileMap(tileMap), kbd(keyboard), 
													   pos(tileMap.getTileMapWith() / 2, tileMap.getTileMapHeight() / 2)
{
}

void Player::update(float dt)
{
	static bool pressed = false;
	static float dtElapsed = 0;

	if (!pressed)
	{
		if (kbd.KeyIsPressed(VK_DOWN) && pos.y < tileMapHeight - 1)
		{
			pos.y += 1;
		}
		if (kbd.KeyIsPressed(VK_UP) && pos.y > 0)
		{
			pos.y -= 1;
		}
		if (kbd.KeyIsPressed(VK_LEFT) && pos.x > 0)
		{
			pos.x -= 1;
		}
		if (kbd.KeyIsPressed(VK_RIGHT) && pos.x < tileMapWidth - 1)
		{
			pos.x += 1;
		}
	}

	tileMap.setTileTypeAtPos(TileMap::TileType::Player, pos);
	dtElapsed += dt;;
	if (dtElapsed > 1.0f)
	{
		dtElapsed = 0;
		pressed = false;
	}
}
