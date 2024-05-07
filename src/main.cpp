#include <raylib.h>
#include <string>
using namespace std;



// Load files
#include "game.hpp"
#include "screen.h"
#include "menu.h"
#include "menu_bis.h"

int framesCounter = 0;
bool gameOn = false;

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life by Lucas, Vanny, Hamza");
    SetTargetFPS(60);
    //  Logo
    Image logo = LoadImage("src/img/icon.png");
    SetWindowIcon(logo);

    //  Images path & Resize
    Image btn1 = LoadImage("src/img/button1.png");
    Image btn2 = LoadImage("src/img/button2.png");
    Image btn3 = LoadImage("src/img/button3.png");
    ImageResize(&btn1, 330, 330);
    ImageResize(&btn2, 330, 330);
    ImageResize(&btn3, 330, 330);

    // Images Texture
    Texture2D background = LoadTexture("src/img/background.png");
    Texture2D t_btn1 = LoadTextureFromImage(btn1);
    Texture2D t_btn2 = LoadTextureFromImage(btn2);
    Texture2D t_btn3 = LoadTextureFromImage(btn3);

    // Color
    Color darkGreen = Color{20, 160, 133, 255};

    // Ball ball = Ball();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        if (!gameOn)
        {
            DrawTexture(background, 0, 0, WHITE);
            DrawTexture(t_btn1, 100, 50, WHITE);
            DrawTexture(t_btn2, 100, 150, WHITE);
            DrawTexture(t_btn3, 100, 250, WHITE);

            menu();
            // gameOn = draw_menu(framesCounter);
            // draw_title();
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
