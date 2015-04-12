#include "BrickConfig.h"
using namespace std;


BrickConfig::BrickConfig() {
/*this assumes a rectangle. We can get fancy later*/
	int numCol = 10;
	int numRow = 5;
	int numBricks = numCol * numRow;
	int brickWidth = SCREEN_WIDTH / (numRow + 2);
	int brickHeight = brickWidth/2;
	int spaceBtwn = SCREEN_WIDTH / (numRow + 2) / (numRow - 1) * 2;
	int spaceEdge = SCREEN_WIDTH - brickWidth * numRow - spaceBtwn * (numRow - 1);
	int xPos = 0;
	int yPos = 0;
	
	vector<Brick> brickVect( numBricks );
}

void BrickConfig::set() {
	numCol = 10;
	numRow = 5;
	numBricks = numCol * numRow;
	brickWidth = SCREEN_WIDTH / (numCol + 2);
	brickHeight = brickWidth/2;
	spaceBtwn = SCREEN_WIDTH / (numCol + 2) / (numCol - 1) * 2;
	spaceEdge = ( SCREEN_WIDTH - brickWidth * numCol - spaceBtwn * (numCol - 1) ) / 2;
	xPos = 0;
	yPos = 0;
	
	brickVect.resize( numBricks );
	
	for ( int i=0; i<numCol; i++ ) {		//i is horisontal iteration
		for ( int j=0; j<numRow; j++ ) {	//j is vertical iteration
			xPos = spaceEdge + i * (brickWidth + spaceBtwn);
			yPos = spaceEdge + j * (brickHeight + spaceBtwn);
			brickVect[ j*numCol + i ].set( xPos, yPos, brickWidth, brickHeight );
		}
	}
}

void BrickConfig::render( SDL_Renderer* gRenderer ) {
	for ( int i=0; i<numBricks; i++ ) {	
		brickVect[ i ].render( gRenderer );
	}
}

void BrickConfig::removeBrick(int row, int col){
	numBricks --;
}
}
