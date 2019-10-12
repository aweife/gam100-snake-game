#include "global.h"
#include "player.h"


// runs the state "game" will run the actual snake game itself
void Game()
{
	State = 1;
	// loops the various checks and updates that affect 
	while (State)
	{
		Console_ClearRenderBuffer();
		runGame();
		displayGame();
		Console_SwapRenderBuffer();
	}
}

// displays the score and time 
void displayGame()
{
	int y = GAME_HEIGHT + 1;
	// creates an array and stores the score inside allowing it to be rendered
	int SCORE[100];
	sprintf_s(SCORE, 100, "SCORE:%d", snakeBodyCount -1);
	Console_SetRenderBuffer_String(0, ++y+ 1, SCORE);

	// creates an array and stores the time elasped inside allowing it to be rendered
	int TIME[100];
	Time += ((Clock_GetElapsedTimeMs()+1) / (Clock_GetElapsedTimeMs() + 1) );
	sprintf_s(TIME, 100, "TIME: %d", Time/1000);
	Console_SetRenderBuffer_String(0, ++y +2, TIME);

	Console_SetRenderBuffer_String(0, ++y + 3, "Press ARROW KEYS to move");
	Console_SetRenderBuffer_String(0, ++y + 4, "Press ESC to quit the game");
}


// resets the game and moves to the GameOver state
void goGameOver(int score)
{
	State = 0;
	Time = 0;
	initGame();
	
	recordScore(score);
	StateMachine_ChangeState(State_GameOver);
}
