OBJS = Breakout.cpp Ball.cpp Brick.cpp BrickConfig.cpp Paddle.cpp Scoreboard.cpp MainMenu.cpp

CC = g++

COMPILER_FLAGS = -Wall -std=c++0x 

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

OBJ_NAME = Breakout

all: $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
