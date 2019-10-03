#pragma once

typedef struct {
	int x;
	int y;
} coordinates;

// Snake body
typedef struct {
	coordinates position;
	coordinates tailPosition;
} snakeBody;

int snakeLength;
int direction;

void initPlayer();
void updatePlayer();
void getInput();
void move();
void setDirection(int dir);
void grow();
void follow();
void animate();