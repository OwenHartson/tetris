#include <iostream>
#include <string>
#include <raylib.h>

#include "src/game.h"
#include "src/colors.h"

using namespace std;

const int WINDOW_WIDTH {500};
const int WINDOW_HEIGHT{620};
double LAST_UPDATE_TIME{0};

bool EventTriggered(double);

int main(){
    Color darkBlue = { 44, 44, 127, 255 };
    Font font = Font();
    Game game;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raylib Tetris");
    SetTargetFPS(60);
    SetExitKey(49);

    while(!WindowShouldClose()){
        game.HandleInput();

        if(!game.paused){
            if(EventTriggered(0.2)){
                game.MoveBlockDown();
            }
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);

        if(game.gameOver){
            DrawTextEx(font, "GAME OVER", {320, 450}, 30, 2, WHITE);
        }

        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();

        if(game.paused){
            DrawTextEx(font, "PAUSED", {330, 450}, 30, 3, GREEN);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

bool EventTriggered(double interval){
    double currentTime = GetTime();

    if(currentTime - LAST_UPDATE_TIME >= interval){
        LAST_UPDATE_TIME = currentTime;
        return true;
    }

    return false;
}