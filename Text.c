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

#include <string.h>
#include "define.h"

// Handles All Text Elements (Score, Lives)

void UpdateText()
{
	char temp1[20], temp2[20], temp3[20], temp4[20];
	int i;
	sprintf(temp1, "LIVES %d", lives);
	sprintf(temp2, "SCORE %d", score);
	sprintf(temp3, "HIGHSCORE %d", highscore);
	sprintf(temp4, "Your Score was %d", score);
	TextSurface[0] = TTF_RenderText_Solid(atari1, temp1, white);
	TextSurface[1] = TTF_RenderText_Solid(atari1, temp2, white);
	TextSurface[2] = TTF_RenderText_Solid(atari2, temp3, red);
	TextSurface[3] = TTF_RenderText_Solid(atari2, "(Q)uit   (R) Reset   (SPACE) Pause   (I) Instructions   (ESC) Go Back", white);
	TextSurface[4] = TTF_RenderText_Solid(atari3, "Press ENTER To Start", white);
	TextSurface[5] = TTF_RenderText_Solid(atari1, "PAUSED!", white);
	TextSurface[6] = TTF_RenderText_Solid(atari3, "Inspired by the 1976 Atari Breakout", white);
	TextSurface[7] = TTF_RenderText_Solid(atari4, temp4, white);
	for(i = 0; i < 8; i++)
	{
		Texture[i+1] = SDL_CreateTextureFromSurface(Renderer, TextSurface[i]);
		SDL_FreeSurface(TextSurface[i]);
		SDL_QueryTexture(Texture[i+1], NULL, NULL, &Text[i].w, &Text[i].h);
	}
	Text[3].x = (SCREEN_WIDTH - Text[3].w)/2;
	Text[3].y = SCREEN_HEIGHT - Text[3].h;
	Text[1].x = 0;
	Text[1].y = Text[3].y - 5 - Text[1].h;
	Text[0].x = SCREEN_WIDTH - Text[0].w;
	Text[0].y = Text[1].y;
	Text[2].x = (SCREEN_WIDTH - Text[2].w)/2;
	Text[2].y = Text[1].y;
	Text[4].y = Text[3].y - 5 - Text[4].h;
	Text[4].x = (SCREEN_WIDTH - Text[4].w)/2;
	Text[5].x = (SCREEN_WIDTH - Text[5].w)/2;
	Text[5].y = Text[1].y;
	Text[6].x = (SCREEN_WIDTH - Text[6].w)/2;
	Text[6].y = Logo.y + Logo.h + 10;
	Text[7].x = (SCREEN_WIDTH - Text[7].w)/2;
	Text[7].y = (SCREEN_HEIGHT - Text[7].h)/2;
	if(!gamestart && !endflag)
	{
		SDL_RenderCopy(Renderer, Texture[5], NULL, &Text[4]);
		SDL_RenderCopy(Renderer, Texture[4], NULL, &Text[3]);	
		SDL_RenderCopy(Renderer, Texture[7], NULL, &Text[6]);
	}
	else if((gamestart == 1) && !endflag)
	{
		if(pausegame)
			SDL_RenderCopy(Renderer, Texture[6], NULL, &Text[5]);
		else
			SDL_RenderCopy(Renderer, Texture[3], NULL, &Text[2]);
		SDL_RenderCopy(Renderer, Texture[1], NULL, &Text[0]);
		SDL_RenderCopy(Renderer, Texture[2], NULL, &Text[1]);		
		SDL_RenderCopy(Renderer, Texture[4], NULL, &Text[3]);
	}
	else if(gamestart == 2 && !endflag)
	{
		SDL_RenderCopy(Renderer, Texture[4], NULL, &Text[3]);

	}
	if(endflag)
	{
		SDL_RenderCopy(Renderer, Texture[8], NULL, &Text[7]);
		if(lives != 0)
			quitflag = 1;
		else if(lives == 0)
			reset = 1;
	}
	for(i = 0; i < 8; i++)
	{ 
		SDL_DestroyTexture(Texture[i+1]);
	}
}


