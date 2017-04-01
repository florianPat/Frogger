#include "Player.h"

Player::Player(TileMap& tileMap, Keyboard& keyboard) : tileMap(tileMap), kbd(keyboard), 
													   pos(tileMap.getTileMapWith() / 2, tileMap.getTileMapHeight() / 2)
{
}

void Player::update(float dt)
{
	static Vec2 deltaPos(0, 0);
	static bool pressed = false;
	static float dtElapsed = 0;

	if (kbd.KeyIsPressed(VK_DOWN) && pos.y < tileMapHeight - 1)
	{
		deltaPos.y = 1;
		deltaPos.x = 0;
		pressed = true;
	}
	if (kbd.KeyIsPressed(VK_UP) && pos.y > 0)
	{
		deltaPos.y = -1;
		deltaPos.x = 0;
		pressed = true;
	}
	if (kbd.KeyIsPressed(VK_LEFT) && pos.x > 0)
	{
		deltaPos.x = -1;
		deltaPos.y = 0;
		pressed = true;
	}
	if (kbd.KeyIsPressed(VK_RIGHT) && pos.x < tileMapWidth - 1)
	{
		deltaPos.x = 1;
		deltaPos.y = 0;
		pressed = true;
	}


	tileMap.setTileTypeAtPos(TileMap::TileType::Player, pos);

	dtElapsed += dt;
	if (dtElapsed > 1.0f)
	{
		pos += deltaPos;

		dtElapsed = 0;
		pressed = false;

		deltaPos.x = 0;
		deltaPos.y = 0;
	}
}

Vec2& Player::getPos()
{
	return pos;
}
