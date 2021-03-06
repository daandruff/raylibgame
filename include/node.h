#ifndef NODE_H
#define NODE_H

#include "raylib.h"

#define NODE_PIXMULT 3
#define NODE_WIDTH 16
#define NODE_HEIGHT 16

#define NODE_GFX_NA 0
#define NODE_GFX_BLOCK 1
#define NODE_GFX_PLAYER 2
#define NODE_GFX_TILE_A 3
#define NODE_GFX_TILE_B 4

typedef struct Node {
    int id;
    int active;
    Texture2D *texture;
    Vector2 pos;
    Vector2 target;
    float moveSnap;
    int render;
} Node;

void NodeTexturesInit(void);
Node *NodeCreate(void);
void NodeTextureSet(Node *self, int texture);
int NodeGetNextFree(void);
void NodeSetPos(Node *self, int x, int y);
void NodeSetTarget(Node *self, int x, int y);
void NodeDraw(Node *self);
void NodeFree(Node *self);

#endif