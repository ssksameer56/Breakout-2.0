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
// Checks Collision of Two Rectngles
// Handles Ball and Paddle Collision
// Handles Paddles' collision
// Handles Bricks and Ball Collision
// Checks Boundary for Ball

//                                 ----------------------------------MAIN COLLISION CHECK CODE----------------------------------
int CheckCollision(SDL_Rect *rect1, SDL_Rect *rect2)
{
        int rect1_left  = (*rect1).x;
        int rect1_right = (*rect1).x + (*rect1).w;
        int rect1_up    = (*rect1).y;
        int rect1_down  = (*rect1).y + (*rect1).h;
        int rect2_left  = (*rect2).x;
        int rect2_right = (*rect2).x + (*rect2).w;
        int rect2_up    = (*rect2).y;
        int rect2_down  = (*rect2).y + (*rect2).h;
       	if( (rect1_down >= rect2_up) && (rect1_up <= rect2_up) && (rect1_right >= rect2_left) && (rect1_left <= rect2_right) )
		return 1;
	if( (rect1_left <= rect2_right) && (rect1_right >= rect2_right) && (rect1_down >= rect2_up) && (rect1_up <= rect2_down) )
		return 2;
	if( (rect1_up <= rect2_down) && (rect1_up >= rect2_up) && (rect1_right >= rect2_left) && (rect1_left <= rect2_right) )
		return 3;
	if( (rect1_right >= rect2_left) && (rect1_left <= rect2_left) && (rect1_down >= rect2_up) && (rect1_up <= rect2_down) )
		return 4;
	return 0;

}
//                                 ----------------------------------MAIN COLLISION CHECK CODE----------------------------------


// Handles Collision of Paddles and Ball And Adjusts Ball Accordingly

void HandleBallPaddleCollision(SDL_Rect* ball, SDL_Rect *paddle)
{
	double angle;
	int i = 0;
	int dist_x, dist_y;
	int ball_centre_x = (*ball).x + (*ball).w/2;
	int ball_centre_y = (*ball).y + (*ball).h/2;
	int flag;
	for( i = 0; i < 4; i++)
	{
	int rect_centre_x = (paddle[i]).x + (paddle[i]).w/2;
	int rect_centre_y = (paddle[i]).y + (paddle[i]).h/2;
	dist_x = ball_centre_x - rect_centre_x;
	dist_y = ball_centre_y - rect_centre_y;
	flag = CheckCollision(ball, &paddle[i]);
	switch(flag)
	{
		case 1: ball_vel_y = -(ball_vel_y);
			if	(ball_vel_x <= 0 && dist_x >= 0)
				ball_vel_x = abs((1 + dist_x/60))*BALLSPEED;
			else if(ball_vel_x >= 0 && dist_x <= 0)
				ball_vel_x = -abs((1 - dist_x/60))*BALLSPEED;
			else if(ball_vel_x >= 0 && dist_x > 0)
				ball_vel_x = abs((1 + dist_x/60))*BALLSPEED;
			else if(ball_vel_x <= 0 && dist_x < 0)
				ball_vel_x = -abs((1 - dist_x/60))*BALLSPEED;
			break;
		case 2: ball_vel_x = -(ball_vel_x);
			if	(ball_vel_y <= 0 && dist_y >= 0)
				ball_vel_y = abs((1 + dist_y/60))*BALLSPEED;
			else if(ball_vel_y >= 0 && dist_y <= 0)
				ball_vel_y = -abs((1 - dist_y/60))*BALLSPEED;
			else if(ball_vel_y >= 0 && dist_y > 0)
				ball_vel_y = abs((1 + dist_y/60))*BALLSPEED;
			else if(ball_vel_y <= 0 && dist_y < 0)
				ball_vel_y = -abs((1 - dist_y/60))*BALLSPEED;
			break;
		case 3: ball_vel_y = -(ball_vel_y);
			if	(ball_vel_x <= 0 && dist_x >= 0)
				ball_vel_x = abs((1 + dist_x/60))*BALLSPEED;
			else if(ball_vel_x >= 0 && dist_x <= 0)
				ball_vel_x = -abs((1 - dist_x/60))*BALLSPEED;
			else if(ball_vel_x >= 0 && dist_x > 0)
				ball_vel_x = abs((1 + dist_x/60))*BALLSPEED;
			else if(ball_vel_x <= 0 && dist_x < 0)
				ball_vel_x = -abs((1 - dist_x/60))*BALLSPEED;
			break;
		case 4: ball_vel_x = -(ball_vel_x);
			if	(ball_vel_y <= 0 && dist_y >= 0)
				ball_vel_y = abs((1 + dist_y/60))*BALLSPEED;
			else if(ball_vel_y >= 0 && dist_y <= 0)
				ball_vel_y = -abs((1 - dist_y/60))*BALLSPEED;
			else if(ball_vel_y >= 0 && dist_y > 0)
				ball_vel_y = abs((1 + dist_y/60))*BALLSPEED;
			else if(ball_vel_y <= 0 && dist_y < 0)
				ball_vel_y = -abs((1 - dist_y/60))*BALLSPEED;
			break;		
		default:break;
	}
	}
}

// Handles Brick and Ball Collision

void HandleBallBrickCollision(SDL_Rect *ball, SDL_Rect *brick)
{
	int dist_x, dist_y, i ,j, k = 0;
	int ball_centre_x = (*ball).x + (*ball).w/2;
	int ball_centre_y = (*ball).y + (*ball).h/2;
	int rect_centre_x;
	int rect_centre_y;
	int flag;
	for( i = 0; i < SIZE; i++)
	{
	int rect_x_centre = (brick[i]).x + (brick[i]).w/2;
	int rect_y_centre = (brick[i]).y + (brick[i]).h/2;
	dist_x = ball_centre_x - rect_centre_x;
	dist_y = ball_centre_y - rect_centre_y;
	flag = CheckCollision(ball, &brick[i]);
	if( flag > 0 )
	{
		(brick[i]).w = 0;
		(brick[i]).h = 0;
		(brick[i]).x = 0;
		(brick[i]).y = 0;
		UpdateScore(0);
		//SDL_Delay(5);
		count--;
	}
	switch(flag)
	{
		case 1: ball_vel_y = -abs(ball_vel_y);
			break;
		case 2: ball_vel_x = abs(ball_vel_x);
			break;
		case 3: ball_vel_y = abs(ball_vel_y);
			break;
		case 4: ball_vel_x = -abs(ball_vel_x);
			break;
		default:break;
	}
	}
}

	
//Checks Whether Ball Hits Boundary

int CheckBoundary(SDL_Rect *rect)
{
	int rect_left = (*rect).x;
	int rect_up   = (*rect).y;
	if(rect_left <= 0)
		return 1;
	if(rect_left >= GAME_SCREEN_WIDTH - (*rect).w)
		return 2;
	if(rect_up <= 0)
		return 3;
	if(rect_up >= GAME_SCREEN_HEIGHT - (*rect).h)
		return 4;
	
	return 0;
}

// Handle Paddle Collision

void HandlePaddleCollision()
{	
	int i;
	for(i = 0; i < 4; i++)
	{
		if(paddle[i].x <= 0)
			paddle[i].x = 0;
		if(paddle[i].x >= (GAME_SCREEN_WIDTH - paddle[i].w))
			paddle[i].x = GAME_SCREEN_WIDTH - paddle[i].w;
		if(paddle[i].y <= 0)
			paddle[i].y = 0;
		if(paddle[i].y >= (GAME_SCREEN_HEIGHT - paddle[i].h))
			paddle[i].y = GAME_SCREEN_HEIGHT - paddle[i].h;
	}
}

// Handles Ball collision with Boundary

void HandleBallCollision(SDL_Rect *ball)
{
	int flag = CheckBoundary(ball);
	if(flag == 1)
		ball_vel_x = ball_vel_x;
	if(flag == 2)
		ball_vel_x = -(ball_vel_x);
	if(flag == 3)
		ball_vel_y = ball_vel_y;
	if(flag == 4)
		ball_vel_y = -(ball_vel_y);
	if(flag)
		UpdateScore(1);
}
