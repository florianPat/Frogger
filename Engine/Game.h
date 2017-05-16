/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Player.h"
#include "Car.h"
#include <vector>
#include "Lake.h"
#include "Win.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer frameTimer;

	Player player;

	std::mt19937 rng;
	std::uniform_int_distribution<int> distCarSpeed;
	static constexpr int numCars = 5;
	std::vector<Car> cars;

	static constexpr float paddingBeforeLake = 32.0f;
	float lakeHeight = gfx.ScreenHeight / 3.0f;
	static constexpr int paddingAfterLake = 10;
	static constexpr float paddingBetweenCars = 70.0f;
	Lake lake;

	std::uniform_int_distribution<int> distWaitTime;
	int waitTime = 0;
	int delay = 0;

	Win win;
	bool isWin = false;
	/********************************/
};