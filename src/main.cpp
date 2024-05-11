#include <raylib.h>
#include <iostream>

// Load files
#include "../include/game.hpp"
#include "../include/screen.hpp"
#include "../include/menu.hpp"
#include "../include/rule.hpp"

void clear_cells();
void create_cells(); 
void start_cells();

int cellSize = 5;
int columns = 230;
int rows = 135;

bool grid[230][135];

// DrawRectangleLinesEx({1025, 750, 150, 35}, 5, RED);

int gameOn = 0;

//**** CLICK
Vector2 G_mousePoint = {0.0f, 0.0f};

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

//**** RECT
Rectangle rect_btn_hover1;
Rectangle rect_btn_hover2;
Rectangle rect_btn_hover3;
Rectangle rect_btn_hover4;
Rectangle rect_btn_hover5;
Rectangle rect_btn_hover6;

// Load images
void load_img_game()
{
    rect_op1 = LoadImage("assets/img/btn.png");
    rect_op2 = LoadImage("assets/img/btn.png");
    rect_op3 = LoadImage("assets/img/btn.png");
    rect_op4 = LoadImage("assets/img/btn.png");
    rect_op5 = LoadImage("assets/img/btn.png");
    rect_op6 = LoadImage("assets/img/btn.png");
    ImageResize(&rect_op1, 165, 85);
    ImageResize(&rect_op2, 165, 85);
    ImageResize(&rect_op3, 165, 85);
    ImageResize(&rect_op4, 165, 85);
    ImageResize(&rect_op5, 165, 85);
    ImageResize(&rect_op6, 165, 85);

    M_background = LoadTexture("assets/img/background3.png");
    t_rect_op1 = LoadTextureFromImage(rect_op1);
    t_rect_op2 = LoadTextureFromImage(rect_op2);
    t_rect_op3 = LoadTextureFromImage(rect_op3);
    t_rect_op4 = LoadTextureFromImage(rect_op4);
    t_rect_op5 = LoadTextureFromImage(rect_op5);
    t_rect_op6 = LoadTextureFromImage(rect_op6);
}

// UnLoad images
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

// Load font
void load_font_game()
{
    M_font1 = LoadFontEx("assets/font/Television.ttf", 400, 0, 252);
    M_font2 = LoadFontEx("assets/font/Anton-Regular.ttf", 300, 0, 252);
}

// Unload font
void unload_font_game()
{
    UnloadFont(M_font1);
    UnloadFont(M_font2);
}

// Design game
int design_game()
{

    DrawRectangle(25, 30, 1150, 675, LIGHTGRAY);

    G_mousePoint = GetMousePosition();

    // Button Next generation
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover1))
    {
        DrawTexture(t_rect_op1, 27, 692, WHITE);
        DrawTextEx(M_font2, "Next generation", (Vector2){50, 725}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 31;
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 25, 690, WHITE);
        DrawTextEx(M_font2, "Next generation", (Vector2){50, 725}, 15, 2, DARKGRAY);
    }

    // Button Start the automaton
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover2))
    {
        DrawTexture(t_rect_op2, 27, 727, WHITE);
        DrawTextEx(M_font2, "Start the automaton", (Vector2){45, 760}, 15, 2, DARKGRAY);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 32;
        }
    }
    else
    {
        DrawTexture(t_rect_op2, 25, 725, WHITE);
        DrawTextEx(M_font2, "Start the automaton", (Vector2){35, 760}, 15, 2, DARKGRAY);
    }

    // Button Blankk Grid
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover3))
    {
        DrawTexture(t_rect_op3, 512, 692, WHITE);
        DrawTextEx(M_font2, "Blank grid", (Vector2){555, 725}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            clear_cells();
        }
    }
    else
    {
        DrawTexture(t_rect_op3, 510, 690, WHITE);
        DrawTextEx(M_font2, "Blank grid", (Vector2){555, 725}, 15, 2, DARKGRAY);
    }

    // Button Randon path
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover4))
    {
        DrawTexture(t_rect_op4, 512, 727, WHITE);
        DrawTextEx(M_font2, "Random path", (Vector2){545, 760}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            create_cells();
        }
    }
    else
    {
        DrawTexture(t_rect_op4, 510, 725, WHITE);
        DrawTextEx(M_font2, "Random path", (Vector2){545, 760}, 15, 2, DARKGRAY);
    }

    // Button Game of Life
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover5))
    {
        DrawTexture(t_rect_op5, 1027, 692, WHITE);
        DrawTextEx(M_font2, "Game of Life", (Vector2){1065, 725}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 35;
        }
    }
    else
    {
        DrawTexture(t_rect_op5, 1025, 690, WHITE);
        DrawTextEx(M_font2, "Game of Life", (Vector2){1065, 725}, 15, 2, DARKGRAY);
    }

    // Button Quit
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover6))
    {
        DrawTexture(t_rect_op6, 1027, 727, WHITE);
        DrawTextEx(M_font2, " Quit", (Vector2){1100, 760}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 36;
        }
    }
    else
    {
        DrawTexture(t_rect_op6, 1025, 725, WHITE);
        DrawTextEx(M_font2, " Quit", (Vector2){1100, 760}, 15, 2, DARKGRAY);
    }

    return 37;
}

int draw_grid()
{
    for (int row = 0; row < rows; row++)
    {

        for (int column = 0; column < columns; column++)
        {
            if (grid[column][row])
            {
                DrawRectangle(25 + column * cellSize, 30 + row * cellSize, cellSize - 1, cellSize - 1, BLACK);
            }
            else
            {
                DrawRectangle(25 + column * cellSize, 30 + row * cellSize, cellSize - 1, cellSize - 1, WHITE);
            }
        }
    }

    return 0;
}

void clear_cells()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            grid[j][i] = false;
        }
    }
}

void create_cells()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            grid[column][row] = rand() % 2 == 0;
        }
    }
}

void start_cells()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            grid[column][row] = rand() % 2 == 0;
        }
    }
}


int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life");
    SetTargetFPS(60);


    create_cells();

    // Update button rectangles
    rect_btn_hover1 = {25, 715, 150, 35};
    rect_btn_hover2 = {25, 750, 150, 85};
    rect_btn_hover3 = {510, 715, 150, 35};
    rect_btn_hover4 = {510, 750, 150, 35};
    rect_btn_hover5 = {1025, 715, 150, 35};
    rect_btn_hover6 = {1025, 750, 150, 85};

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
