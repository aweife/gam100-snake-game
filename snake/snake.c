#include "global.h"
#include "Clock/Clock.h"
#include "player.h"
#include "map.h"

static int bGameIsRunning;

// Euler method calculation for movement
//static double EulerX = 0.0f;
//static double Velocity = 0.001;

void initGame();
void runGame();

int main(void)
{
	initGame();
	while (bGameIsRunning) runGame();

	// Shutdown game
	Console_CleanUp();

	return 0;
}

// Initialise the console, player and map
void initGame()
{
	// Init console
	Console_Init();
	Random_Init();
	Console_SetTitle("Snake Game");
	Console_SetSquareFont();
	Console_SetWindowedMode(GAME_WIDTH + 1, GAME_HEIGHT + 1 + CONSOLE_HEIGHT, true);
	Console_SetCursorVisibility(0);
	bGameIsRunning = 1;

	// Init player
	player_Init();
}

// The game loop
void runGame()
{
	// Frame Time calculation, DeltaTime      
	Clock_GameLoopStart();

	// Number of pixels to move per second
	//EulerX += Velocity * Clock_GetDeltaTime();

	// First, we record player inputs
	player_GetInput();

	// Clear buffer to prepare for next frame
	Console_ClearRenderBuffer();

	// Get all objects to update their positions using SetRenderBuffer()
	player_Update();
	map_Update();
	//food_Update();

	// debug
	//Console_SetCursorPos(0, 60);
	//printf("eulerx: %f", EulerX);

	// Render with updated positions
	Console_SwapRenderBuffer();

	// Sleep
	Sleep(250);
}
