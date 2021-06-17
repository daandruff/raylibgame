#include <stdio.h>
#include "raylib.h"
#include "node.h"

Node NodeContainer[1024];

Node *NodeCreate(void) {
    Node thisNode;
    
    thisNode.id = NodeGetNextFree();
    thisNode.active = 1;
    thisNode.texture = LoadTexture("gfx/block.png");
    thisNode.pos.x = 0;
    thisNode.pos.y = 0;
    thisNode.target = thisNode.pos;
    thisNode.moveSnap = 1;

    NodeContainer[thisNode.id] = thisNode;
    return &NodeContainer[thisNode.id];
};

int NodeGetNextFree(void) {
    int NodeContainerSize = (int)(sizeof(NodeContainer) / sizeof(Node));

    for (int i = 0; i < NodeContainerSize; i++) {
        if (NodeContainer[i].active != 1) return i;
    }

    return -1;
}

void NodeSetPos(Node *self, int x, int y) {
    self->pos.x = x;
    self->pos.y = y;
};

void NodeSetTarget(Node *self, int x, int y) {
    self->target.x = x;
    self->target.y = y;
};

void NodeDraw(Node *self) {
    Vector2 pixelPosition;
    pixelPosition.x = ((int)self->pos.x / NODE_PIXMULT) * NODE_PIXMULT;
    pixelPosition.y = ((int)self->pos.y / NODE_PIXMULT) * NODE_PIXMULT;

    DrawTextureEx(self->texture, pixelPosition, 0, NODE_PIXMULT, WHITE);
};

void NodeFree(Node *self) {
    NodeContainer[self->id].active = 0;
};