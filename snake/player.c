#include "player.h"
#include "StateMachine.h"

// For now I only store 100 bodies' positions, any more is undefined behaviour
snakeBody snakeBodyArray[100];
snakeHead player;

// Initialise player
void player_Init()
{
	// Init head
	player.eulerX = GAME_WIDTH * 0.5f;
	player.eulerY = GAME_HEIGHT * 0.5f;
	player.direction = DIRECTION_NONE;
	snakeBodyCount = 1;
}

// Map arrows to player.direction
void player_GetInput()
{

	// Limit the player to turn only (right angle)
	if (GetAsyncKeyState(VK_UP))
		if (player.direction != DIRECTION_UP && player.direction != DIRECTION_DOWN)
			setDirection(DIRECTION_UP);
	if (GetAsyncKeyState(VK_RIGHT))
		if (player.direction != DIRECTION_RIGHT && player.direction != DIRECTION_LEFT)
			setDirection(DIRECTION_RIGHT);
	if (GetAsyncKeyState(VK_DOWN))
		if (player.direction != DIRECTION_DOWN && player.direction != DIRECTION_UP)
			setDirection(DIRECTION_DOWN);
	if (GetAsyncKeyState(VK_LEFT))
		if (player.direction != DIRECTION_LEFT && player.direction != DIRECTION_RIGHT)
			setDirection(DIRECTION_LEFT);


	//if (GetAsyncKeyState(VK_SPACE)) bGameIsRunning = 0;
	//if (GetAsyncKeyState(VK_SPACE)) grow(); // Debug grow
}

// Grow the snake by 1
void grow()
{
	snakeBodyArray[snakeBodyCount].position = snakeBodyArray[snakeBodyCount - 1].position;
	snakeBodyCount++;
}

// Move head according to velocity
// Update bodies to follow
// Animate snake on screen
// Collision check
void player_Update(double euler)
{
	// Update position according to direction (input by player)
	switch (player.direction)
	{
	case DIRECTION_UP:
		player.eulerY -= euler;
		break;
	case DIRECTION_RIGHT:
		player.eulerX += euler;
		break;
	case DIRECTION_DOWN:
		player.eulerY += euler;
		break;
	case DIRECTION_LEFT:
		player.eulerX -= euler;
		break;
	}

	// Cast double values into int
	player.position.x = player.eulerX;
	player.position.y = player.eulerY;

	checkCollision();
	follow();
	animate();
}

// Update by player_GetInput()
void setDirection(DIRECTION dir)
{
	player.direction = dir;
}

// Loop through the bodies from the back and update their positions 
// to take over previous head's position 
void follow()
{
	// To check if head has moved, if so, update bodies
	// Don't compare on y axis if snake is moving on vertically
	if (player.direction == DIRECTION_UP || player.direction == DIRECTION_DOWN)
		if (snakeBodyArray[0].position.y == player.position.y) return;

	// Don't compare on x axis if snake is moving on horizontally
	if (player.direction == DIRECTION_LEFT || player.direction == DIRECTION_RIGHT)
		if (snakeBodyArray[0].position.x == player.position.x) return;

	// For each body, take over their previous head's tailPosition
	for (int i = snakeBodyCount; i > 1; i--)
	{
		snakeBodyArray[i - 1].position = snakeBodyArray[i - 2].position;
	}
	snakeBodyArray[0].position = player.position;
}

// Set in render buffer each part's updated position
void animate()
{
	// Render the head separately
	Console_SetRenderBuffer_Char(snakeBodyArray[0].position.x, snakeBodyArray[0].position.y, 'H');

	// Render body (+1 because of head
	for (int i = 1; i < snakeBodyCount; i++)
		Console_SetRenderBuffer_Char(snakeBodyArray[i].position.x, snakeBodyArray[i].position.y, 'B');

	// OLD CODE: Moving the head and clearing the tail using putchar()
	//// While snake is moving, only clear the char at the last body's tailPosition
	//Console_Putchar(snakeBodyArray[0].position.x, snakeBodyArray[0].position.y, 'O');
	//if (headDirection != 0)
	//	Console_Putchar(snakeBodyArray[snakeLength - 1].tailPosition.x, snakeBodyArray[snakeLength - 1].tailPosition.y, ' ');
}

// Check collision with boundary, walls, itself and food
void checkCollision()
{
	// Boundary limits
	if (player.position.x < 1 ||			// Left side of screen
		player.position.x > GAME_WIDTH - 1 ||	// Right
		player.position.y < 1 ||			// Top
		player.position.y > GAME_HEIGHT - 1)	// Bottom
		goGameOver();

	// Collision against itself but only from the 4th body part onwards
	if (snakeBodyCount > 3)
		for (int i = 3; i < snakeBodyCount; i++)
			if (player.position.x == snakeBodyArray[i].position.x &&
				player.position.y == snakeBodyArray[i].position.y)
				goGameOver();

	if (player.position.x == foodArray[0].x && player.position.y == foodArray[0].y)
	{
		// Remove the food first
		spawnFood();

		// Then grow
		grow();
	}
}