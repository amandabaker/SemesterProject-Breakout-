#ifndef _SCOREBOARD_H_INCLUDED_
#define _SCOREBOARD_H_INCLUDED_

class Breakout;
class Paddle;
class BrickConfig;
class Brick;
class LTexture;

#include "Breakout.h"
#include "Paddle.h"
#include "BrickConfig.h"
#include "Brick.h"
#include "Ball.h"
#include "MainMenu.h"

class Scoreboard {
	int score;
	int xPos;
	int yPos;
	int width;
	int height;
	SDL_Color textColor;

public:
	Scoreboard();
	void set();
	void setScore( int newScore );
	void addScore( int points );
	void render( SDL_Renderer*, TTF_Font*, LTexture );

};


#endif