#include <stdio.h>
#include "player.h"
#include "node.h"
#include "raylib.h"

Player PlayerCreate(void) {
    Player thisPlayer;

    thisPlayer.node = NodeCreate();
    thisPlayer.node->texture = LoadTexture("gfx/player.png");
    thisPlayer.node->moveSnap = 0.2;

    return thisPlayer;
};

void PlayerUpdate(Player *self) {
    if (self->node->pos.x != self->node->target.x) {
        self->node->pos.x += ((self->node->target.x - self->node->pos.x) * self->node->moveSnap);
    }
    if (self->node->pos.y != self->node->target.y) {
        self->node->pos.y += ((self->node->target.y - self->node->pos.y) * self->node->moveSnap);
    }
}

void PlayerDraw(Player *self) {
    NodeDraw(self->node);
};

int PlayerMove(Player *self, int direction) {
    switch (direction) {
        case 0: // Up
            self->node->target.y -= NODE_HEIGHT * NODE_PIXMULT;
            break;
        case 1: // Right
            self->node->target.x += NODE_WIDTH * NODE_PIXMULT;
            break;
        case 2: // Down
            self->node->target.y += NODE_HEIGHT * NODE_PIXMULT;
            break;
        case 3: // Left
            self->node->target.x -= NODE_WIDTH * NODE_PIXMULT;
            break;
        default:
            break;
    }

    return 1;
}