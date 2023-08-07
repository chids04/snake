#include "game.h"
#include "defs.h"


void createBackground(){
    Square s1;
    Square s2;
    int count = 0;

    s1.colours[0] = 170;
    s1.colours[1] = 215;
    s1.colours[2] = 80;
    s1.colours[3] = 255;
    
    s2.colours[0] = 162;
    s2.colours[1] = 209;
    s2.colours[2] = 72;
    s2.colours[3] = 255;

    s1.s.w = SCREEN_WIDTH / 16;
    s1.s.h = SCREEN_HEIGHT / 12;

    s2.s.w = SCREEN_WIDTH / 16;
    s2.s.h = SCREEN_HEIGHT / 12;

    s1.s.x = 0;
    s1.s.y = 0;

    s2.s.x = 0;
    s2.s.y = 0;

    for(int i = 0; i < 96; i++){
        if(count == SCREEN_WIDTH){

            Square temp;
            temp = s1;
            s1 = s2;
            s2 = temp;

            count = 0;
            s1.s.y = s1.s.y + (SCREEN_HEIGHT / 12);
            s2.s.y = s2.s.y + (SCREEN_HEIGHT / 12);

            s1.s.x = count;
            SDL_SetRenderDrawColor(renderer, s1.colours[0], s1.colours[1], s1.colours[2], s1.colours[3]);
            SDL_RenderFillRect(renderer, &s1.s);
            count+=SCREEN_WIDTH / 16;

            s2.s.x = count;
            SDL_SetRenderDrawColor(renderer, s2.colours[0], s2.colours[1], s2.colours[2], s2.colours[3]);
            SDL_RenderFillRect(renderer, &s2.s);
            count+=SCREEN_WIDTH/16;

        }
        else{
            s1.s.x = count;
            SDL_SetRenderDrawColor(renderer, s1.colours[0], s1.colours[1], s1.colours[2], s1.colours[3]);
            SDL_RenderFillRect(renderer, &s1.s);
            count+=SCREEN_WIDTH / 16;

            s2.s.x = count;
            SDL_SetRenderDrawColor(renderer, s2.colours[0], s2.colours[1], s2.colours[2], s2.colours[3]);
            SDL_RenderFillRect(renderer, &s2.s);
            count+=SCREEN_WIDTH/16;

        }
    }
}

void initGame(Snake *head){

    initSnakeTextures();
    SDL_RenderClear(renderer);
    createBackground();
    SDL_RenderCopy(renderer, head->currentTexture, NULL, &head->hitbox);
    SDL_RenderPresent(renderer);
}

void checkInputs(SDL_Event *e, Snake *head){ //might add extra options like lasers to the snake etc
    changeDirection(head, e);
}