#include <raylib.h>
#include <string>
using namespace std;

// Load files
#include "game.hpp"
#include "screen.h"
#include "menu.h"

int framesCounter = 0;
bool gameOn = false;

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life by Lucas, Vanny, Hamza");
    SetTargetFPS(60);

    load_img_menu();
    load_font_menu();
    // Color&
    Color darkGreen = Color{20, 160, 133, 255};
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        DrawFPS(10, 10);
        BeginDrawing();
        ClearBackground(darkGreen);
        if (!gameOn)
        {

            gameOn = menu();
            // gameOn = draw_menu(framesCounter);
            // draw_title();
        }
        else
        {

            draw_grid();
        }

        EndDrawing();
    }

    unload_font_menu();
    unload_img_menu();

    CloseWindow();
    return 0;
}
