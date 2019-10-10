#include "global.h"
#include "StateMachine.h"


void MainMenu()
{
	Console_ClearRenderBuffer();
	int y = 10;
	Console_SetRenderBuffer_String(26, y++-5, "Welcome to the game of");                                                               
	Console_SetRenderBuffer_String(2, ++y, "   @@@@@     @@@       @@@         @@         @@@      @@@  @@@@@@@@@@");
	Console_SetRenderBuffer_String(2, ++y, " @@@@@@@@    @@@       @@@        @@@@        @@@     @@@   @@@@@@@@@@");
	Console_SetRenderBuffer_String(2, ++y, "@@@    @@@   @@@@      @@@       @@@@@@       @@@   @@@     @@@       ");
	Console_SetRenderBuffer_String(2, ++y, "@@@@         @@@@@     @@@      @@@  @@@      @@@  @@@      @@@       ");
	Console_SetRenderBuffer_String(2, ++y, "  @@@@@@@    @@@  @@@  @@@     @@@    @@@     @@@@@@@       @@@@@@@@@@");
	Console_SetRenderBuffer_String(2, ++y, "       @@@   @@@   @@@ @@@    @@@@@@@@@@@@    @@@  @@@      @@@       ");
	Console_SetRenderBuffer_String(2, ++y, "@@@     @@@  @@@    @@@@@@   @@@@@@@@@@@@@@   @@@    @@@    @@@       ");
	Console_SetRenderBuffer_String(2, ++y, "@@@@@@@@@@   @@@     @@@@@  @@@          @@@  @@@     @@@   @@@@@@@@@@");
	Console_SetRenderBuffer_String(2, ++y, "  @@@@@      @@@       @@@ @@@            @@@ @@@      @@@  @@@@@@@@@@");
	Console_SetRenderBuffer_String(28, y+30, "PRESS ENTER TO PLAY");
	Console_SwapRenderBuffer();

	if (GetAsyncKeyState(VK_RETURN) & 1)
		StateMachine_ChangeState(State_Game);

	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		bGameIsRunning = 0;

}
