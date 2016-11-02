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
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#define SIZE		   140
#define BALLSPEED	   200

// Variables
	int highscore, score, lives, pausegame, quitflag, gamestart, move, reset, count, endflag, level;
	int GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, FONT_1, FONT_2, FONT_3, FONT_4;
	int ball_vel_x, ball_vel_y;
	int paddle_vel;
	int paddleflag, move_y, move_x;
	int factor;
	
//SDL Structures and Objects
	SDL_Rect ball;
	SDL_Rect brick[140];
	SDL_Rect paddle[4];
	SDL_Rect Text[8];
	SDL_Rect Logo;
	SDL_Rect Ins;

//SDL Components

	SDL_Window *Window;
	SDL_Renderer *Renderer;
	SDL_Texture *Texture[9], *LogoTexture, *InsTexture;
	SDL_Surface *BallSurface, *TextSurface[8], *LogoSurface, *InsSurface;
	SDL_Event e;
	SDL_Color red, white, black, brown, grey;

//TTF Components and Fonts
	TTF_Font *atari1;
	TTF_Font *atari2;
	TTF_Font *atari3;
	TTF_Font *atari4;

// Funtion Declarations
void GameReset();
void DisplayInit();
void RectInit();
void InitText();
void Quit();
void Game();
int  CheckCollision(SDL_Rect*, SDL_Rect*);
void HandleBallPaddleCollision(SDL_Rect*, SDL_Rect*);
void MoveBall();
void MovePaddle();
void HandleInput();
void UpdateScore(int);
void UpdateText();
int  CheckBoundary(SDL_Rect*);
void HandleBallBrickCollision(SDL_Rect*, SDL_Rect*);
void Render();
void Reset();
void CheckLoss();
void LevelUp();
void HandlePaddleCollision();
void GameUpdate();
void Free();
int  HighScore();
void End();
void Resize();
void HandleBallCollision(SDL_Rect*);
void BallRestart();
