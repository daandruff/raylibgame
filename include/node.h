#ifndef NODE_H
#define NODE_H

#include "raylib.h"

#define NODE_PIXMULT 3
#define NODE_WIDTH 16
#define NODE_HEIGHT 16

typedef struct Node {
    int id;
    int active;
    Texture2D texture;
    Vector2 pos;
    Vector2 target;
    float moveSnap;
} Node;

Node *NodeCreate(void);
int NodeGetNextFree(void);
void NodeSetPos(Node *self, int x, int y);
void NodeSetTarget(Node *self, int x, int y);
void NodeDraw(Node *self);
void NodeFree(Node *self);

#endif