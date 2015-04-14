#ifndef _BRICK_H_INCLUDED_
#define _BRICK_H_INCLUDED_

class Breakout;
class Paddle;
class BrickConfig;
class Ball;

#include <SDL.h>
#include <stdio.h>
#include "Breakout.h"
#include "Paddle.h"
#include "BrickConfig.h"
#include "Ball.h"

class Brick
{
	int xPos;
	int yPos;
	int width;
	int height;
	bool exists;
  
public:
  
	Brick();
	Brick( int x, int y, int width, int height );
	int left();
	int right();
	int top();
	int bottom();
	void set( int x, int y, int width, int height );
	void destroy();
	void render( SDL_Renderer* );
	void render( SDL_Renderer*, SDL_Texture* );
    
};

#endif