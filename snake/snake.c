#include "global.h"

int main(void)
{
	// Init console
	Console_Init();
	Random_Init();
	Console_SetTitle("Snake Game");
	Console_SetSquareFont();
	Console_SetWindowedMode(50, 50, true);
	Console_SetCursorVisibility(0);
	bGameIsRunning = 1;

	// Init player
	initPlayer();

	// Game loop
	while (bGameIsRunning)
	{
		// Player
		updatePlayer();

		Sleep(100);
	}

	// Shutdown game
	Console_CleanUp();

	return 0;
}
