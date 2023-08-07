
#include "init.h"

enum KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

typedef struct Snake{
    SDL_Texture *currentTexture;
    SDL_Rect hitbox;
    struct Snake *next;
    struct Snake *previous;
    char direction;
    char buffDir;
} Snake;

extern SDL_Texture *snakeTextures[KEY_PRESS_SURFACE_TOTAL];

void initSnakeTextures();
Snake *createSegment(int x, int y);
void changeDirection(Snake *segment, SDL_Event *e);
void moveSnake(Snake *segment);
void updateSnake(Snake *segment);