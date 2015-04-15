<<<<<<< Updated upstream
#ifndef _PADDLE_H_INCLUDED_
#define _PADDLE_H_INCLUDED_

class Breakout;
class Brick;
class BrickConfig;
class Ball;

#include <SDL.h>
#include <stdio.h>
#include <string>
#include "Breakout.h"
#include "Brick.h"
#include "BrickConfig.h"
#include "Ball.h"

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
	//int getXVel();
	void render( SDL_Renderer* );

};

#endif
=======
class Paddle
{
	double xPos;
	const double  yPos;
	int speed;
	const int width;
	const int  height;

	SDL_Texture * padIMG;
	SDL_Render * padREND;


    public:

    Paddle(SDL_Renderer * padREND, double speed, double startX);
	void setX(double Xp);
	void setSpeed(double spd);
	void setHeight(int Hp);
	void setWidth(int Wp);


	void movePaddle();

	double getX();
	double getSpeed();
	int getHeight();
	int getWidth();

};
>>>>>>> Stashed changes





