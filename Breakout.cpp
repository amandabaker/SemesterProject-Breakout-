#include <SDL.h>
#include <stdio.h>
#include "Breakout.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

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
    gWindow = SDL_CreateWindow( "Breakout!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL ) {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
      success = false;
    }
    else {
      //Get window surface
      gScreenSurface = SDL_GetWindowSurface( gWindow );
    }
  }
  
  return success;
}

bool loadMedia() {
  //Loading success flag
  bool success = true;
  
  //TODO here is where we would load a background if necessary. 
}

void close() {
  //Deallocate surface
  SDL_FreeSurface( /*Surface name*/ );
  /*Surface name*/ = NULL;
  
  //Destory Window
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  
  //Quit SDL subsystems
  SDL_Quit();
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
      //Get window surface
      screenSurface = SDL_GetWindowSurface ( window );
      
      //Fill surface black
      SDL_FillRect ( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );\
      
      //Update the surface
      SDL_UpdateWindowSurface( gWindow );
    }
  }
  
  close();
  
  return 0;
}
