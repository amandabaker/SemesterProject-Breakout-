#include "Paddle.h"
using namespace std;

Paddle::Paddle() {
	int height = 20;
	int width = 100;
	int xPos = SCREEN_WIDTH/2 - width/2;
	int yPos = 400  /*SCREEN_HEIGHT - SCREEN_HEIGHT/12*/;
	int xVel = 0;
	int velMult = 0;
}

int Paddle::left() {
	return xPos;
}

int Paddle::right() {
	return xPos + width;
}

int Paddle::top() {
	return yPos;
}

int Paddle::bottom() {
	return yPos + height;
}

void Paddle::set() {
	height = 20;
	width = 100;
	xPos = SCREEN_WIDTH/2 - width/2;
	//yPos = SCREEN_HEIGHT - SCREEN_HEIGHT/12;
	yPos = SCREEN_HEIGHT - 50;
	xVel = 0;
	speed = 15; //
}

void Paddle::movePaddle() {
	xPos += xVel*speed;

	if( xPos <= leftBoundry ) {
		xPos = leftBoundry;
	}
	else if(xPos >= ( rightBoundry - width ) ) {
		xPos = rightBoundry - width;
	}
}

void Paddle::setXVel(int newVel) {
	xVel = newVel;
}

int Paddle::getXVel(){
	return xVel;
}

void Paddle::render( SDL_Renderer* gRenderer ) {
	SDL_Rect fillRect = { xPos, yPos, width, height };
	SDL_SetRenderDrawColor( gRenderer, 0x50, 0x90, 0xFF, 0xFF );
	SDL_RenderFillRect( gRenderer, &fillRect );
}

void Paddle::render( SDL_Renderer* gRenderer, SDL_Texture* gTexture ) {
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	srcrect.x = 0;
	srcrect.y = 80;
	srcrect.w = 100;
	srcrect.h = 20;
	dstrect.x = xPos;
	dstrect.y = yPos;
	dstrect.w = width;
	dstrect.h = height;
	SDL_RenderCopy( gRenderer, gTexture, &srcrect, &dstrect );
}
