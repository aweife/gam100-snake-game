#include "global.h"
#include "StateMachine.h"
#include "snake.h"
#include "StateMachine.h"


// runs the state "Game Over" aka the game over screen
void GameOver()
{
	State = 1;
	while (State)
	{
		displayGameOver();
		commandGameOver();
	}




}
// displays the game over 
void displayGameOver()
{
Console_ClearRenderBuffer();
	int x=GAME_WIDTH, y=GAME_HEIGHT;

	Console_SetRenderBuffer_String(3, y / 2 - 7, "  @@@@@@     @@@     @@@@@    @@@@@ @@@@@@@@");
	Console_SetRenderBuffer_String(3, y / 2 - 6, " @@   @@    @@ @@    @@ @@    @@ @@ @@      ");
	Console_SetRenderBuffer_String(3, y / 2 - 5, "@@         @@   @@   @@  @@  @@  @@ @@      ");
	Console_SetRenderBuffer_String(3, y / 2 - 4, "@@  @@@@  @@     @@  @@  @@  @@  @@ @@@@@@@@");
	Console_SetRenderBuffer_String(3, y / 2 - 3, "@@    @@  @@     @@  @@  @@  @@  @@ @@      ");
	Console_SetRenderBuffer_String(3, y / 2 - 2, " @@  @@  @@@@@@@@@@@ @@   @@@@   @@ @@      ");
	Console_SetRenderBuffer_String(3, y / 2 - 1, "  @@@@   @@       @@ @@    @@    @@ @@@@@@@@");



	Console_SetRenderBuffer_String(5, y / 2 + 1, "  @@@@@@   @@       @@  @@@@@@@@ @@@@@@@ ");
	Console_SetRenderBuffer_String(5, y / 2 + 2, " @@    @@   @@     @@   @@       @@   @@");
	Console_SetRenderBuffer_String(5, y / 2 + 3, "@@      @@  @@     @@   @@       @@  @@  ");
	Console_SetRenderBuffer_String(5, y / 2 + 4, "@@      @@   @@   @@    @@@@@@@@ @@@@@   ");
	Console_SetRenderBuffer_String(5, y / 2 + 5, "@@      @@   @@   @@    @@       @@ @@   ");
	Console_SetRenderBuffer_String(5, y / 2 + 6, " @@    @@     @@@@@     @@       @@  @@  ");
	Console_SetRenderBuffer_String(5, y / 2 + 7, "  @@@@@@       @@@      @@@@@@@@ @@   @@ ");

	Console_SetRenderBuffer_String(7, y -2, "PRESS ESCAPE TO RETURN TO MAIN MENU");
	Console_SetRenderBuffer_String(24, y, "OR");
	Console_SetRenderBuffer_String(15, y +2, "ENTER TO PLAY AGAIN");
	Console_SwapRenderBuffer();
}

void commandGameOver()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 1)
	{
		StateMachine_ChangeState(State_MainMenu);
		State = 0;

	}


	if (GetAsyncKeyState(VK_RETURN) & 1)
	{
		StateMachine_ChangeState(State_Game);
		State = 0;

	}

}