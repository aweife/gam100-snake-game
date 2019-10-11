#include "global.h"
#include "StateMachine.h"
#include "snake.h"
#include "map.h"
#include "player.h"
#include "Clock/Clock.h"
#include "StateMachine.h"


// runs the state "game" will run the actual snake game itself
void Game()
{
	State = 1;
	// loops the various checks and updates that affect 
	while (State)
	{
		commandGame();
		Console_ClearRenderBuffer();
		runGame();
		checkCollision();
		displayGame();
		Console_SwapRenderBuffer();
	}

	
}

// displays the score and time 
void displayGame()
{
	int y = GAME_HEIGHT;
	// creates an array and stores the score inside allowing it to be rendered
	int SCORE[100];
	sprintf_s(SCORE, 100, "SCORE:%d", snakeBodyCount -1);
	Console_SetRenderBuffer_String(0, ++y+ 1, SCORE);

	// creates an array and stores the time elasped inside allowing it to be rendered
	int TIME[100];
	Time += ((Clock_GetElapsedTimeMs()+1) / (Clock_GetElapsedTimeMs() + 1) );
	sprintf_s(TIME, 100, "TIME: %d", Time/1000);
	Console_SetRenderBuffer_String(0, ++y +2, TIME);
}

// input keys to trigger change in game state
void commandGame()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		goGameOver();
}

// resets the game and moves to the GameOver state
void goGameOver()
{
	State = 0;
	Time = 0;
	initGame();
	StateMachine_ChangeState(State_GameOver);

}
