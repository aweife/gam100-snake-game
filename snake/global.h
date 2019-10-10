#pragma once

#include "Random/Random.h"
#include "Console/Console.h"
#include "Clock/Clock.h"
#include <Windows.h>
#include <math.h>
#include <stdio.h>

#define GAME_WIDTH 50
#define GAME_HEIGHT 50
#define CONSOLE_HEIGHT 25

typedef struct {
	int x;
	int y;
} coordinates;

static int bGameIsRunning;