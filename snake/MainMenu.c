#include "global.h"


// runs the state "MainMenu" aka the main menu screen
void MainMenu()
{
	State = 1;
	while (State)
	{
	displayMain();
	commandMain();
	}

}

// sets the text shown on the main menu
void displayMain()
{ 
	Console_ClearRenderBuffer();
	int x = GAME_WIDTH, y= GAME_HEIGHT;
	Console_SetRenderBuffer_String(14, (y/2 -10), "Welcome to the game of");                                                               
	Console_SetRenderBuffer_String(2, (y / 2 - 3), " @@@@  @@     @@      @      @@    @@ @@@@@@@");
	Console_SetRenderBuffer_String(2, (y / 2 - 2), "@@  @@ @@@    @@     @@@     @@   @@  @@     ");
	Console_SetRenderBuffer_String(2, (y/2-1),     "@@     @@ @   @@    @@ @@    @@  @@   @@     ");
	Console_SetRenderBuffer_String(2, y/2,         " @@@@  @@  @  @@   @@   @@   @@@@@    @@@@@@@");
	Console_SetRenderBuffer_String(2, (y / 2 + 1), "    @@ @@   @ @@   @@   @@   @@  @@   @@     ");
	Console_SetRenderBuffer_String(2, (y / 2 + 2), "@@  @@ @@    @@@  @@@@@@@@@  @@   @@  @@     ");
	Console_SetRenderBuffer_String(2, (y / 2 + 3), " @@@@  @@     @@ @@       @@ @@    @@ @@@@@@@");
	Console_SetRenderBuffer_String(15, y, "PRESS ENTER TO PLAY");
	Console_SetRenderBuffer_String(16, y+2, "PRESS ESC TO QUIT");
	Console_SwapRenderBuffer();
}

// input keys to trigger change in game state
void commandMain()
{
	// changes from main menu state to the actual game
	// The & 0x8000 is to ensure key only get pressed once
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		StateMachine_ChangeState(State_Game);
		State = 0;
		StateMachine_StartFrame();
	}

// causes the game to exit and the program to close
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{		
		exitGame();
		State = 0;

	}
}
