#include "raylib.h"
#include "node.h"

#define ROOM_MAX_HEIGHT 10
#define ROOM_MAX_WIDTH 20

typedef struct Room {
    Node *area[ROOM_MAX_HEIGHT][ROOM_MAX_WIDTH];
} Room;

Room RoomCreate(void);
void RoomDraw(Room *self);