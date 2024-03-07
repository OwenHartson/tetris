#include <iostream>
#include <string>
#include <raylib.h>

#include "src/game.h"

using namespace std;

const int WINDOW_WIDTH {300};
const int WINDOW_HEIGHT{600};

int main(){
    Color darkBlue = { 44, 44, 127, 255 };

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raylib Tetris");
    SetTargetFPS(60);

    Game game;

    while(!WindowShouldClose()){
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}