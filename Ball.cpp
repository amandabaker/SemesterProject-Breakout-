#include "Ball.h"
using namespace std;

Ball::Ball() {
	int diameter;
	int xPos, yPos;
	int xVel, yVel;
	int speed;
}

void Ball::set() {
	diameter = 15;
	xPos = SCREEN_WIDTH / 2;
	yPos = SCREEN_HEIGHT - 50 - diameter;

	speed = 1; 
	xVel = speed;
	yVel = speed;  
	/*note that the ball will be traveling at a 45 degree angle as it is set above.
	  the intention here is to have numbers that don't require much calculation, so 
	  no need for any sass about speed not being the actual speed (the actual speed 
	  would be sqrt(xVel^2+yVel^2), but thats just lots of extra computation, so 
	  lets be lazy and not mathematical for now :)			                       */					
}

bool Ball::move() { //doesn't work yet
	xPos += xVel;
	yPos += yVel;

	if( xPos <= leftBoundry ) {
		xPos = leftBoundry;
		xVel *= -1;
	}
	else if( xPos >= rightBoundry - diameter ) {
		xPos = rightBoundry - diameter;
		xVel *= -1;
	}

	if( yPos <= topBoundry ) {
		yPos = topBoundry;
		yVel *= -1;
	}
	else if( yPos >= bottomBoundry - diameter ) {
		yPos = bottomBoundry - diameter;
		yVel *= -1;
		return false;
	}
	return true;
}

int Ball::left() {
	return xPos;
}

int Ball::right() {
	return xPos + diameter;
}

int Ball::top() {
	return yPos;
}

int Ball::bottom() {
	return yPos + diameter;
}
void Ball::changeYDir() {
	yVel *= -1;
}

void Ball::render( SDL_Renderer *gRenderer ) {
	SDL_Rect fillRect = { xPos, yPos, diameter, diameter };
	SDL_SetRenderDrawColor( gRenderer, 0x50, 0xFF, 0x90, 0xFF );
	SDL_RenderFillRect( gRenderer, &fillRect );
}

void Ball::render( SDL_Renderer *gRenderer, SDL_Texture *gTexture ) {
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 30;
	srcrect.h = 30;
	dstrect.x = xPos;
	dstrect.y = yPos;
	dstrect.w = diameter;
	dstrect.h = diameter;
	SDL_RenderCopy( gRenderer, gTexture, &srcrect, &dstrect );
}

void Ball::render( SDL_Renderer *gRenderer, SDL_Texture *gTexture ) {
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 30;
	srcrect.h = 30;
	dstrect.x = xPos;
	dstrect.y = yPos;
	dstrect.w = diameter;
	dstrect.h = diameter;
	SDL_RenderCopy( gRenderer, gTexture, &srcrect, &dstrect );
}
