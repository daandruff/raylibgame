#include "include/raylib.h"
#include "include/player.h"
#include "include/room.h"

int main(void) {
    const int screenWidth = 960;
    const int screenHeight = 528;
    
    InitWindow(screenWidth, screenHeight, "Potpock and the four crusader rings 2");

    NodeTexturesInit();
    Room firstLevel = RoomCreate();
    Player playerOne = PlayerCreate(NODE_WIDTH * 3, NODE_HEIGHT * 3);
    
    SetTargetFPS(24);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(BLACK);
        RoomDraw(&firstLevel);
        PlayerDraw(&playerOne);
        
        EndDrawing();

        if (IsKeyPressed(KEY_UP)) PlayerMove(&playerOne, 0);
        if (IsKeyPressed(KEY_RIGHT)) PlayerMove(&playerOne, 1);
        if (IsKeyPressed(KEY_DOWN)) PlayerMove(&playerOne, 2);
        if (IsKeyPressed(KEY_LEFT)) PlayerMove(&playerOne, 3);

        if (IsGamepadAvailable(0)) {
            if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) PlayerMove(&playerOne, 0);
            if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) PlayerMove(&playerOne, 1);
            if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) PlayerMove(&playerOne, 2);
            if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) PlayerMove(&playerOne, 3);
        }

        PlayerUpdate(&playerOne);
    }

    CloseWindow();

    return 0;
}