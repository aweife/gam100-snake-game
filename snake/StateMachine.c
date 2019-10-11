#include "StateMachine.h"



static GameState CurrentState = State_Default;
static GameState RequestedState = State_Default;

void StateMachine_ChangeState(GameState newState)
{
	RequestedState = newState;
}

void StateMachine_StartFrame()
{
	//if (CurrentState != RequestedState) // checks to see if game is changing to a different state, if same state nothing needs to be done

		switch (RequestedState) 
		{
		case State_MainMenu: MainMenu() ; break; 
		case State_Game: Game(); break; 
		case State_GameOver: GameOver() ; break;
		default: break;
		}

}
