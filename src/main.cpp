#include <raylib.h>

// Load files
#include "../include/game.hpp"
#include "../include/screen.hpp"
#include "../include/menu.hpp" 
#include "../include/rule.hpp"   

int gameOn = 0; 

//**** FONT
Font M_font1;
Font M_font2;


//**** IMAGES
Texture2D M_background;

void load_img_game()
{

    // Images Texture
    M_background = LoadTexture("assets/img/background3.png");
   
}

void unload_img_game()
{
    UnloadTexture(M_background); 
}

void load_font_game()
{
    M_font1 = LoadFontEx("assets/font/Television.ttf", 400, 0, 252);
    M_font2 = LoadFontEx("assets/font/Roboto-Black.ttf", 400, 0, 252);
}

void unload_font_game()
{
    UnloadFont(M_font1);
    UnloadFont(M_font2);
}

void design_game() {
    DrawRectangle(25, 30, 1150, 675, LIGHTGRAY);   
}


int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life");
    SetTargetFPS(60);

   
    DrawTextEx(M_font1, "Next generation", (Vector2){50, 600}, 25, 2, DARKGRAY);
     
    DrawTextEx(M_font1, "Start the automaton", (Vector2){50, 600}, 25, 2, DARKGRAY);
     
    DrawTextEx(M_font1, "Blank grid", (Vector2){100, 600}, 25, 2, DARKGRAY);
     
    DrawTextEx(M_font1, "Random path", (Vector2){150, 600}, 25, 2, DARKGRAY);
     
    DrawTextEx(M_font1, "Game of Life", (Vector2){200, 600}, 25, 2, DARKGRAY);
     
    DrawTextEx(M_font1, " Quit", (Vector2){250, 600}, 25, 2, DARKGRAY);
    
    
    // Menu
    load_img_menu();
    load_font_menu();

    // Game 
    load_img_game();
    load_font_game();

    // Rule
    load_font_rule();
    load_img_rule();


    // Color
    Color darkGreen = Color{20, 160, 133, 255};
    SetTargetFPS(60);

    while (!WindowShouldClose() && (gameOn != -1))
    {
        DrawFPS(10, 10);
        BeginDrawing();
        ClearBackground(darkGreen);
        if (gameOn == 0) 
        {
            gameOn = menu(); 
        }
        else if (gameOn == 10) 
        {
            DrawTexture(M_background, 0, 0, WHITE);
            design_game();
            draw_grid(); 
            DrawRectangleLinesEx({25, 30, 1150, 675}, 5, BLACK);

        }
        else if (gameOn == 20) 
        {
            gameOn = draw_rule(); 
        }
        EndDrawing();
    }

    // Menu
    unload_font_menu();
    unload_img_menu();

        // Game 
    unload_img_game();
    unload_font_game();

    // Rule
    unload_font_rule(); 
    unload_img_rule();

    CloseWindow();
    return 0;
}
