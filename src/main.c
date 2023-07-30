#include "init.h"
#include "game.h"
#include "snake.h"

int main() {

    if(!initWin()){
        printf("Failed to initalise SDL: %s\n", SDL_GetError());
    }
    else{
        printf("Initialised SDL\n");
    }

    SDL_Event e;
    bool quit = false;

    SDL_Texture **snakeTextures = mallocSnakeTex(); //allocates memory for the different snake textures
    
    /* SDL_Texture *defaultTexture = snakeTextures[KEY_PRESS_SURFACE_DEFAULT];
    SDL_Rect hitbox;
    hitbox.x = 0;
    hitbox.y = 0;
    SDL_QueryTexture(defaultTexture, NULL, NULL, &hitbox.w, &hitbox.h); */


    while(!quit){ //game loop needs to, move snake, check collisions, update game
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else{
                continue; //checkInputs(e);
            }
                    
        }

        SDL_RenderClear(renderer);
        createBackground();
        Snake *firstSeg = createSegment(0, 0, snakeTextures);
        SDL_RenderCopy(renderer, firstSeg->currentTexture, NULL, &firstSeg->hitbox);
        SDL_RenderPresent(renderer);
    }

    destroyWin();
    printf("Destroyed window and renderer\n");
    return 0;




}