<<<<<<< Updated upstream
#ifndef _BALL_H_INCLUDED_
#define _BALL_H_INCLUDED_

class Breakout;
class Paddle;
class BrickConfig;
class Brick;

#include <stdio.h>
#include <cmath>
#include "Breakout.h"
#include "Paddle.h"
#include "BrickConfig.h"
#include "Brick.h"

class Ball
{
	int radius;
	int xPos;
	int yPos;
	int xVel;
	int yVel;
	int speed;

public:

	Ball ();
	void set();
	void move();
	int left();
	int right();
	int top();
	int bottom();
	void changeYDir();
	void render( SDL_Renderer* );
    
};

#endif
=======
class Ball{
	int xPos;
	int yPos;
	int speedX;
	int speedY;
	const int  widthBall;
	const int  heightBall;

public:
	getX_Ball();
	getY_Ball();
	getBallSpeed_X();
	getBallSpeed_Y();
	getWidth_Ball();
	getHeight_Ball();

};

>>>>>>> Stashed changes
