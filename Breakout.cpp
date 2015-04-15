#include "Breakout.h"

/*
  --TODO--
	Score: 
		kept as a function of time
	Timer:
		keeps time...
	Main Menu:
		Reset Bricks
		Spacebar to play

*/

using namespace std;

bool init();
bool loadMedia();
bool checkCollision( SDL_Rect a, SDL_Rect b );
void close();
SDL_Window*   gWindow      = NULL;
SDL_Surface*  loadSurface( std::string path );
SDL_Surface*  gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
SDL_Renderer* gRenderer	   = NULL;
SDL_Texture*  gTexture     = NULL;
SDL_Texture*  loadTexture( std::string path );
TTF_Font*     gFont        = NULL;
LTexture      gTextTexture;


LTexture::LTexture() {
  mTexture = NULL;
  mWidth = 0;
  mHeight = 0;
}

LTexture::~LTexture() {
  free();
}

bool LTexture::loadFromFile( std::string path, SDL_Renderer* gRenderer ) {

  free();
  
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  if( loadedSurface == NULL ) {
    printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
  }
  else {
    //color key image
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
    //create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
    if( newTexture == NULL ) {
      printf( "Unable to create texture from %s! SDL Error %s\n", path.c_str(), SDL_GetError() );
    }
    else {
      //get image dimensions
      mWidth  = loadedSurface->w;
      mHeight = loadedSurface->h;
    }

    //get rid of old surface
    SDL_FreeSurface( loadedSurface );
  }

  mTexture = newTexture;
  return mTexture != NULL;
}

bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor ){
  
  free();

  SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
  if( textSurface == NULL ) {
    printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
  }
  else {
    //create texture form surface pixels
    mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
    if( mTexture == NULL ){
      printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
    }
    else {
      mWidth  = textSurface->w;
      mHeight = textSurface->h;
    }

    SDL_FreeSurface( textSurface );
  }

  return mTexture != NULL;
}

void LTexture::free() {
  if( mTexture != NULL ) {
    SDL_DestroyTexture( mTexture );
    mTexture = NULL;
    mWidth   = 0;
    mHeight  = 0;
  }
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue ) {
  SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending ) {
  SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha ) {
  SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip ) {
  SDL_Rect renderQuad = { x, y, mWidth, mHeight };

  if( clip != NULL ) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth() {
  return mWidth;
}

int LTexture::getHeight() {
  return mHeight;
}

bool init() {
	
	//Initialization flag
	bool success = true;
  
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else {
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create Window TODO
		gWindow = SDL_CreateWindow( "Breakout!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else {
			//Get window surface
			//gScreenSurface = SDL_GetWindowSurface( gWindow );
			if ( SDL_GetRenderer != NULL ) {
				gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			}
			else {
				gRenderer = SDL_GetRenderer( gWindow );
			}
			if ( gRenderer == NULL ) { 
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else {
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !(IMG_Init( imgFlags ) & imgFlags ) ) {
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
        //Initialize SDL_ttf
        if( TTF_Init() == -1 ) {
          printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        }
			}
		}
  }
	return success;
}

bool loadMedia() {
	
	//Loading success flag
	bool success = true;
 
  //open font
  gFont = TTF_OpenFont( "Roboto-Font/Roboto-Thin.ttf", 36 );
  if( gFont == NULL ) {
    printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
    success = false;
  }
  else {
    //Render text
    SDL_Color textColor = { 0, 0, 0 };
    if( !gTextTexture.loadFromRenderedText( "Texttttt", textColor ) ) {
      printf( "Failed to render text texture!\n" );
      success = false;
    }
  }
  
	//Load PNG texture
	gTexture = loadTexture( "PNG/sprites.png" );
	if( gTexture == NULL ) {
		printf( "Failed to load texture image!\n" );
		success = false;
	}

	return success;
}

bool checkCollision ( Ball &ball, BrickConfig &brickConfig, Paddle &paddle ) {
	int leftBall,	leftBrick,		leftPaddle;
	int rightBall,	rightBrick,		rightPaddle;
	int topBall,	topBrick,		topPaddle;
	int bottomBall,	bottomBrick,	bottomPaddle;

	leftBall   = ball.left();					
	rightBall  = ball.right();
	topBall	 	 = ball.top();
	bottomBall = ball.bottom();
 
	//check collision with bricks
	for ( int i=0; i < brickConfig.size(); i++) { 
		
		leftBrick	= brickConfig.left( i );
		rightBrick	= brickConfig.right( i );
		topBrick	= brickConfig.top( i );
		bottomBrick = brickConfig.bottom( i );

		
		if	   ( bottomBall <= topBrick )		continue;	      
		else if( topBall	>= bottomBrick )	continue;
		else if( rightBall	<= leftBrick )		continue;
		else if( leftBall	>= rightBrick )		continue;
		else { 
			//ball collided with brickVect[ i ].  We will assume that you can only hit one brick at a time for now
			brickConfig.destroy( i ); //destroy brickVect[ i ]
			ball.changeYDir();
			break; //REMOVE THIS IF YOU WANT TO ALLOW MULTIPLE BRICKS TO BREAK AT A TIME
		}
	}
	
	leftPaddle	 = paddle.left();
	rightPaddle  = paddle.right();
	topPaddle	 = paddle.top();
	bottomPaddle = paddle.bottom();

	//check collision with paddle
	if	   ( bottomBall <= topPaddle )		return false;
	else if( topBall	>= bottomPaddle )	return false;
	else if( rightBall	<= leftPaddle )		return false;
	else if( leftBall	>= rightPaddle )		return false;
		ball.changeYDir();
  return true;    //
}

void close() {
	
	//Deallocate surface
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i ) {
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}
	//SDL_FreeSurface( gScreenSurface );
	//SDL_FreeSurface( gCurrentSurface );

	gTextTexture.free();

  TTF_CloseFont( gFont );
  gFont = NULL;
  
  SDL_DestroyTexture( gTexture );
	gTexture = NULL;
  
	//Destory Window
	SDL_DestroyWindow( gWindow );
	SDL_DestroyRenderer( gRenderer );
	gWindow   = NULL;
	gRenderer = NULL;
  
	//Quit SDL subsystems
  TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface( std::string path ) {  /*THIS MAY NOT BE NECESSARY FOR PROJECT!!*/
	
	//Load image at a specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	return loadedSurface;
}

SDL_Texture* loadTexture( std::string path ) {

	//The final Texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL ) {
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else {
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL ) {
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;
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
			paddle.set();

			//Build Brick setup
			BrickConfig brickConfig;
			brickConfig.set();

			//Create Ball
			Ball ball;
			ball.set();

			SDL_Rect scoreFrame = { 0, 0, SCREEN_WIDTH, scoreboardHeight };

			unsigned int startTime;
      
			//While game is running
			while ( !quit ) {

				startTime = SDL_GetTicks();
				while ( SDL_GetTicks() < startTime + 5 ){
					//Do nothing for 10 ms (goal: constant ball speed whether or not paddle moves)
				}
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 ){
					if ( e.type == SDL_QUIT ) {
					quit = true;
					}
					else if( e.type == SDL_KEYDOWN ) {
						switch( e.key.keysym.sym ) {
						case SDLK_LEFT:
							paddle.setXVel(-1);
							break;
						case SDLK_RIGHT:
							paddle.setXVel(1);
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
					if (!ball.move()) {
						//Game Over
					}
					
					checkCollision( ball, brickConfig, paddle);

					//Clear Screen
					SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
					SDL_RenderClear( gRenderer );

					//Update Score Board
					SDL_SetRenderDrawColor( gRenderer, 0x1D, 0xE9, 0xB6, 0xFF ); 
					SDL_RenderFillRect( gRenderer, &scoreFrame );

					//Update Game screen
					paddle.render( gRenderer, gTexture );
					brickConfig.render( gRenderer, gTexture );
					ball.render( gRenderer, gTexture );

					//Update screen
					SDL_RenderPresent( gRenderer );

				}
				ball.move();  
				checkCollision( ball, brickConfig, paddle );

				//Clear Screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Update Scoreboard
				SDL_SetRenderDrawColor( gRenderer, 0x1D, 0xE9, 0xB6, 0xFF ); 
				SDL_RenderFillRect( gRenderer, &scoreFrame );

				//Update Game Screen
				paddle.render( gRenderer, gTexture );
				brickConfig.render( gRenderer, gTexture );
				ball.render( gRenderer, gTexture );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}
  
	close();
  
	return 0;
}
