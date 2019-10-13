#include "player.h"

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
	player.headChar = '^';

	// Initial speed
	speed = 2;
	speedCounter = 0;
}

// Map arrows to player.direction
void player_GetInput()
{

	// Limit the player to turn only (right angle)
	// The & 0x8000 is to ensure key only get pressed once
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		if (player.direction != DIRECTION_UP && player.direction != DIRECTION_DOWN)
			setDirection(DIRECTION_UP, '^');
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		if (player.direction != DIRECTION_RIGHT && player.direction != DIRECTION_LEFT)
			setDirection(DIRECTION_RIGHT, '>');
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		if (player.direction != DIRECTION_DOWN && player.direction != DIRECTION_UP)
			setDirection(DIRECTION_DOWN, 'v');
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		if (player.direction != DIRECTION_LEFT && player.direction != DIRECTION_RIGHT)
			setDirection(DIRECTION_LEFT, '<');


	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) goGameOver(snakeBodyCount - 1);
}

// Grow the snake by 1
void grow(CONSOLECOLOR color)
{
	snakeBodyArray[snakeBodyCount].position = snakeBodyArray[snakeBodyCount - 1].position;
	snakeBodyArray[snakeBodyCount].color = color;

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
		player.eulerY -= euler * log(speed);
		break;
	case DIRECTION_RIGHT:
		player.eulerX += euler * log(speed);
		break;
	case DIRECTION_DOWN:
		player.eulerY += euler * log(speed);
		break;
	case DIRECTION_LEFT:
		player.eulerX -= euler * log(speed);
		break;
	case DIRECTION_NONE:
		player.eulerX = GAME_WIDTH * 0.5f;
		player.eulerY = GAME_HEIGHT * 0.5f;
		break;
	default:
		break;
	}

	// Cast double values into int
	player.position.x = player.eulerX;
	player.position.y = player.eulerY;

	checkCollision();
	follow();
	animate();
	speedUp();
}

// Update by player_GetInput()
void setDirection(DIRECTION dir, char c)
{
	player.direction = dir;
	player.headChar = c;
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
	Console_SetRenderBuffer_CharColor(snakeBodyArray[0].position.x, snakeBodyArray[0].position.y, player.headChar,
		FOREGROUND_RED);

	// Render body (+1 because of head
	for (int i = 1; i < snakeBodyCount; i++)
		Console_SetRenderBuffer_CharColor(snakeBodyArray[i].position.x, snakeBodyArray[i].position.y, 'O',
			snakeBodyArray[i].color);

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
		goGameOver(snakeBodyCount - 1);

	// Collision against itself but only from the 4th body part onwards
	if (snakeBodyCount > 3)
		for (int i = 3; i < snakeBodyCount; i++)
			if (player.position.x == snakeBodyArray[i].position.x &&
				player.position.y == snakeBodyArray[i].position.y)
				goGameOver(snakeBodyCount - 1);

	// Collision with food
	for (int i = 0; i < foodCount; i++)
		if (player.position.x == foodArray[i].x && player.position.y == foodArray[i].y)
		{
			// Remove the food first
			spawnFood(i);

			// Then grow
			grow(GREEN);
		}

	// Collision with walls
	for (int i = 0; i < wallCount; i++)
		if (player.position.x == wallArray[i].x && player.position.y == wallArray[i].y)
			goGameOver(snakeBodyCount - 1);
}

// Speed up player once every 10s, and grow it by 1
void speedUp()
{
	speedCounter = (Clock_GetElapsedTimeMs() / ONESECONDINMS) - totalElapsedTime;
	if (speedCounter > TENSECONDS)
	{
		totalElapsedTime += speedCounter;
		speedCounter = 0;

		// Only speed up when player ate the first food
		if (snakeBodyCount == 1) return;
		speed+=snakeBodyCount;
		grow(DARKGREEN);
	}
}