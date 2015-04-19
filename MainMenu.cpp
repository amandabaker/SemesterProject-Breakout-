#include "MainMenu.h"
using namespace std;

MainMenu::MainMenu() {
  SDL_Color textColor;
}

void MainMenu::set() {
	SDL_Color textColor = { 0x00, 0x00, 0xFF, 0xFF };
}

void MainMenu::render( SDL_Renderer* gRenderer, TTF_Font* gFont, LTexture gTextTexture, int menuType ) {
	switch ( menuType ) {
	case( MAIN_MENU ): 
		renderMainMenu( gRenderer, gFont, gTextTexture );
		break;
	case( GAME_OVER ):
		renderGameOver( gRenderer, gFont, gTextTexture );
		break;
	case( PAUSE_GAME ):
		renderPause( gRenderer, gFont, gTextTexture );
		break;
	default:
		break;
	}
}

void MainMenu::renderMainMenu( SDL_Renderer* gRenderer, TTF_Font* gFont, LTexture gTextTexture ) {
	string menuText(  " Welcome to Breakout! " );
	string menuText2( " Press SPACE to begin " );
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xAA);
	SDL_SetRenderDrawBlendMode( gRenderer, SDL_BLENDMODE_ADD );
	SDL_RenderFillRect( gRenderer, NULL );
	SDL_RenderPresent( gRenderer );

	gTextTexture.setBlendMode( SDL_BLENDMODE_ADD );
	gTextTexture.setAlpha( 0x00 );
	gTextTexture.loadFromRenderedText( menuText, textColor );
	gTextTexture.render( 120, 250, gRenderer );
	gTextTexture.loadFromRenderedText( menuText2, textColor );
	gTextTexture.render( 125, 350, gRenderer );
}

void MainMenu::renderGameOver( SDL_Renderer* gRenderer, TTF_Font* gFont, LTexture gTextTexture ) {
	
	string gameOver(  "        GAME OVER!       " );
	string gameOver2( "Press SPACE to play again" );
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xAA);
	SDL_SetRenderDrawBlendMode( gRenderer, SDL_BLENDMODE_BLEND );
	SDL_RenderFillRect( gRenderer, NULL );
	SDL_RenderPresent( gRenderer );

	gTextTexture.setBlendMode( SDL_BLENDMODE_ADD );
	gTextTexture.setAlpha( 0x00 );
	gTextTexture.loadFromRenderedText( gameOver, textColor );
	gTextTexture.render( 120, 250, gRenderer );
	gTextTexture.loadFromRenderedText( gameOver2, textColor );
	gTextTexture.render( 125, 350, gRenderer );
}

void MainMenu::renderPause( SDL_Renderer* gRenderer, TTF_Font* gFont, LTexture gTextTexture ) {
	
	string pause(  "      Game Paused      " );
	string pause2( "Press SPACE to continue" );
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xAA);
	SDL_SetRenderDrawBlendMode( gRenderer, SDL_BLENDMODE_BLEND );
	SDL_RenderFillRect( gRenderer, NULL );
	SDL_RenderPresent( gRenderer );

	gTextTexture.setBlendMode( SDL_BLENDMODE_ADD );
	gTextTexture.setAlpha( 0x00 );
	gTextTexture.loadFromRenderedText( pause, textColor );
	gTextTexture.render( 120, 250, gRenderer );
	gTextTexture.loadFromRenderedText( pause2, textColor );
	gTextTexture.render( 125, 350, gRenderer );
}
