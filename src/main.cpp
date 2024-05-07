#include <raylib.h>
#include "screen.h"
#include "menu.h"
#include "ball.h"

int framesCounter = 0;
bool gameOn = false;
// SetWindowIcon()
int main()
{
    Color darkGreen = Color{20, 160, 133, 255};
    Ball ball = Ball();
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        if (!gameOn)
        {
            gameOn = draw_menu(framesCounter);
            draw_title();
        }
        else
        {
            ball.Update();
            ball.Draw();
        }
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
