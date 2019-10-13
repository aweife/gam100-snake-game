#include "map.h"

void map_Init()
{
	foodCount = 3;
	wallCount = 0;

	// Spawn randomly generated walls on the map
	for (int x = Random_Range(2, 10); x < GAME_WIDTH - 12; x += 10)
		for (int y = Random_Range(2, 10); y < GAME_HEIGHT - 12; y += 10)
			spawnWall(x, y, Random_Range(1, 10), Random_Range(1, 10));

	// Spawn food must be after walls
	for (int i = 0; i < foodCount; i++)
		spawnFood(i);
}

// Render everything into the console
void map_Update()
{
	// Set in render buffer each part's updated position
	renderBoundary();
	renderFood();
	renderWall();
}

// Randomly spawn 1 food
void spawnFood(int index)
{
	int x;
	int y;

	// Keep randomize if spawned in wall
	do
	{
		x = Random_Range(2, GAME_WIDTH - 2);
		y = Random_Range(2, GAME_HEIGHT - 2);
	} while (checkWithWall(x, y));

	foodArray[index].x = x;
	foodArray[index].y = y;
}

// Check if im spawning on existing walls
int checkWithWall(int x, int y)
{
	for (int i = 0; i < wallCount; i++)
	{
		if (x == wallArray[i].x || y == wallArray[i].y)
			return 1;
	}

	return 0;
}

// Create an randomized rectangle
void spawnWall(int offsetX, int offsetY, int sizeX, int sizeY)
{
	for (int i = offsetX; i < offsetX + sizeX; i++)
	{
		for (int j = offsetY; j < offsetY + sizeY; j++)
		{
			wallArray[wallCount].x = i;
			wallArray[wallCount].y = j;
			wallCount++;
		}
	}
}

// Simply render a fixed boundary
void renderBoundary()
{
	// Horizontal walls
	for (int x = 1; x < GAME_WIDTH; x++)
	{
		Console_SetRenderBuffer_CharColor(x, 0, "X", YELLOW);
		Console_SetRenderBuffer_CharColor(x, GAME_WIDTH, "X", YELLOW);
	}
	// Vertical walls
	for (int y = 1; y < GAME_HEIGHT; y++)
	{
		Console_SetRenderBuffer_CharColor(0, y, "X", YELLOW);
		Console_SetRenderBuffer_CharColor(GAME_WIDTH, y, "X", YELLOW);
	}
}

// Simply render everything inside the wallarray
void renderWall()
{
	for (int i = 0; i < wallCount; i++)
		Console_SetRenderBuffer_CharColor(wallArray[i].x, wallArray[i].y, 'X', YELLOW);
}

// Simply render everything inside the foodrray
void renderFood()
{
	for (int i = 0; i < foodCount; i++)
		Console_SetRenderBuffer_CharColor(foodArray[i].x, foodArray[i].y, 'O', GREEN);
}
