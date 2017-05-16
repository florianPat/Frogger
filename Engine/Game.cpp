/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Vec2.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	frameTimer(),
	cars(),
	lake(paddingBeforeLake, gfx),
	win(),
	player(wnd.kbd, gfx, { gfx.ScreenWidth / 2.0f, gfx.ScreenHeight - 48.0f /*player width*/ }, cars, lake, win),
	rng(), distWaitTime(100, 130), distCarSpeed(100, 150)
{
	for (int i = 0; i < numCars; ++i)
	{
		cars.push_back(Car(paddingAfterLake + paddingBeforeLake + lakeHeight + i * paddingBetweenCars, gfx, distCarSpeed(rng)));
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = frameTimer.Mark();
	
	if (!isWin)
	{
		player.update(dt, &isWin);

		if (delay == numCars)
		{
			for (auto it = cars.begin(); it != cars.end(); ++it)
			{
				it->update(dt);
			}
		}
		else
		{
			auto it = cars.begin();
			for (int z = 0; z < delay; z++, it++)
			{
				it->update(dt);
			}
		}

		lake.update(dt);
	}
}

void Game::ComposeFrame()
{
	if (isWin)
	{
		SpriteCodex::DrawWin(gfx.ScreenWidth / 2, gfx.ScreenHeight / 2, gfx);
		return;
	}

	if (delay == numCars)
	{
		for (auto it = cars.begin(); it != cars.end(); ++it)
		{
			it->draw();
		}
	}
	else
	{
		if (waitTime == 0)
		{
			delay++;
			waitTime = distWaitTime(rng);
		}
		else
		{
			auto it = cars.begin();
			for (int z = 0; z < delay; z++, it++)
			{
				it->draw();
			}
			waitTime--;
		}
	}

	lake.draw();

	player.draw();
}
