#ifndef _PADDLE_H_INCLUDED_
#define _PADDLE_H_INCLUDED_

class Breakout;
class Brick;
class BrickConfig;
class Ball;
class Scoreboard;
class MainMenu;

#include "Breakout.h"
#include "Brick.h"
#include "BrickConfig.h"
#include "Ball.h"
#include "Scoreboard.h"

class Paddle
{
	int xPos;
	int yPos;
	int xVel;
	int width;
	int height;
	int speed;

public:

	Paddle();
	int left();
	int right();
	int top();
	int bottom();
	void set();
	void movePaddle();
	void setXVel( int newVel );
	int  getXVel();
	void render( SDL_Renderer* );
	void render( SDL_Renderer*, SDL_Texture* );


};

#endif
