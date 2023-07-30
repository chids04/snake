#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>

#include "init.h"
#include "defs.h"

SDL_Window *window;
SDL_Renderer *renderer;

bool initWin() { //create the window and the renderer.

    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) > 0){
        printf("Failed to initalise SDL: %s\n", SDL_GetError());
        success = false;
    }else{

        window = SDL_CreateWindow("image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(window==NULL){
            printf("Failed to intialise window: %s\n", SDL_GetError());
            success = false;
        }
        else{
            
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == NULL){
                printf("Renderer could not be intitilaised: %s\n", SDL_GetError());
                success = false;
            }
            else{
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
                    printf("SDL image could not be initalised: %s\n", SDL_GetError());
                    success = false;
                }
            }
        }
    }


    return success;
}


void destroyWin(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}