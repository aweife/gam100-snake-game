#include "global.h"
#include "player.h"

snakeBody snakeBodyArray[10];

void initPlayer()
{
	currentDirection = 0;
	snakeBodyArray[0].x = 25;
	snakeBodyArray[0].y = 25;
}

void updatePlayer()
{
	getInputs();
	moveInDirection();
}

void getInputs()
{
	if (GetAsyncKeyState(VK_RIGHT) && currentDirection != 2) currentDirection = 2;
	if (GetAsyncKeyState(VK_LEFT) && currentDirection != 4) currentDirection = 4;
	if (GetAsyncKeyState(VK_UP) && currentDirection != 1) currentDirection = 1;
	if (GetAsyncKeyState(VK_DOWN) && currentDirection != 3) currentDirection = 3;

	if (GetAsyncKeyState(VK_SPACE)) bGameIsRunning = 0;
}

void moveInDirection()
{
	switch (currentDirection)
	{
	case 1: // UP
		moveBody(0, -1, &snakeBodyArray[0]);
		break;
	case 2: // RIGHT
		moveBody(1, 0, &snakeBodyArray[0]);
		break;
	case 3: // DOWN
		moveBody(0, 1, &snakeBodyArray[0]);
		break;
	case 4: // LEFT
		moveBody(-1, 0, &snakeBodyArray[0]);
		break;
	default: // STOP
		moveBody(0, 0, &snakeBodyArray[0]);
		break;
	}
}

void moveBody(int x, int y, snakeBody* sb)
{
	Console_Putchar(sb->x, sb->y, ' ');
	sb->x += x;
	sb->y += y;
	Console_Putchar(sb->x, sb->y, 'O');
}