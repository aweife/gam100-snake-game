#pragma once

#include "global.h"

coordinates foodArray[3];
coordinates wallArray[2500];

// For tracking food
int foodCount;

// For tracking the walls
int wallCount;

void map_Init();
void map_Update();
void spawnFood(int index);
int checkWithWall(int x, int y);
void renderBoundary();
void renderFood();
void spawnWall(int offsetX, int offsetY, int sizeX, int sizeY);
void renderWall();