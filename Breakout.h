#ifndef _BREAKOUT_H_INCLUDED_
#define _BREAKOUT_H_INCLUDED_

class Paddle;
class Brick;
class BrickConfig;
class Ball;
class Scoreboard;
class MainMenu;

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#elif __linux
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <sstream>
#include "Paddle.h"
#include "Brick.h"
#include "BrickConfig.h"
#include "Ball.h"
#include "Scoreboard.h"
#include "MainMenu.h"

const int SCREEN_WIDTH			 = 640;
const int SCREEN_HEIGHT			 = 480;
const int SCREEN_FPS			 = 120;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
const int scoreboardHeight		 = 50;
const int leftBoundry			 = 0;
const int rightBoundry			 = SCREEN_WIDTH;
const int topBoundry			 = scoreboardHeight;
const int bottomBoundry			 = SCREEN_HEIGHT;

enum KeyPressSurfaces 
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_SPACEBAR,
	KEY_PRESS_SURFACE_TOTAL /*used to count number of all keys used for array size*/
};

enum menuType
{
	NO_MENU,
	MAIN_MENU,
	GAME_OVER,
	PAUSE_GAME,
	WINNER
};

class LTexture {
  
  public:
    LTexture();
    ~LTexture();
    bool loadFromFile( std::string path, SDL_Renderer* gRenderer );
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
    void free();
    void setColor( Uint8 red, Uint8 green, Uint8 blue  );
    void setBlendMode( SDL_BlendMode blending );
    void setAlpha( Uint8 alpha );
    void render( int x, int y, SDL_Renderer* gRenderer );
	int getWidth();
    int getHeight();

  private:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
};

#endif
