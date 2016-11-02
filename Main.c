/*			Copyright 2016 Sameer Kolpekwar
	This file is part of Breakout 2.0.
	Breakout 2.0 is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Breakout 2.0 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Breakout 2.0.  If not, see <http://www.gnu.org/licenses/>. */

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "define.h"

// Main Loop

int main()
{
	highscore = HighScore(1);
	DisplayInit();
	RectInit();
	InitText();
	while(!quitflag)
	{	
		Game();
		SDL_Delay(16); // To get 60 Frames per Second
	}
	Quit();
	return 0;
}

// Game Loop

void Game()
{
	HandleInput();
	HandleBallPaddleCollision(&ball, &paddle[0]);
	HandleBallBrickCollision(&ball, &brick[0]);
	HandlePaddleCollision();
	HandleBallCollision(&ball);
	CheckLoss();
	GameUpdate();
	CheckLoss();
}
	
