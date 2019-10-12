#pragma once

#include "Random/Random.h"
#include "Console/Console.h"
#include "Clock/Clock.h"
#include "StateMachine.h"
#include <Windows.h>
#include <math.h>
#include <stdio.h>

#define GAME_WIDTH 50
#define GAME_HEIGHT 50
#define CONSOLE_HEIGHT 10

typedef struct {
	int x;
	int y;
} coordinates;

static int bGameIsRunning;

void initGame();
void runGame();
void recordScore(int score);