#ifndef NODE_H
#define NODE_H

#include "raylib.h"

#define NODE_PIXMULT 3
#define NODE_WIDTH 16
#define NODE_HEIGHT 16

#define NODE_GFX_NA LoadTexture("gfx/na.png")
#define NODE_GFX_BLOCK LoadTexture("gfx/block.png")
#define NODE_GFX_PLAYER LoadTexture("gfx/player.png")

typedef struct Node {
    int id;
    int active;
    Texture2D texture;
    Vector2 pos;
    Vector2 target;
    float moveSnap;
    int render;
} Node;

Node *NodeCreate(void);
int NodeGetNextFree(void);
void NodeSetPos(Node *self, int x, int y);
void NodeSetTarget(Node *self, int x, int y);
void NodeDraw(Node *self);
void NodeFree(Node *self);

#endif