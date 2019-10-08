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

// Direction enum
typedef enum {
	DIRECTION_NONE,
	DIRECTION_UP,
	DIRECTION_RIGHT,
	DIRECTION_DOWN,
	DIRECTION_LEFT
} DIRECTION;

int snakeLength;
DIRECTION headDirection;

// For now I only store 100 bodies' positions, any more is undefined behaviour
snakeBody snakeBodyArray[100];

// Player functions
void player_Init();
void player_Update();
void player_GetInput();
void move();
void setDirection(DIRECTION dir);
void grow();
void follow();
void animate();