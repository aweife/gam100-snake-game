#include "map.h"

int foodCount = 1;

void map_Update()
{
	// Set in render buffer each part's updated position
	renderBoundary();
	renderFood();
}

// Simply prints a boundary inside the console
void renderBoundary()
{
	// Horizontal walls
	for (int x = 1; x < GAME_WIDTH; x++)
	{
		Console_SetRenderBuffer_Char(x, 0, "X");
		Console_SetRenderBuffer_Char(x, GAME_WIDTH, "X");
	}
	// Vertical walls
	for (int y = 1; y < GAME_HEIGHT; y++)
	{
		Console_SetRenderBuffer_Char(0, y, "X");
		Console_SetRenderBuffer_Char(GAME_WIDTH, y, "X");
	}
}

// Randomly spawn 1 food
void spawnFood()
{
	int x = Random_Range(1, GAME_WIDTH);
	int y = Random_Range(1, GAME_HEIGHT);

	foodArray[0].x = x;
	foodArray[0].y = y;
}

void renderFood()
{
	for (int i = 0; i < foodCount; i++)
		Console_SetRenderBuffer_Char(foodArray[i].x, foodArray[i].y, 'F');
}
