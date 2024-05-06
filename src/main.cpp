#include <raylib.h>
#include "menu.h"
#include "ball.h"

int framesCounter = 0;
bool gameOn = false;

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};
    const int screenWidth = 1200;
    const int screenHeight = 800;
    Ball ball = Ball();

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        if (!gameOn)
        {
            gameOn = draw_menu(framesCounter, msg);
        }
        else
        {
            ball.Update();
            ball.Draw();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
