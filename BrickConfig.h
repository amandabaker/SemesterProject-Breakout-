#ifndef _BRICKCONFIG_H_INCLUDED_
#define _BRICKCONFIG_H_INCLUDED_

class Breakout;
class Brick;
class Paddle;
class Ball;

#include <vector>
#include "Breakout.h"
#include "Brick.h"
#include "Paddle.h"
#include "Ball.h"

class BrickConfig {

	int numCol;
	int numRow;
	int numBricks;
	int numBricksLeft;
	int brickWidth;
	int brickHeight;
	int spaceBtwn;
	int spaceEdge;
	int xPos;
	int yPos;
	std::vector<Brick> brickVect;

public:

	BrickConfig(); 
	int size();
	int left( int brickNum );
	int right( int brickNum );
	int top( int brickNum );
	int bottom( int brickNum );
	void set();
	void destroy( int brickNum );
	void render( SDL_Renderer* );
	void render( SDL_Renderer*, SDL_Texture* );
};


#endif
