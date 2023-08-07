#include "game.h"


int main() {

    if(!initWin()){
        printf("Failed to initalise SDL: %s\n", SDL_GetError());
    }
    else{
        printf("Initialised SDL\n");
    }

    SDL_Event e;

    initSnakeTextures();
    Snake* head = createSegment(0, 0);
    
    bool quit = false;

    while(!quit){ //game loop needs to, move snake, check collisions, update game
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else{
                if(e.type == SDL_KEYDOWN){
                    checkInputs(&e, head);
                }
                
            }
                    
        }

        SDL_RenderClear(renderer);
        createBackground();
        moveSnake(head);
        updateSnake(head);
        //SDL_RenderCopy(renderer, head->currentTexture, NULL, &head->hitbox);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    destroyWin();
    printf("Destroyed window and renderer\n");
    return 0;




}