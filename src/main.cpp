#include <raylib.h>

// Load files
#include "../include/game.hpp"   // <------------
#include "../include/screen.hpp" // <------------
#include "../include/menu.hpp"   // <------------
#include "../include/rule.hpp"   // <------------

int gameOn = 0; // <------------

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life by Lucas, Vanny, Hamza");
    SetTargetFPS(60);

    load_img_menu();  // <------------
    load_font_menu(); // <------------
    // Color
    Color darkGreen = Color{20, 160, 133, 255};
    SetTargetFPS(60);

    while (!WindowShouldClose() && (gameOn != -1))
    {
        DrawFPS(10, 10);
        BeginDrawing();
        ClearBackground(darkGreen);
        if (gameOn == 0) // <------------
        {
            gameOn = menu(); // <------------
        }
        else if (gameOn == 10) // <------------
        {
            draw_grid(); // <------------
        }
        else if (gameOn == 20) // <------------
        {
            gameOn = rule_state(); // <------------
        }
        EndDrawing();
    }

    unload_font_menu(); // <------------
    unload_img_menu();  // <------------

    CloseWindow();
    return 0;
}
