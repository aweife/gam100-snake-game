#pragma once

#include "global.h"
#include "map.h"

#define ONESECONDINMS 1000
#define TENSECONDS 10

// Direction enum
typedef enum {
	DIRECTION_NONE,
	DIRECTION_UP,
	DIRECTION_RIGHT,
	DIRECTION_DOWN,
	DIRECTION_LEFT
} DIRECTION;

typedef struct {
	coordinates position;
	DIRECTION direction;
	double eulerX;
	double eulerY;
	char headChar;
} snakeHead;

// Snake body
typedef struct {
	coordinates position;
	CONSOLECOLOR color;
} snakeBody;

int snakeBodyCount;
double speed;
int speedCounter;
int totalElapsedTime;

// Player functions
void player_Init();
void player_Update(double euler);
void player_GetInput();
void setDirection(DIRECTION dir, char c);
void grow();
void follow();
void animate();
void checkCollision();
void speedUp();