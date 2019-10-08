#include "map.h"
#include "global.h"

void map_Update()
{
	// Set in render buffer each part's updated position
	createBoundary();
}

// Simply prints a boundary inside the console
void createBoundary()
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
