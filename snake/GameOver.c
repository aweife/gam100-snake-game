#include "global.h"
#include "StateMachine.h"



void GameOver()
{
	Console_ClearRenderBuffer();
	int y = 10, x=4;
	Console_SetRenderBuffer_String(x, y++, "   @@@@@@@@@@           @@@         @@@@@        @@@@@  @@@@@@@@@@@");
	Console_SetRenderBuffer_String(x, y++, "  @@@@     @@@@        @@@@@        @@@@@@      @@@@@@  @@@@@@@@@@@");
	Console_SetRenderBuffer_String(x, y++, " @@@         @@@      @@@ @@@       @@@ @@      @@ @@@  @@@        ");
	Console_SetRenderBuffer_String(x, y++, "@@@@                 @@@   @@@      @@@  @@@   @@@ @@@  @@@        ");
	Console_SetRenderBuffer_String(x, y++, "@@@@     @@@@@@@    @@@     @@@     @@@   @@@ @@@  @@@  @@@@@@@@@@@");
	Console_SetRenderBuffer_String(x, y++, " @@@@        @@@   @@@@@@@@@@@@@    @@@    @@@@@   @@@  @@@        ");
	Console_SetRenderBuffer_String(x, y++, " @@@@        @@@  @@@@@@@@@@@@@@@   @@@    @@@@@   @@@  @@@        ");
	Console_SetRenderBuffer_String(x, y++, "  @@@@     @@@@  @@@           @@@  @@@    @@@@@   @@@  @@@@@@@@@@@");
	Console_SetRenderBuffer_String(x, y++, "    @@@@@@@@@@  @@@             @@@ @@@     @@@    @@@  @@@@@@@@@@@");

	Console_SetRenderBuffer_String(x, y++ +2, "   @@@@@@@@@@     @@@        @@@     @@@@@@@@@@@@     @@@@@@@@@@@@ ");
	Console_SetRenderBuffer_String(x, y++ +2, "  @@@@    @@@@    @@@        @@@     @@@@@@@@@@@@     @@@@    @@@@@");
	Console_SetRenderBuffer_String(x, y++ +2, " @@@@      @@@@   @@@        @@@     @@@              @@@@    @@@@@");
	Console_SetRenderBuffer_String(x, y++ +2, "@@@@        @@@@   @@@      @@@      @@@              @@@@@@@@@@@@ ");
	Console_SetRenderBuffer_String(x, y++ +2, "@@@@        @@@@   @@@      @@@      @@@@@@@@@@@@     @@@@@@@@@@   ");
	Console_SetRenderBuffer_String(x, y++ +2, "@@@@        @@@@    @@@    @@@       @@@              @@@@@@@@@@   ");
	Console_SetRenderBuffer_String(x, y++ +2, " @@@@      @@@@      @@@@@@@@        @@@              @@@     @@@@ ");
	Console_SetRenderBuffer_String(x, y++ +2, "  @@@@    @@@@        @@@@@@         @@@@@@@@@@@@     @@@      @@@ ");
	Console_SetRenderBuffer_String(x, y++ +2, "   @@@@@@@@@           @@@@          @@@@@@@@@@@@     @@@       @@@");
	Console_SetRenderBuffer_String(20, y + 22, "PRESS ESCAPE TO RETURN TO MAIN MENU");
	Console_SwapRenderBuffer();

	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		StateMachine_ChangeState(State_MainMenu);


}