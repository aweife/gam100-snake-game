#pragma once

// Direction enum
typedef enum {
	DIRECTION_NONE,
	DIRECTION_UP,
	DIRECTION_RIGHT,
	DIRECTION_DOWN,
	DIRECTION_LEFT
} DIRECTION;

typedef struct {
	int x;
	int y;
} coordinates;

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

// For now I only store 100 bodies' positions, any more is undefined behaviour
snakeBody snakeBodyArray[100];

// Player functions
void player_Init();
void player_Update(double euler);
void player_GetInput();
void move(double euler);
void setDirection(DIRECTION dir);
void grow();
void follow();
void animate();