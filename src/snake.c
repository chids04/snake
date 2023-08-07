#include "snake.h"
#include <stdlib.h>

/*how to move snake:
check direction
move in that direction
check for keypresses
according to which keypress, change snake texture to reflect direction snake it to move in*/
SDL_Texture *snakeTextures[KEY_PRESS_SURFACE_TOTAL];

void initSnakeTextures(){

    snakeTextures[KEY_PRESS_SURFACE_DEFAULT] = IMG_LoadTexture(renderer, "../graphics/head_right.png");
    if(snakeTextures[KEY_PRESS_SURFACE_DEFAULT] == NULL){
        printf("failed to load default image: %s\n", SDL_GetError());
    }

    snakeTextures[KEY_PRESS_SURFACE_UP] = IMG_LoadTexture(renderer,"../graphics/head_up.png");
    if (snakeTextures[KEY_PRESS_SURFACE_UP] == NULL){
        printf("failed to load up image: %s\n", SDL_GetError());
    }

    snakeTextures[KEY_PRESS_SURFACE_DOWN] = IMG_LoadTexture(renderer,"../graphics/head_down.png");
    if (snakeTextures[KEY_PRESS_SURFACE_DOWN] == NULL){
        printf("failed to load down image: %s\n", SDL_GetError());
    }

    snakeTextures[KEY_PRESS_SURFACE_LEFT] = IMG_LoadTexture(renderer,"../graphics/head_left.png");
    if (snakeTextures[KEY_PRESS_SURFACE_LEFT] == NULL){
        printf("failed to load left image: %s\n", SDL_GetError());
    }

    snakeTextures[KEY_PRESS_SURFACE_RIGHT] = IMG_LoadTexture(renderer, "../graphics/head_right.png");
    if (snakeTextures[KEY_PRESS_SURFACE_RIGHT] == NULL){
        printf("failed to load right image: %s\n", SDL_GetError());
    }

}

Snake *createSegment(int x, int y){
    Snake *segment = malloc(sizeof(Snake));

    segment->currentTexture = snakeTextures[KEY_PRESS_SURFACE_DEFAULT];
    segment->hitbox.x = x;
    segment->hitbox.y = y;
    segment->next = NULL;
    segment->previous = NULL;
    segment->direction = 'E';
    segment->buffDir = '0';
    SDL_QueryTexture(segment->currentTexture, NULL, NULL, &segment->hitbox.w, &segment->hitbox.h);

    return segment;

}

void changeDirection(Snake *segment, SDL_Event *e){ //i buffer the directions so that the snake can only turn in a grid
    switch(e->key.keysym.sym){
        case SDLK_UP:
            segment->buffDir = 'N';
            break;
        
        case SDLK_RIGHT:
            segment->buffDir = 'E';
            break;
        
        case SDLK_DOWN:
            segment->buffDir = 'S';
            break;
        
        case SDLK_LEFT:
            segment->buffDir = 'W';
            break;
    }

}

void moveSnake(Snake *segment){
    switch(segment->direction){
        case 'N':
            segment->hitbox.y += -1;
            break;
        
        case 'E':
            segment->hitbox.x += 1;
            break;
        
        case 'S':
            segment->hitbox.y += 1;
            break;
        
        case 'W':
            segment->hitbox.x -= 1;
            break;
    }
}

void updateSnake(Snake *segment){

    if(segment->hitbox.x % 40 == 0 && segment->hitbox.y % 40 == 0){
        if(segment->buffDir != '0'){
            segment->direction = segment->buffDir;
            segment->buffDir = '0';
            switch(segment->direction){
                    case 'S':
                        segment->currentTexture = snakeTextures[KEY_PRESS_SURFACE_DOWN];
                        break;
                    
                    case 'E':
                        segment->currentTexture = snakeTextures[KEY_PRESS_SURFACE_RIGHT];
                        break;
                    
                    case 'N':
                        segment->currentTexture = snakeTextures[KEY_PRESS_SURFACE_UP];
                        break;

                    case 'W':
                        segment->currentTexture = snakeTextures[KEY_PRESS_SURFACE_LEFT];
                        break;
                }
        }
    }

    SDL_RenderCopy(renderer, segment->currentTexture, NULL, &segment->hitbox);
}