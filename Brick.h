<<<<<<< Updated upstream
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
    
};

#endif
=======
class Brick{
	int xPos;
	int yPos;
	const int  widthBrick;
	const int  heightBrick;

public:
	void setX_Brick(int X1);
	void setY_Brick(int Y1);
	void setWidth(int W);
	void setHeight(int H);


    int getX_Brick();
	int getY_Brick();
	int getWidth_Brick();
	int getHeight_Brick();

	
};
>>>>>>> Stashed changes
