gcc main.c include/player.c include/node.c include/room.c -o game.exe -Wall -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
start game.exe