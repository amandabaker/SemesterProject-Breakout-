#ifndef _BREAKOUT_H_INCLUDED_
#define _BREAKOUT_H_INCLUDED_

class Paddle;
class Brick;
class BrickConfig;
class Ball;

#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "Paddle.h"
#include "Brick.h"
#include "BrickConfig.h"
#include "Ball.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int scoreboardHeight = 50;
const int leftBoundry   = 0;
const int rightBoundry  = SCREEN_WIDTH;
const int topBoundry	= scoreboardHeight;
const int bottomBoundry = SCREEN_HEIGHT;

enum KeyPressSurfaces 
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_SPACEBAR,
	KEY_PRESS_SURFACE_TOTAL /*used to count number of all keys used for array size*/
};

#endif