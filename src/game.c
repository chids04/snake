#include "game.h"
#include "snake.h"
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

void initGame(){
    
}
/* void checkInputs(SDL_Event e){
    if(e.type == SDL_KEYDOWN){
        switch(e.key.keysym.sym){

            case SDLK_UP:
                changeDir('N');

            case SDLK_DOWN:
                changeDir('S');

            case SDLK_LEFT:
                changeDir('W');

            case SDLK_RIGHT:
                changeDir('E');
        }
    }
} */