#include <SDL.h>
#include <stdio.h>
#include <string>
#include "Breakout.h"

using namespace std;

bool init();
bool loadMedia();
void close();
SDL_Window* gWindow = NULL;
SDL_Surface* loadSurface( std::string path );
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
SDL_Renderer* gRenderer = NULL;


bool init() {
  //Initialization flag
  bool success = true;
  
  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    success = false;
  }
  else {
    //Create Window
    gWindow = SDL_CreateWindow( "Breakout!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL ) {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
      success = false;
    }
    else {
      //Get window surface
      gScreenSurface = SDL_GetWindowSurface( gWindow );
	  gRenderer = SDL_CreateRenderer ( gWindow, -1, SDL_RENDERER_ACCELERATED );
	  if ( gRenderer == NULL ) {
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
	    success = false;
	  }
	  else {
	    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
	  }
    }
	  
  }
  return success;
}

bool loadMedia() {
  //Loading success flag
  bool success = true;
  
  //TODO here is where we would load a background if necessary. 

  return success;
}

void close() {
  //Deallocate surface
  for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i ) {
    SDL_FreeSurface( gKeyPressSurfaces[ i ] );
	gKeyPressSurfaces[ i ] = NULL;
  }
  SDL_FreeSurface( gScreenSurface );
  SDL_FreeSurface( gCurrentSurface );
  
  //Destory Window
  SDL_DestroyWindow( gWindow );
  SDL_DestroyRenderer( gRenderer );
  gWindow = NULL;
  
  //Quit SDL subsystems
  SDL_Quit();
}

SDL_Surface* loadSurface( std::string path ) {  /*THIS MAY NOT BE NECESSARY FOR PROJECT!!*/
  //Load image at a specified path
  SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
  if( loadedSurface == NULL ) {
    printf( "Unable to load image%s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
  }
  return loadedSurface;
}

int main( int argc, char* args[]) {
  
  //initialize SDL and create window
  if ( !init() ) {
    printf( "Failed to initialize!\n" );
  }
  else {
    //Create Window
    if ( !loadMedia() ) {
      printf ( "Failed to load media!\n" );
    }
    else {
      //Main loop flag
      bool quit = false;
      
      //Event handler
      SDL_Event e;

	  //Create Paddle
	  Paddle paddle;
	  paddle.setEverything();
      
      //While game is running
      while ( !quit ) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ){
          if ( e.type == SDL_QUIT ) {
            quit = true;
          }
          else if( e.type == SDL_KEYDOWN ) {
			switch( e.key.keysym.sym ) {
              case SDLK_LEFT:
                paddle.setXVel(-10);
                break;
              case SDLK_RIGHT:
                paddle.setXVel(10);
                break;
              default:
                break;
            }
          }
		  else if ( e.type == SDL_KEYUP ) {
		    switch( e.key.keysym.sym ) {
			  case SDLK_LEFT:
			    paddle.setXVel(0);
				break;
			  case SDLK_RIGHT:
				paddle.setXVel(0);
				break;
			  default:
				break;
			}
		  }
		  paddle.movePaddle();

		//Clear Screen 
		SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
		SDL_RenderClear( gRenderer );

		//draw paddle
		paddle.render( gRenderer );

		//Update screen
		SDL_RenderPresent( gRenderer );
        }
      }
    }
  }
  
  close();
  
  return 0;
}
