#include "Random/Random.h"
#include "Console/Console.h"
#include <Windows.h>

static int bGameIsRunning = 1;

int main(void)
{
	// Init game
	Console_Init();
	Random_Init();
	int x = 25;
	int y = 25;

	// Set title to window
	Console_SetTitle("Snake Test");

	// Setup font and window size
	Console_SetSquareFont();
	Console_SetWindowedMode(50, 50, true);
	Console_SetCursorVisibility(0);

	// Display sth
	Console_Printf(20, 20, "Hello Digipen");
	Console_Putchar(20, 21, 'o');

	// Game loop
	while (bGameIsRunning)
	{
		// Move player
		if (GetAsyncKeyState(VK_RIGHT)) x += 1;
		if (GetAsyncKeyState(VK_LEFT)) x -= 1;
		if (GetAsyncKeyState(VK_UP)) y -= 1;
		if (GetAsyncKeyState(VK_DOWN)) y += 1;

		if (GetAsyncKeyState(VK_SPACE)) bGameIsRunning = 0;

		// Clear display and draw player
		Console_Clear();
		Console_Putchar(x, y, 'o');

		Sleep(10);
	}

	// Shutdown game
	Console_CleanUp();

	return 0;
}
