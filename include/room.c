#include "room.h"

Room RoomCreate(void) {
    Room thisRoom;

    for (int row = 0; row < ROOM_MAX_HEIGHT; row++) {
        for (int col = 0; col < ROOM_MAX_WIDTH; col++) {
            thisRoom.area[row][col] = NodeCreate();
            NodeSetPos(thisRoom.area[row][col], col * NODE_WIDTH * NODE_PIXMULT, row * NODE_HEIGHT * NODE_PIXMULT);
        }
    }

    return thisRoom;
};

void RoomDraw(Room *self) {
    for (int row = 0; row < ROOM_MAX_HEIGHT; row++) {
        for (int col = 0; col < ROOM_MAX_WIDTH; col++) {
            NodeDraw(self->area[row][col]);
        }
    }
}