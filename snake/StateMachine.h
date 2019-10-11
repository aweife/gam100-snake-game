#pragma once

static int Time;
static int State;

typedef enum Gamestate
{
	State_Default,
	State_MainMenu,
	State_Game,
	State_GameOver
} GameState;

void StateMachine_ChangeState(GameState newState);
void StateMachine_StartFrame();
void displayMain();
void commandMain();
void displayGame();
void commandGame();
void displayGameOver();
void commandGameOver();
void goGameOver();
