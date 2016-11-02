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
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
// Rendering and Updating Frames of Game Including Logo
// Renders Objects of SDL
// Calls UpdateText() for Rendering Text
// Game Updation for Every Frame
// Resizing

//                                 ----------------------------------MAIN GRAPHICS RENDERING CODE----------------------------------

void Render()
{
	int i;
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	SDL_RenderClear(Renderer);
	if(!gamestart && !endflag)
		SDL_RenderCopy(Renderer, LogoTexture, NULL, &Logo);
	else if(gamestart == 2)
		SDL_RenderCopy(Renderer, InsTexture, NULL, &Ins);
	else if(!endflag && gamestart == 1)
	{
		SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
		for(i = 0; i < 4; i++)
		{
			if(i == paddleflag)
			{
				SDL_SetRenderDrawColor(Renderer, 119, 136, 153, 255);
				SDL_RenderFillRect(Renderer, &paddle[i]);
				SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
			}
			else
				SDL_RenderFillRect(Renderer, &paddle[i]);
		}							
		SDL_SetRenderDrawColor(Renderer, 139, 69, 19, 255);
		SDL_RenderFillRects(Renderer, &brick[0], SIZE);
		SDL_RenderCopy(Renderer, Texture[0], NULL, &ball);
	}
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	UpdateText();
	SDL_RenderPresent(Renderer);
	if(endflag)
		SDL_Delay(3000);	
}
//                                 ----------------------------------MAIN GRAPHICS RENDERING CODE----------------------------------


// Updates Game Frame, Also Checks for Pause

void GameUpdate()
{
	if((gamestart == 1) && !pausegame)
	{
		MoveBall();
		MovePaddle();
	}
	Render();
}

// Resizes Window

void Resize()
{
	SDL_SetWindowFullscreen(Window, SDL_WINDOW_FULLSCREEN);
	SDL_GetWindowSize(Window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
	GAME_SCREEN_WIDTH = SCREEN_WIDTH;
	GAME_SCREEN_HEIGHT = 0.905 * SCREEN_HEIGHT;
}
	
