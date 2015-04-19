#ifndef _MAINMENU_H_INCLUDED_
#define _MAINMENU_H_INCLUDED_

class Breakout;
class Brick;
class BrickConfig;
class Ball;
class Paddle;

#include "Breakout.h"
#include "Brick.h"
#include "BrickConfig.h"
#include "Ball.h"
#include "Scoreboard.h"
#include "Paddle.h"

class MainMenu 
{
	SDL_Color textColor;

public:
	MainMenu();
	void set();
	void render( SDL_Renderer*, TTF_Font*, LTexture, int );
	void renderMainMenu( SDL_Renderer*, TTF_Font*, LTexture );
	void renderGameOver( SDL_Renderer*, TTF_Font*, LTexture );
	void renderPause(SDL_Renderer*, TTF_Font*, LTexture );
};

#endif