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

#include "define.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
// Updates Score
// Checks for Lives
// Resets Ball after Life Loss
// Resets Game
// Loss 
// Gets Highscore
// Level Up
// Ball Restart for Level Up
// Updates Score

void UpdateScore(int flag)
{
	if(!pausegame)
	{
		if(!flag)
			score = score + 100;
		if(flag)
			score = score - 250;
	}
}

// Checks for Any Loss Condition

void CheckLoss()
{
	if(count == 0)
		LevelUp();
	if(score <= 0 && lives != 0)
		Reset();
	if(lives == 0)
		End();
	if(reset == 1)
		GameReset();
}

//Resets after a Loss
void Reset()
{
	if(score <= 0)
		score = 300;
	lives--;
	ball.x = (GAME_SCREEN_WIDTH - ball.w)/2;
	ball.y = GAME_SCREEN_HEIGHT - 100;
	BallRestart();
}

//Level Up
void LevelUp()
{
	level++;
	if(level > 2)
		End();
	else
	{
		RectInit();
		BallRestart();
	}	
}

// Resets Game

void GameReset()
{
	RectInit();
	score = 300;
	lives = 3;
	gamestart = 0;
	pausegame = 0;
	paddleflag = 2;
	endflag = 0;
	reset = 0;
	level = 1;
}

//Gets Highscore from the Binary File

int HighScore(int flag)
{
	int fd;
	int hs = 99999;
	if(flag)
	{
		fd = open("highscore", O_RDONLY, S_IRUSR);
		read(fd, &hs , sizeof(int));
		close(fd);
		return hs; 
	}
	if(!flag)
	{
		if(highscore <= score)
		{
			fd = open("highscore", O_WRONLY | O_CREAT, S_IWUSR);
			write(fd, &score, sizeof(int));
		}
		close(fd);
		return 0;
	}
}

//  Ends Game 

void End()
{
	HighScore(0);
	endflag = 1;
	gamestart = 0;	
}

// Restarts Ball

void BallRestart()
{
	ball_vel_x = 0;
	ball_vel_y = BALLSPEED;
}
	
