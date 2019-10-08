#include "global.h"
#include "player.h"

snakeHead head;

void player_Init()
{
	// Init head
	head.eulerX = GAME_WIDTH * 0.5f;
	head.eulerY = GAME_HEIGHT * 0.5f;
	head.direction = DIRECTION_NONE;

	snakeBodyCount = 0;
}

void player_Update(double euler)
{
	// Update head's position
	move(euler);

	// If snake has body already, loop through the bodies and update them to 
	// take over previous head's position 
	if (snakeBodyCount > 0) follow();

	// Set in render buffer each part's updated position
	animate();
}

void player_GetInput()
{
	// Map player input to direction
	// Limit the player to turn only (right angle)
	if (GetAsyncKeyState(VK_UP))
		if (head.direction != DIRECTION_UP && head.direction != DIRECTION_DOWN)
			setDirection(DIRECTION_UP);
	if (GetAsyncKeyState(VK_RIGHT))
		if (head.direction != DIRECTION_RIGHT && head.direction != DIRECTION_LEFT)
			setDirection(DIRECTION_RIGHT);
	if (GetAsyncKeyState(VK_DOWN))
		if (head.direction != DIRECTION_DOWN && head.direction != DIRECTION_UP)
			setDirection(DIRECTION_DOWN);
	if (GetAsyncKeyState(VK_LEFT))
		if (head.direction != DIRECTION_LEFT && head.direction != DIRECTION_RIGHT) {
			setDirection(DIRECTION_LEFT); grow();
		}

	//if (GetAsyncKeyState(VK_SPACE)) bGameIsRunning = 0;
	//if (GetAsyncKeyState(VK_SPACE)) grow(); // Debug grow
}

void grow()
{
	// Update the last tailPosition every time the snake grows
	if (snakeBodyCount == 0)
	{
		snakeBodyArray[0].position = head.position;
		snakeBodyCount++;
		snakeBodyCount++;
		return;
	}
	snakeBodyArray[snakeBodyCount].position = snakeBodyArray[snakeBodyCount - 1].position;
	snakeBodyCount++;
}

// Move head according to velocity
void move(double euler)
{
	// Update position according to direction (input by player)
	switch (head.direction)
	{
	case DIRECTION_UP:
		head.eulerY -= euler;
		break;
	case DIRECTION_RIGHT:
		head.eulerX += euler;
		break;
	case DIRECTION_DOWN:
		head.eulerY += euler;
		break;
	case DIRECTION_LEFT:
		head.eulerX -= euler;
		break;
	}

	head.position.x = head.eulerX;
	head.position.y = head.eulerY;
}

// Update by player_GetInput()
void setDirection(DIRECTION dir)
{
	head.direction = dir;
}

// Make each body to catch up with their own heads
void follow()
{
	if (head.direction == DIRECTION_UP || head.direction == DIRECTION_DOWN)
		if (snakeBodyArray[0].position.y == head.position.y) return;

	if (head.direction == DIRECTION_LEFT || head.direction == DIRECTION_RIGHT)
		if (snakeBodyArray[0].position.x == head.position.x) return;

	// For each body, take over their previous head's tailPosition
	for (int i = snakeBodyCount; i > 0; i--)
	{
		snakeBodyArray[i].position = snakeBodyArray[i - 1].position;
	}
	snakeBodyArray[0].position = head.position;
}

void animate()
{
	// Render head
	Console_SetRenderBuffer_Char(head.eulerX, head.eulerY, 'O');

	// Render body
	for (int i = 0; i < snakeBodyCount; i++)
		Console_SetRenderBuffer_Char(snakeBodyArray[i].position.x, snakeBodyArray[i].position.y, 'O');
	//Console_Putchar(snakeBodyArray[0].position.x, snakeBodyArray[0].position.y, 'O');

	//// While snake is moving, only clear the char at the last body's tailPosition
	//if (headDirection != 0)
	//	Console_Putchar(snakeBodyArray[snakeLength - 1].tailPosition.x, snakeBodyArray[snakeLength - 1].tailPosition.y, ' ');
}