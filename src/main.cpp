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
Image rect_op1;
Image rect_op2;
Image rect_op3;
Image rect_op4;
Image rect_op5;
Image rect_op6;

Texture2D M_background;
Texture2D t_rect_op1;
Texture2D t_rect_op2;
Texture2D t_rect_op3;
Texture2D t_rect_op4;
Texture2D t_rect_op5;
Texture2D t_rect_op6;

void load_img_game()
{
    rect_op1= LoadImage("assets/img/btn.png");
    rect_op2= LoadImage("assets/img/btn.png");
    rect_op3= LoadImage("assets/img/btn.png");
    rect_op4= LoadImage("assets/img/btn.png");
    rect_op5= LoadImage("assets/img/btn.png");
    rect_op6= LoadImage("assets/img/btn.png");
    ImageResize(&rect_op1, 150, 85);
    ImageResize(&rect_op2, 150, 85);
    ImageResize(&rect_op3, 150, 85);
    ImageResize(&rect_op4, 150, 85);
    ImageResize(&rect_op5, 150, 85);
    ImageResize(&rect_op6, 150, 85);

    // Images Texture
    M_background = LoadTexture("assets/img/background3.png");
    t_rect_op1= LoadTextureFromImage( rect_op1);
    t_rect_op2= LoadTextureFromImage( rect_op2);
    t_rect_op3= LoadTextureFromImage( rect_op3);
    t_rect_op4= LoadTextureFromImage( rect_op4);
    t_rect_op5= LoadTextureFromImage( rect_op5);
    t_rect_op6= LoadTextureFromImage( rect_op6);   
}

void unload_img_game()
{
    UnloadImage(rect_op1);
    UnloadImage(rect_op2);
    UnloadImage(rect_op3);
    UnloadImage(rect_op4);
    UnloadImage(rect_op5);
    UnloadImage(rect_op6);

    UnloadTexture(M_background); 
    UnloadTexture(t_rect_op1);
    UnloadTexture(t_rect_op2);
    UnloadTexture(t_rect_op3);
    UnloadTexture(t_rect_op4);
    UnloadTexture(t_rect_op5);
    UnloadTexture(t_rect_op6);
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

    DrawTexture(t_rect_op1, 25, 690, WHITE);
    DrawTexture(t_rect_op2, 25, 725, WHITE);
    DrawTexture(t_rect_op3, 500, 690, WHITE);
    DrawTexture(t_rect_op4, 500, 725, WHITE);
    DrawTexture(t_rect_op5, 1025, 690, WHITE);
    DrawTexture(t_rect_op6, 1025, 725, WHITE);

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
            draw_grid(); 
            DrawRectangleLinesEx({25, 30, 1150, 675}, 5, BLACK);
            design_game();

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
