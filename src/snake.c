#include "snake.h"
#include <stdlib.h>

/* SDL_Texture *snakeTextures[KEY_PRESS_SURFACE_TOTAL];

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

} */

Snake *createSegment(int x, int y, SDL_Texture **snakeTextures){
    Snake *segment = malloc(sizeof(Snake));

    segment->currentTexture = snakeTextures[KEY_PRESS_SURFACE_DEFAULT];
    segment->hitbox.x = x;
    segment->hitbox.y = y;
    segment->next = NULL;
    segment->previous = NULL;
    SDL_QueryTexture(segment->currentTexture, NULL, NULL, &segment->hitbox.w, &segment->hitbox.h);

    return segment;

}

SDL_Texture **mallocSnakeTex(){

    SDL_Texture **snakeTextures = malloc(KEY_PRESS_SURFACE_TOTAL*sizeof(SDL_Texture*));

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

    return snakeTextures;
}