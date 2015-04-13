#include "Ball.h"
using namespace std;

Ball::Ball() {
	int radius;
	int xPos, yPos;
	int xVel, yVel;
	int speed;
}

void Ball::set() {
	radius = 10;
	xPos = SCREEN_WIDTH / 2;
	yPos = 11 * SCREEN_HEIGHT / 12 - radius;

	speed = 1; 
	xVel = speed;
	yVel = speed;  
	/*note that the ball will be traveling at a 45 degree angle as it is set above.
	  the intention here is to have numbers that don't require much calculation, so 
	  no need for any sass about speed not being the actual speed (the actual speed 
	  would be sqrt(xVel^2+yVel^2), but thats just lots of extra computation, so 
	  lets be lazy and not mathematical for now :)			                       */					
}

void Ball::move() { //doesn't work yet
	xPos += xVel;
	yPos += yVel;

	if( xPos <= leftBoundry ) {
		xPos = leftBoundry;
		xVel *= -1;
	}
	else if( xPos >= rightBoundry - radius ) {
		xPos = rightBoundry - radius;
		xVel *= -1;
	}

	if( yPos <= topBoundry ) {
		yPos = topBoundry;
		yVel *= -1;
	}
	else if( yPos >= bottomBoundry - radius ) {
		yPos = bottomBoundry - radius;
		yVel *= -1;
	}
}

int Ball::left() {
	return xPos - radius;
}

int Ball::right() {
	return xPos + radius;
}

int Ball::top() {
	return yPos - radius;
}

int Ball::bottom() {
	return yPos + radius;
}
void Ball::changeYDir() {
	yVel *= -1;
}
/*void Ball::render( SDL_Renderer *gRenderer ) {
	SDL_Point ball[21] = {
							xPos-1, yPos-2,		xPos, yPos-2,	xPos+1, yPos-2,
		xPos-2, yPos-1,		xPos-1, yPos-1,		xPos, yPos-1,	xPos+1, yPos-1,		xPos+2, yPos-1,
		xPos-2, yPos,		xPos-1, yPos,		xPos, yPos,		xPos+1, yPos,		xPos+2, yPos,
		xPos-2, yPos+1,		xPos-1, yPos+1,		xPos, yPos+1,	xPos+1, yPos+1,		xPos+2, yPos+1,
							xPos-1, yPos+2,		xPos, yPos+2,	xPos+1, yPos+2				};
	  so SDL does not come with a simple circle generator, so that will make
	    something that looks somewhat like a circle							       
	SDL_SetRenderDrawColor( gRenderer, 0x50, 0xFF, 0x90, 0xFF );
	SDL_RenderDrawPoints( gRenderer, ball, 21 );
}*/

/*
void Ball::render( SDL_Renderer *gRenderer ) {
	SDL_Point drawBall[ 1600 ] = { 0 };
	int i = 0;
	double error = ( double )radius;
	double x = ( double )radius - 0.5;
	double y = ( double )0.5;
	double cx = ( double )xPos - 0.5;
	double cy = ( double )yPos - 0.5;
	while( x >= y ) {
		drawBall[ i++ ] = SDL_Point( (int)(xPos + x), (int)( yPos + y) );
		//drawBall[ i++ ] = (int)( xPos + x );		drawBall[ i++ ] = (int)( yPos + y );
		//drawBall[ i++ ] = (int)( xPos - x );		drawBall[ i++ ] = (int)( yPos + y );
		//drawBall[ i++ ] = (int)( xPos - x );		drawBall[ i++ ] = (int)( yPos - y );
		//drawBall[ i++ ]	= (int)( xPos + x );		drawBall[ i++ ] = (int)( yPos - y );

		error += y;
		y++;
		error += y;

		if( error >= 0 ) {
			--x; 
			error -= x;
			error -= x;
		}
	}
	SDL_SetRenderDrawColor( gRenderer, 0x50, 0xFF, 0x90, 0xFF );
	SDL_RenderDrawPoints( gRenderer, drawBall, 21 );
}
*/

/*JUST KIDDING WE'RE GOING TO USE A SQUARE!!*/


void Ball::render( SDL_Renderer *gRenderer ) {
	SDL_Rect fillRect = { xPos - radius, yPos - radius, radius*2, radius*2 };
	SDL_SetRenderDrawColor( gRenderer, 0x50, 0xFF, 0x90, 0xFF );
	SDL_RenderFillRect( gRenderer, &fillRect );
}
