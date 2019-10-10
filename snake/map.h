#pragma once

#include "global.h"

coordinates foodArray[3];
coordinates wallArray[32];

void map_Update();
void spawnFood();
void renderBoundary();
void renderFood();