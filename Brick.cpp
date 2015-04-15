#include "Brick.h"
using namespace std;


Brick::Brick() {
	int xPos = 0;
	int yPos = 0;
	int width = 0;
	int height = 0;
	bool exists = true;
	SDL_Rect srcrect;
	SDL_Rect dstrect;
}
Brick::Brick( int x, int y, int w, int h ) {
	int xPos = x;
	int yPos = y;
	int width = w;
	int height = h;
	bool exists = true;
	SDL_Rect srcrect;
	SDL_Rect dstrect;
}

int Brick::left() {
	return xPos;
}

int Brick::right() {
	return xPos + width;
}

int Brick::top() {
	return yPos;
}

int Brick::bottom() {
	return yPos + height;
}

void Brick::set( int x, int y, int w, int h ) {
	xPos = x;
	yPos = y;
	width = w;
	height = h;
	exists = true;

	srcrect.x = 50;
	srcrect.y = 0;
	srcrect.w = 50;
	srcrect.h = 25;

	dstrect.x = xPos;
	dstrect.y = yPos;
	dstrect.w = width;
	dstrect.h = height;
}

void Brick::destroy() {
	exists = false;
	xPos = yPos = width = height = -1;
}

void Brick::render(SDL_Renderer* gRenderer, SDL_Texture* gTexture) {
	if (exists) {
		SDL_Rect dstrect;
		dstrect.x = xPos;
		dstrect.y = yPos;
		dstrect.w = width;
		dstrect.h = height;
		SDL_RenderCopy( gRenderer, gTexture, &srcrect, &dstrect );
	}
}