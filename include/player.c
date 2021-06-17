#include <stdlib.h>
#include "player.h"
#include "node.h"
#include "raylib.h"

Player PlayerCreate(int x, int y) {
    Player thisPlayer;

    thisPlayer.node = NodeCreate();
    thisPlayer.node->pos.x = x;
    thisPlayer.node->pos.y = y;
    thisPlayer.node->target = thisPlayer.node->pos;
    thisPlayer.node->moveSnap = 0.2;

    NodeTextureSet(thisPlayer.node, NODE_GFX_PLAYER);

    return thisPlayer;
};

void PlayerUpdate(Player *self) {
    if (self->node->pos.x != self->node->target.x) {
        self->node->pos.x += ((self->node->target.x - self->node->pos.x) * self->node->moveSnap);
        if (abs((self->node->target.x - self->node->pos.x)) < .05) self->node->pos.x = self->node->target.x;
    }
    if (self->node->pos.y != self->node->target.y) {
        self->node->pos.y += ((self->node->target.y - self->node->pos.y) * self->node->moveSnap);
        if (abs((self->node->target.y - self->node->pos.y)) < .05) self->node->pos.y = self->node->target.y;
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