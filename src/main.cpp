#include <raylib.h>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Load files
#include "../include/screen.hpp"
#include "../include/menu.hpp"
#include "../include/option.hpp"

void clear_cells();
void create_cells();
void update_grid();
void paused_game();
int surrounded_cells(int row, int col);
void save_grid();
void load_grid();

int cellSize = 5;
int columns = 230;
int rows = 135;
bool grid[230][135];

// Option pause
bool gamePaused = true;

// Count new generation
int updateCount = 0;

// Slow display grid
// Clock updateClock = { 0 };

int gameOn = 0;

//**** CLICK
Vector2 G_mousePoint = {0.0f, 0.0f};

//**** FONT
Font M_font1;
Font M_font2;

//**** IMAGES
Image rect_op1;
Image next_g;
Image close_m;

Texture2D M_background;
Texture2D t_rect_op1;
Texture2D t_next_g;
Texture2D t_close_m;

//**** RECT
Rectangle rect_btn_hover1;
Rectangle rect_btn_hover2;
Rectangle rect_btn_hover3;
Rectangle rect_btn_hover4;
Rectangle rect_btn_hover5;
Rectangle rect_btn_hover6;
Rectangle rect_btn_hover7;
Rectangle rect_btn_hover8;
Rectangle rect_btn_hover9;
Rectangle rect_btn_hover10;
Rectangle rect_close;

//**** DRAW CELLS
bool draw_cell = false;
bool erase_cell = false;

// Load images
void load_img_game()
{
    rect_op1 = LoadImage("assets/img/btn.png");
    ImageResize(&rect_op1, 165, 85);
    next_g = LoadImage("assets/img/generation.png");
    ImageResize(&next_g, 20, 20);

    close_m = LoadImage("assets/img/close.png");
    ImageResize(&close_m, 25, 25);

    M_background = LoadTexture("assets/img/background3.png");
    t_rect_op1 = LoadTextureFromImage(rect_op1);
    t_next_g = LoadTextureFromImage(next_g);
    t_close_m = LoadTextureFromImage(close_m);
}

// UnLoad images
void unload_img_game()
{
    UnloadImage(rect_op1);
    UnloadImage(next_g);

    UnloadTexture(M_background);
    UnloadTexture(t_rect_op1);
    UnloadTexture(t_next_g);
    UnloadTexture(t_close_m);
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

    DrawTextEx(M_font2, "Game of Life", (Vector2){550, 4}, 30, 2, DARKGRAY);
    DrawText(TextFormat("New generations : %d", updateCount), 50, 8, 20, BLACK);

    // Logo next generation
    DrawTexture(t_next_g, 25, 8, WHITE);

    DrawRectangle(25, 30, 1150, 675, LIGHTGRAY);

    G_mousePoint = GetMousePosition();

    // Back to menu
    rect_close = {1150, 2, 25, 25};
    if (CheckCollisionPointRec(G_mousePoint, rect_close))
    {
        DrawTexture(t_close_m, 1151, 3, WHITE);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 0;
        }
    }
    else
    {
        DrawTexture(t_close_m, 1150, 2, WHITE);
    }

    // 1. Random
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover1))
    {
        DrawTexture(t_rect_op1, 27, 692, WHITE);
        DrawTextEx(M_font2, "Random", (Vector2){80, 725}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            create_cells();
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 25, 690, WHITE);
        DrawTextEx(M_font2, "Random", (Vector2){80, 725}, 15, 2, DARKGRAY);
    }

    // 2. Clear
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover2))
    {
        DrawTexture(t_rect_op1, 27, 727, WHITE);
        DrawTextEx(M_font2, "Clear", (Vector2){90, 760}, 15, 2, DARKGRAY);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            clear_cells();
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 25, 725, WHITE);
        DrawTextEx(M_font2, "Clear", (Vector2){90, 760}, 15, 2, DARKGRAY);
    }

    // 3. Draw
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover3))
    {
        DrawTexture(t_rect_op1, 277, 692, WHITE);
        DrawTextEx(M_font2, "Draw", (Vector2){350, 725}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            gamePaused = true;
            draw_cell = !draw_cell;
            erase_cell = false;
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 275, 690, WHITE);
        DrawTextEx(M_font2, "Draw", (Vector2){350, 725}, 15, 2, DARKGRAY);
    }

    // 4. Erase
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover4))
    {
        DrawTexture(t_rect_op1, 277, 727, WHITE);
        DrawTextEx(M_font2, "Erase", (Vector2){350, 760}, 15, 2, DARKGRAY);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            gamePaused = true;
            erase_cell = !erase_cell;
            draw_cell = false;
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 275, 725, WHITE);
        DrawTextEx(M_font2, "Erase", (Vector2){350, 760}, 15, 2, DARKGRAY);
    }

    // 5. Stop
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover5))
    {
        DrawTexture(t_rect_op1, 512, 692, WHITE);
        DrawTextEx(M_font2, "Pause", (Vector2){585, 725}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            gamePaused = true;
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 510, 690, WHITE);
        DrawTextEx(M_font2, "Pause", (Vector2){585, 725}, 15, 2, DARKGRAY);
    }

    // 6. Play
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover6))
    {
        DrawTexture(t_rect_op1, 512, 727, WHITE);
        DrawTextEx(M_font2, "Play", (Vector2){585, 760}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            gamePaused = false;
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 510, 725, WHITE);
        DrawTextEx(M_font2, "Play", (Vector2){585, 760}, 15, 2, DARKGRAY);
    }

    // 7. Load
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover7))
    {
        DrawTexture(t_rect_op1, 762, 692, WHITE);
        DrawTextEx(M_font2, "Load", (Vector2){825, 725}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            gamePaused = true;
            load_grid();
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 760, 690, WHITE);
        DrawTextEx(M_font2, "Load", (Vector2){825, 725}, 15, 2, DARKGRAY);
    }

    // 8. Saved
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover8))
    {
        DrawTexture(t_rect_op1, 762, 727, WHITE);
        DrawTextEx(M_font2, "Saved", (Vector2){825, 760}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            gamePaused = true;
            save_grid();
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 760, 725, WHITE);
        DrawTextEx(M_font2, "Saved", (Vector2){825, 760}, 15, 2, DARKGRAY);
    }

    // 9. Speed
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover9))
    {
        DrawTexture(t_rect_op1, 1017, 692, WHITE);
        DrawTextEx(M_font2, "Speed", (Vector2){1075, 725}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            gamePaused = true;
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 1015, 690, WHITE);
        DrawTextEx(M_font2, "Speed", (Vector2){1075, 725}, 15, 2, DARKGRAY);
    }

    // 10. Choose pattern
    if (CheckCollisionPointRec(G_mousePoint, rect_btn_hover10))
    {
        DrawTexture(t_rect_op1, 1017, 727, WHITE);
        DrawTextEx(M_font2, "Choose pattern", (Vector2){1040, 760}, 15, 2, DARKGRAY);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 20;
        }
    }
    else
    {
        DrawTexture(t_rect_op1, 1015, 725, WHITE);
        DrawTextEx(M_font2, "Choose pattern", (Vector2){1040, 760}, 15, 2, DARKGRAY);
    }
    return 10;
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

void update_grid()
{

    bool new_grid[columns][rows];

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            new_grid[column][row] = grid[column][row];
        }
    }

    for (int row = 0; row < rows; row++)
    {

        for (int column = 0; column < columns; column++)
        {

            int neighbors = surrounded_cells(row, column);

            if (grid[column][row])
            {
                // 2 or 3 neighbors : cell is alive
                if (neighbors == 2 || neighbors == 3)
                {
                    new_grid[column][row] = true;
                }
                // More then 3 neighbors or less than 2 neighboors : Death of cells
                else
                {
                    new_grid[column][row] = false;
                }
            }

            else
            {
                // if 3 neighbors: birth cell
                if (neighbors == 3)
                {
                    new_grid[column][row] = true;
                }
                else
                {
                    new_grid[column][row] = false;
                }
            }
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            grid[column][row] = new_grid[column][row];
        }
    }
    updateCount++;
    printf("Nombre de mises à jour : %d\n", updateCount);
}

int surrounded_cells(int row, int col)
{
    int count = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {

            // Ignore current cell
            if (i == 0 && j == 0)
            {
                continue;
            }

            int neighborRow = row + i;
            int neighborCol = col + j;

            if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < columns)
            {
                // Add if cell alive
                if (grid[neighborCol][neighborRow])
                {
                    count++;
                }
            }
        }
    }

    return count;
}

void draw_cells()
{
    int column = (G_mousePoint.x - 25) / cellSize;
    int row = (G_mousePoint.y - 30) / cellSize;
    if (column >= 0 && column < columns && row >= 0 && row < rows)
    {
        grid[column][row] = true;
    }
}
void erase_cells()
{
    int column = (G_mousePoint.x - 25) / cellSize;
    int row = (G_mousePoint.y - 30) / cellSize;
    if (column >= 0 && column < columns && row >= 0 && row < rows)
    {
        grid[column][row] = false;
    }
}

void paused_game()
{
    gamePaused = !gamePaused;
}

void save_grid()
{
    nlohmann::json json_data;
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            json_data["grid"][row][column] = grid[column][row];
        }
    }
    std::ofstream file("config.json");
    file << json_data.dump(4);
}

void load_grid()
{
    std::ifstream file("config.json");
    json json_data;
    file >> json_data;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            grid[column][row] = json_data["grid"][row][column];
        }
    }
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life");
    SetTargetFPS(60);

    create_cells();

    // Update button rect
    rect_btn_hover1 = {25, 715, 165, 35};
    rect_btn_hover2 = {25, 750, 165, 35};
    rect_btn_hover3 = {275, 715, 165, 35};
    rect_btn_hover4 = {275, 750, 165, 35};
    rect_btn_hover5 = {510, 715, 165, 35};
    rect_btn_hover6 = {510, 750, 165, 35};
    rect_btn_hover7 = {760, 715, 165, 35};
    rect_btn_hover8 = {760, 750, 165, 35};
    rect_btn_hover9 = {1025, 715, 165, 35};
    rect_btn_hover10 = {1025, 750, 165, 35};

    // Menu
    load_img_menu();
    load_font_menu();

    // Game
    load_img_game();
    load_font_game();

    // option
    load_font_option();
    load_img_option();

    // Color
    Color darkGreen = Color{20, 160, 133, 255};
    SetTargetFPS(60);

    while (!WindowShouldClose() && (gameOn != -1))
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        if (gameOn == 0)
        {
            gameOn = menu();
        }
        else if (gameOn == 10)
        {

            if (!gamePaused)
            {
                DrawTexture(M_background, 0, 0, WHITE);
                gameOn = design_game();
                draw_grid();
                update_grid();
            }
            else
            {
                DrawTexture(M_background, 0, 0, WHITE);
                gameOn = design_game();
                draw_grid();
            }

            DrawRectangleLinesEx({25, 30, 1150, 675}, 5, BLACK);
            // DrawRectangleLinesEx({1150, 2, 25, 25}, 5, RED);

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && draw_cell)
            {
                draw_cells();
            }
            else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && erase_cell)
            {
                erase_cells();
            }
        }

        else if (gameOn == 20)
        {
            gameOn = draw_option();
        }
        EndDrawing();
    }

    // Menu
    unload_font_menu();
    unload_img_menu();

    // Game
    unload_img_game();
    unload_font_game();

    // option
    unload_font_option();
    unload_img_option();

    CloseWindow();
    return 0;
}
