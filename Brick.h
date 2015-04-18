#ifndef _BRICK_H_INCLUDED_
#define _BRICK_H_INCLUDED_

class Breakout;
class Paddle;
class BrickConfig;
class Ball;

#include "Breakout.h"
#include "Paddle.h"
#include "BrickConfig.h"
#include "Ball.h"
#include "Scoreboard.h"

class Brick
{
	int xPos;
	int yPos;
	int width;
	int height;
	bool exists;
	SDL_Rect srcrect;
  	SDL_Rect dstrect;

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
