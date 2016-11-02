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

// Closes SDL, TTF Elements, Surfaces and Textures
void Quit()
{
	highscore = HighScore(1);
	if(highscore <= score)
		HighScore(0);
	int i;
	for( i = 0; i < 9; i++)
		SDL_DestroyTexture(Texture[i]);
	SDL_DestroyTexture(LogoTexture);
	SDL_DestroyTexture(InsTexture);
	TTF_CloseFont(atari1);
	TTF_CloseFont(atari2);
	TTF_CloseFont(atari3);
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	TTF_Quit();
	SDL_Quit();
}
