#include "raylib.h"
#include "SameGameModel.h"
#include "SameGameView.h"
#include <math.h>

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Tetris");

    SetTargetFPS(60);

    BoardGame tetris;
    view view(tetris);
    int numberOfMovesMade = 0;
    
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        
        view.display(numberOfMovesMade);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mouseData = GetMousePosition();
            if (tetris.getcolor(mouseData.y / 200, mouseData.x / 200) != color::Empty) {
                tetris.remove(mouseData.y / 200, mouseData.x / 200);
                numberOfMovesMade++;
            }
        }
        while (tetris.stillFloatingColors()) {
            tetris.stillFloatingColors();
        }


        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}