#pragma once

#include "global.h"
#include "map.h"

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
} snakeHead;

// Snake body
typedef struct {
	coordinates position;
} snakeBody;

int snakeBodyCount;

// Player functions
void player_Init();
void player_Update(double euler);
void player_GetInput();
void setDirection(DIRECTION dir);
void grow();
void follow();
void animate();
void checkCollision();