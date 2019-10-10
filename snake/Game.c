#include "global.h"
#include "StateMachine.h"



void Game()
{
	Console_ClearRenderBuffer();
	int y = 0, x = 0;
	Console_SetRenderBuffer_String(65, y++, "=========");
	Console_SetRenderBuffer_String(65, y++, "SCORE");
	Console_SetRenderBuffer_String(65, y++, "=========");

	while (x < 75)
	{
		Console_SetRenderBuffer_String(x++, y, "_");
		Console_SetRenderBuffer_String(x, 74, "_");
	}
	while (y < 75)
	{
		Console_SetRenderBuffer_String(0, ++y, "|");
		Console_SetRenderBuffer_String(74, y, "|");
	}
	Console_SwapRenderBuffer();

	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		StateMachine_ChangeState(State_GameOver);
	
}