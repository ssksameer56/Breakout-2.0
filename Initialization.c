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
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "define.h"

// Initialization of SDL Elements
// Initializing Ball
// Initializing Paddle
// Initializing Bricks
// Initializing Text Surface and Texture
// Game Reset
	int score      = 300;
	int lives      = 3;
	int pausegame  = 0;
	int endflag    = 0;
	int quitflag   = 0;
	int level      = 1;
	int ball_vel_x = BALLSPEED;
	int ball_vel_y = BALLSPEED;
	int paddle_vel = 800;
	int factor     = 1;
	int paddleflag = 2;
	int reset      = 0;
	int SCREEN_WIDTH	= 1366;
	int SCREEN_HEIGHT	= 708;
	int GAME_SCREEN_WIDTH 	= 1366;
	int GAME_SCREEN_HEIGHT 	= 641;
	int FONT_1		= 16;
	int FONT_2		= 18;
	int FONT_3		= 22;
	int FONT_4		= 24;

void DisplayInit()
{
// Initializing SDL Elements

	SDL_Init(SDL_INIT_VIDEO);
	Window = SDL_CreateWindow("Breakout 2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	Renderer = SDL_CreateRenderer(Window, -1 , SDL_RENDERER_ACCELERATED);
	BallSurface = IMG_Load("ball.png");
	LogoSurface = IMG_Load("logo.jpg");
	InsSurface  = IMG_Load("instructions.jpg");
	LogoTexture = SDL_CreateTextureFromSurface(Renderer, LogoSurface);
        Texture[0] = SDL_CreateTextureFromSurface(Renderer, BallSurface);
	InsTexture = SDL_CreateTextureFromSurface(Renderer, InsSurface);
	SDL_FreeSurface(BallSurface);
	SDL_FreeSurface(LogoSurface);
	SDL_FreeSurface(InsSurface);
	SDL_QueryTexture(LogoTexture, NULL, NULL, &Logo.w, &Logo.h);
	SDL_QueryTexture(InsTexture, NULL, NULL, &Ins.w, &Ins.h);
	Logo.x = (SCREEN_WIDTH - Logo.w)/2;
	Logo.y = (SCREEN_HEIGHT - Logo.h)/2;
	Ins.w = Ins.w * 0.8;
	Ins.h = Ins.h * 0.8;
	Ins.x = (SCREEN_WIDTH - Ins.w)/2;
	Ins.y = (SCREEN_HEIGHT - Ins.h)/2;
	red.r = 255;
	red.g = 0;
	red.b = 0;
	white.r = 255;
	white.g = 255;
	white.b = 255;
	black.r = 0;
	black.g = 0;
	black.b = 0;
	brown.r = 102;
	brown.g = 51;
	brown.b = 0;
	grey.r = 119;
	grey.g = 136;
	grey.b = 153;
}

void RectInit()
{
// Initializing Ball
	int i,j, k;
	ball.x = (GAME_SCREEN_WIDTH - ball.w)/2;
	ball.y = GAME_SCREEN_HEIGHT - 100;
	ball.w = 30;
	ball.h = 30;
	BallRestart();
	k = 0;
//Initializing Paddles 

	for(i = 0; i < 4; i++)
	{
		if(i%2 == 0)
		{
			paddle[i].w = 200;
			paddle[i].h = 20;
			paddle[i].x = (GAME_SCREEN_WIDTH- paddle[i].w)/2;
		}
		if(i%2 == 1)
		{
			paddle[i].w = 20;
			paddle[i].h = 200;
			paddle[i].y = (GAME_SCREEN_HEIGHT - paddle[i].h)/2;
		}
		paddle[0].y = 0;
		paddle[1].x = GAME_SCREEN_WIDTH - paddle[1].w;
		paddle[2].y = GAME_SCREEN_HEIGHT - paddle[2].h;
		paddle[3].x = 0;
	}
	
//Initializing Bricks
	if(level == 1)	
		count = SIZE;
	if(level == 2)
		count = SIZE/2;
	for(i = 0; i < 10; i++)
	{
		for( j = 0; j <14; j++)
		{
			if(level == 1)
			{
				brick[k].w = 50;
				brick[k].h = 25;	
				brick[k].x = (GAME_SCREEN_WIDTH - 14*brick[k].w)/2 + j*brick[k].w;
				brick[k].y = (GAME_SCREEN_HEIGHT - 10*brick[k].h)/2 + i*brick[k].h;
				k++;
			}
			if(level == 2)
			{
				if( (i+j)%2 == 0)
				{
					brick[k].w = 50;
					brick[k].h = 25;	
					brick[k].x = (GAME_SCREEN_WIDTH - 14*brick[k].w)/2 + j*brick[k].w;
					brick[k].y = (GAME_SCREEN_HEIGHT - 10*brick[k].h)/2 + i*brick[k].h;
				}
				else
					brick[k].w = brick[k].x = brick[k].h = brick[k].y = 0;
			k++;
			}
		}
	}
}

// Initializing Fonts and TTF Elements

void InitText()
{
		TTF_Init();
		atari1 = TTF_OpenFont("atari.TTF", FONT_1);
		atari2 = TTF_OpenFont("atari.TTF", FONT_2);
		atari3 = TTF_OpenFont("atari.TTF", FONT_3);
		atari4 = TTF_OpenFont("atari.TTF", FONT_4);
}


