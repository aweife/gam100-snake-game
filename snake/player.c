#include "global.h"
#include "player.h"

void player_Init()
{
	// Init head
	snakeBodyArray[0].position.x = GAME_WIDTH * 0.5f;
	snakeBodyArray[0].position.y = GAME_HEIGHT * 0.5f;
	headDirection = DIRECTION_NONE;

	snakeLength = 1;
}

void player_Update()
{
	// Update head's position
	move();

	// If snake has body already, loop through the bodies and update them to 
	// take over previous head's position 
	if (snakeLength > 1) follow();

	// Set in render buffer each part's updated position
	animate();
}

void player_GetInput()
{
	// Map player input to direction
	// Limit the player to turn only (right angle)
	if (GetAsyncKeyState(VK_UP))
		if (headDirection != DIRECTION_UP && headDirection != DIRECTION_DOWN)
			setDirection(DIRECTION_UP);
	if (GetAsyncKeyState(VK_RIGHT))
		if (headDirection != DIRECTION_RIGHT && headDirection != DIRECTION_LEFT)
			setDirection(DIRECTION_RIGHT);
	if (GetAsyncKeyState(VK_DOWN))
		if (headDirection != DIRECTION_DOWN && headDirection != DIRECTION_UP)
			setDirection(DIRECTION_DOWN);
	if (GetAsyncKeyState(VK_LEFT))
		if (headDirection != DIRECTION_LEFT && headDirection != DIRECTION_RIGHT)
			setDirection(DIRECTION_LEFT);

	//if (GetAsyncKeyState(VK_SPACE)) bGameIsRunning = 0;
	if (GetAsyncKeyState(VK_SPACE)) grow(); // Debug grow
}

void grow()
{
	// Update the last tailPosition every time the snake grows
	snakeBodyArray[snakeLength].position = snakeBodyArray[snakeLength - 1].tailPosition;
	snakeLength++;
}

// Move head according to velocity
void move()
{
	// Set (current) position as head's tailPosition
	snakeBodyArray[0].tailPosition = snakeBodyArray[0].position;

	// Update position according to direction (input by player)
	switch (headDirection)
	{
	case DIRECTION_UP:
		snakeBodyArray[0].position.y--;
		break;
	case DIRECTION_RIGHT:
		snakeBodyArray[0].position.x++;
		break;
	case DIRECTION_DOWN:
		snakeBodyArray[0].position.y++;
		break;
	case DIRECTION_LEFT:
		snakeBodyArray[0].position.x--;
		break;
	}
}

// Update by player_GetInput()
void setDirection(DIRECTION dir)
{
	headDirection = dir;
}

// Make each body to catch up with their own heads
void follow()
{
	// For each body, take over their previous head's tailPosition
	for (int i = 1; i < snakeLength; i++)
	{
		coordinates currentPos = snakeBodyArray[i].position;
		snakeBodyArray[i].position = snakeBodyArray[i - 1].tailPosition;
		snakeBodyArray[i].tailPosition = currentPos;
	}
}

void animate()
{
	for (int i = 0; i < snakeLength; i++)
		Console_SetRenderBuffer_Char(snakeBodyArray[i].position.x, snakeBodyArray[i].position.y, 'O');
	//Console_Putchar(snakeBodyArray[0].position.x, snakeBodyArray[0].position.y, 'O');

	//// While snake is moving, only clear the char at the last body's tailPosition
	//if (headDirection != 0)
	//	Console_Putchar(snakeBodyArray[snakeLength - 1].tailPosition.x, snakeBodyArray[snakeLength - 1].tailPosition.y, ' ');
}