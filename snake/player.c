#include "global.h"
#include "player.h"

// For now I only store 100 bodies' positions, any more is undefined behaviour
snakeBody snakeBodyArray[100]; 

void initPlayer()
{
	// Init head
	snakeBodyArray[0].position.x = 25;
	snakeBodyArray[0].position.y = 40;
	direction = 0;

	snakeLength = 1;
}

void updatePlayer()
{
	// Update head direction with player input
	getInput();

	// Move snake automatically
	move();
}

void getInput()
{
	// Map player input to direction
	// Limit the player to turn only (right angle)
	if (GetAsyncKeyState(VK_UP))
		if (direction != 1 && direction != 3)
			setDirection(1);
	if (GetAsyncKeyState(VK_RIGHT) && direction != 2)
		if (direction != 2 && direction != 4)
			setDirection(2);
	if (GetAsyncKeyState(VK_DOWN) && direction != 3)
		if (direction != 1 && direction != 3)
			setDirection(3);
	if (GetAsyncKeyState(VK_LEFT) && direction != 4)
		if (direction != 2 && direction != 4)
			setDirection(4);

	//if (GetAsyncKeyState(VK_SPACE)) bGameIsRunning = 0;
	if (GetAsyncKeyState(VK_SPACE)) grow(); // Debug grow
}

void move()
{
	// Set (current) position as head's tailPosition
	snakeBodyArray[0].tailPosition = snakeBodyArray[0].position;

	// Update position according to direction (input by player)
	switch (direction)
	{
	case 1: // UP
		snakeBodyArray[0].position.y--;
		break;
	case 2: // RIGHT
		snakeBodyArray[0].position.x++;
		break;
	case 3: // DOWN
		snakeBodyArray[0].position.y++;
		break;
	case 4: // LEFT
		snakeBodyArray[0].position.x--;
		break;
	}

	// If snake has body already, loop through the bodies and update them to 
	// take over previous head's position 
	if (snakeLength > 1) follow();

	// Finally, print on screen with updated positions
	animate();
}

void setDirection(int dir)
{
	direction = dir;
}

void grow()
{
	// Update the last tailPosition every time the snake grows
	snakeBodyArray[snakeLength].position = snakeBodyArray[snakeLength - 1].tailPosition;
	snakeLength++;
}

void follow()
{
	// For each body, take over the previous head's tailPosition
	for (int i = 1; i < snakeLength; i++)
	{
		coordinates currentPos = snakeBodyArray[i].position;
		snakeBodyArray[i].position = snakeBodyArray[i - 1].tailPosition;
		snakeBodyArray[i].tailPosition = currentPos;
	}
}

void animate()
{
	// Only the first head prints
	Console_Putchar(snakeBodyArray[0].position.x, snakeBodyArray[0].position.y, 'O');

	// While snake is moving, only clear the char at the last body's tailPosition
	if (direction != 0)
		Console_Putchar(snakeBodyArray[snakeLength - 1].tailPosition.x, snakeBodyArray[snakeLength - 1].tailPosition.y, ' ');
}