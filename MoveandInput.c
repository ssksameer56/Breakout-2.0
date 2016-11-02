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
// Handles User Input
// Move Ball
// Move Paddle

// Handles Game Input

void HandleInput()
{
	if(SDL_PollEvent(&e) != 0)
	{
		if(e.type == SDL_QUIT)
		{
			quitflag = 1;
		}
		if(e.type == SDL_KEYDOWN)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_q 	: if(!gamestart)
							quitflag = 1;
						  if(gamestart)
							endflag = 1;
						  break;
				case SDLK_SPACE : if(gamestart)
							pausegame = (pausegame + 1) % 2;
						  break;
				case SDLK_RETURN: if(!gamestart)
						  {
						  	gamestart = 1;
						  	SDL_Delay(500);
						  }
						  break;
				case SDLK_w     : if(!pausegame) 
							paddleflag = 0;
						  break;
				case SDLK_d     : if(!pausegame) 
							paddleflag = 1;
						  break;
				case SDLK_s     : if(!pausegame) 
							paddleflag = 2;
						  break;
				case SDLK_a     : if(!pausegame) 
							paddleflag = 3;
						  break;
				case SDLK_r	: reset = 1;
						  break;
				case SDLK_i	: if(gamestart == 0)
						  	gamestart = 2;
						  break;
				case SDLK_UP    : move_y = 1;
						  break;
				case SDLK_DOWN  : move_y = 2;
						  break;
				case SDLK_LEFT  : move_x = 1;
						  break;
				case SDLK_RIGHT : move_x = 2;
						  break;
				case SDLK_ESCAPE: if(gamestart)
							gamestart = 0;
						  break;
			}
		}
		if(e.type == SDL_KEYUP)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_UP    : move_y = 0;
						  break;
				case SDLK_DOWN  : move_y = 0;
						  break;
				case SDLK_LEFT  : move_x = 0;
						  break;
				case SDLK_RIGHT : move_x = 0;
						  break;
			}
		}
		if(e.type == SDL_WINDOWEVENT)
		{
			if(e.type == SDL_WINDOW_MAXIMIZED)
			Resize();
		}
	}
}

// Moves Paddles

void MovePaddle()
{
	if(!pausegame)
	{
		switch(paddleflag)
		{
			case 0 : if(move_x == 1)
				 	paddle[0].x = paddle[0].x - paddle_vel/60;
				 if(move_x == 2)
				 	paddle[0].x = paddle[0].x + paddle_vel/60;
				 break;
			case 1 : if(move_y == 1)
				 	paddle[1].y = paddle[1].y - paddle_vel/60;
				 if(move_y == 2)
				 	paddle[1].y = paddle[1].y + paddle_vel/60;
				 break;		
			case 2 : if(move_x == 1)
					 paddle[2].x = paddle[2].x - paddle_vel/60;
				 if(move_x == 2)
					 paddle[2].x = paddle[2].x + paddle_vel/60;
				 break;
			case 3 : if(move_y == 1)
				 	paddle[3].y = paddle[3].y - paddle_vel/60;
				 if(move_y == 2)
				 	paddle[3].y = paddle[3].y + paddle_vel/60;
				 break;
			
		}		
	
	}
}

// Moves Ball

void MoveBall()
{
	if(!pausegame)
	{
		ball.x = ball.x + ball_vel_x/60;
		ball.y = ball.y + ball_vel_y/60;
	}
}

