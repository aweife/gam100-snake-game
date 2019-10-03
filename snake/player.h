#pragma once

typedef struct {
	int x;
	int y;
} coordinates;

// Snake body
typedef struct {
	int direction; 
	coordinates position;
	coordinates moveVector;
	coordinates tail;
} snakeBody;

int snakeLength;

void initPlayer();
void updatePlayer();
void getInput();
void move(snakeBody* self);
int setDirection(snakeBody* self, int dir);
void grow(snakeBody* self, snakeBody* myHead);
void follow();