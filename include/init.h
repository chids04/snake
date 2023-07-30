#pragma once

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;

typedef struct{
    SDL_Rect s;
    int colours[4];
} Square;

bool initWin();
void destroyWin();