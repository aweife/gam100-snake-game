#pragma once

// Snake body
typedef struct {
	int x;
	int y;
} snakeBody;

// 1 = up, 2 = right, 3 = down, 4 = left, 0 = stop
int currentDirection;

void initPlayer();
void updatePlayer();
void getInputs();
void moveInDirection();
void moveBody(int x, int y, snakeBody* sb);