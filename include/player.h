#include "raylib.h"
#include "node.h"

typedef struct Player {
    Node *node;
} Player;

Player PlayerCreate(void);
void PlayerUpdate(Player *self);
void PlayerDraw(Player *self);
int PlayerMove(Player *self, int direction);