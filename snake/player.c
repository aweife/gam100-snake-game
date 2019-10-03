#include "global.h"
#include "player.h"

snakeBody snakeBodyArray[10];
int timer = 0;
int canGrow = 0;
int growth = 5;

void initPlayer()
{
	// Init head
	snakeBodyArray[0].direction = 0;
	snakeBodyArray[0].position.x = 25;
	snakeBodyArray[0].position.y = 40;
	setDirection(&snakeBodyArray[0], 1);
	snakeLength = 1;
}

void updatePlayer()
{
	timer++;
	if (timer > 10)
	{
		timer = 0;
		canGrow = 1;
	}

	getInput();
	if (snakeLength > 1) follow();
	if (canGrow && growth)
	{
		canGrow = 0;
		move(&snakeBodyArray[0]);
		grow(&snakeBodyArray[snakeLength], &snakeBodyArray[snakeLength - 1]);
		growth--;
	}
	else
		move(&snakeBodyArray[0]);
}

// Update head (snakeBody[0])'s direction with player inputs
void getInput()
{
	if (GetAsyncKeyState(VK_UP) && &snakeBodyArray[0].direction != 1)
		setDirection(&snakeBodyArray[0], 1);
	if (GetAsyncKeyState(VK_RIGHT) && &snakeBodyArray[0].direction != 2)
		setDirection(&snakeBodyArray[0], 2);
	if (GetAsyncKeyState(VK_DOWN) && &snakeBodyArray[0].direction != 3)
		setDirection(&snakeBodyArray[0], 3);
	if (GetAsyncKeyState(VK_LEFT) && &snakeBodyArray[0].direction != 4)
		setDirection(&snakeBodyArray[0], 4);

	if (GetAsyncKeyState(VK_SPACE)) bGameIsRunning = 0;
}


void move(snakeBody* self)
{
	// Set tail position as current position
	self->tail = self->position;

	// Update to new position
	self->position.x += self->moveVector.x;
	self->position.y += self->moveVector.y;

	Console_Putchar(self->position.x, self->position.y, 'O');
	Console_Putchar(snakeBodyArray[snakeLength - 1].tail.x, snakeBodyArray[snakeLength - 1].tail.y, ' ');
}

int setDirection(snakeBody* self, int dir)
{
	self->direction = dir;
	switch (dir)
	{
	case 1: // UP
		self->moveVector.x = 0;
		self->moveVector.y = -1;
		break;
	case 2: // RIGHT
		self->moveVector.x = 1;
		self->moveVector.y = 0;
		break;
	case 3: // DOWN
		self->moveVector.x = 0;
		self->moveVector.y = 1;
		break;
	case 4: // LEFT
		self->moveVector.x = -1;
		self->moveVector.y = 0;
		break;
	default:
		self->moveVector.x = 0;
		self->moveVector.y = 0;
		break;
	}
}

void grow(snakeBody* self, snakeBody* myHead)
{
	setDirection(self, myHead->direction);
	self->position = myHead->tail;
	Console_Putchar(self->position.x, self->position.y, 'O');
	snakeLength++;
}

void follow()
{
	int test = 0;
	for (int i = 1; i < snakeLength; i++)
	{
		move(&snakeBodyArray[i]);

		// Check if myHead changed direction
		if (snakeBodyArray[i].direction == snakeBodyArray[i-1].direction || test) continue;
		setDirection(&snakeBodyArray[i], snakeBodyArray[i - 1].direction); 
		test = 1;
	}
}