#include "room.h"

Room RoomCreate(void) {
    Room thisRoom;

    for (int row = 0; row < ROOM_MAX_HEIGHT; row++) {
        for (int col = 0; col < ROOM_MAX_WIDTH; col++) {
            thisRoom.area[row][col] = NodeCreate();
            NodeSetPos(thisRoom.area[row][col], col * NODE_WIDTH * NODE_PIXMULT, row * NODE_HEIGHT * NODE_PIXMULT);

            if (row == 0 || row == (ROOM_MAX_HEIGHT - 1) || col == 0 || col == (ROOM_MAX_WIDTH - 1)) {
                NodeTextureSet(thisRoom.area[row][col], NODE_GFX_BLOCK);
            } else {
                thisRoom.area[row][col]->render = 0;
            }
        }
    }

    return thisRoom;
};

void RoomDraw(Room *self) {
    for (int row = 0; row < ROOM_MAX_HEIGHT; row++) {
        for (int col = 0; col < ROOM_MAX_WIDTH; col++) {
            if(self->area[row][col]->render == 1) NodeDraw(self->area[row][col]);
        }
    }
}