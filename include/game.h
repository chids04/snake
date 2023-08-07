#pragma once

#include "init.h"
#include "snake.h"

void createBackground();
void initGame(Snake *head);
void checkInputs(SDL_Event *, Snake *head);