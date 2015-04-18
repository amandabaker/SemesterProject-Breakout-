#include "Scoreboard.h"
using namespace std;

Scoreboard::Scoreboard() {
	int score	= 0;
	int xPos	= 10;
	int yPos	= 5;
	int width	= SCREEN_WIDTH - 10;
	int height  = 40;
	SDL_Color textColor;
}

void Scoreboard::set() {
	score		= 0;
	xPos		= 25;
	yPos		= 0;
	width		= SCREEN_WIDTH - 10;
	height		= 40;
	textColor.r = 0x42;
	textColor.g = 0x42;
	textColor.b = 0x42;
	textColor.a = 0x99;
}

void Scoreboard::setScore( int newScore ) {
	score	= newScore;

}

void Scoreboard::addScore( int points ) {
	score  += points;
}

void Scoreboard::render( SDL_Renderer* gRenderer, TTF_Font* gFont, LTexture gTextTexture ) {
	string s = std::to_string( static_cast<long long>( score ) );
	s = string( 10 - s.size(), ' ' ) + s;
	string text = "Score: " + s;
	gTextTexture.loadFromRenderedText( text, textColor );
	gTextTexture.setBlendMode( SDL_BLENDMODE_BLEND );
	gTextTexture.setAlpha( 150 );
	gTextTexture.render( xPos, yPos, gRenderer );
}
