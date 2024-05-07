#include <raylib.h>
#include "screen.h"
#include "menu.h"
#include "ball.h"
#include "game.hpp"

int framesCounter = 0;
bool gameOn = false;

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};
    // Ball ball = Ball();
    InitWindow(screenWidth, screenHeight, "Game of Life by Lucas, Vanny, Hamza");
    SetTargetFPS(60);
    Image logo = LoadImage("src/img/icon.png");
    SetWindowIcon(logo);

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
        // ball.Update();
        // ball.Draw();
        draw_grid();
    }
    DrawFPS(10, 10);
    EndDrawing();
}

CloseWindow();
return 0;
}
