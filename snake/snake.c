#include "global.h"
#include "StateMachine.h"

//int main(void)
//{
//	// Init console
//	Console_Init();
//	Random_Init();
//	Console_SetTitle("Snake Game");
//	Console_SetSquareFont();
//	Console_SetWindowedMode(50, 50, true);
//	Console_SetCursorVisibility(0);
//	bGameIsRunning = 1;
//
//	// Init player
//	initPlayer();
//
//	// Game loop
//	while (bGameIsRunning)
//	{
//		// Player
//		updatePlayer();
//
//		Sleep(100);
//	}
//
//	// Shutdown game
//	Console_CleanUp();
//
//	return 0;
//}



int main(void)
{

	// Game Initialization
	Console_Init();
	Console_SetTitle("Snake Game");
	Console_SetSquareFont();
	Console_SetWindowedMode(75, 75, true);
	Console_SetCursorVisibility(0);

	StateMachine_ChangeState(State_MainMenu); //calls the function that changes to current game state to "main menu"

	bGameIsRunning = 1;

	while (bGameIsRunning == 1)
	{
		StateMachine_StartFrame(); // perform checks if the current state is the same as the state that is supposed to be displayed, 
	}
	// Clear the Rendering Buffer
}