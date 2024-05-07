#include <raylib.h>
#include <string>
using namespace std;  

// Load files
#include "screen.h"
#include "menu.h"


int main()
{
   InitWindow(screenWidth, screenHeight, "Game of Life");
    SetTargetFPS(60);

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


    while (!WindowShouldClose())
    {
        BeginDrawing();       
        ClearBackground(darkGreen);

        // Display Images textures
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(t_btn1, 100, 50, WHITE); 
        DrawTexture(t_btn2, 100, 150, WHITE); 
        DrawTexture(t_btn3, 100, 250, WHITE);      


        menu();
        EndDrawing();
    }

    // Unload images & texture
    UnloadTexture(background );
    UnloadImage(btn1);
    UnloadImage(btn2);
    UnloadImage(btn3);   

    CloseWindow();
    return 0;
}