#include <raylib.h>
#include "string"

#include "../include/screen.hpp"
using namespace std;

//**** IMAGES
Texture2D R_background;

//**** FONT
Font R_font1;
Font R_font2;

//**** CLICK
Vector2 R_mousePoint = {0.0f, 0.0f};

//**** RECT
Rectangle rect_menu;

// Images
void load_img_rule()
{
    // Images Texture
    R_background = LoadTexture("assets/img/background4.png");
}

void unload_img_rule(){
    
    UnloadTexture(R_background);
}

// Font
void load_font_rule()
{
    R_font1 = LoadFontEx("assets/font/Television.ttf", 400, NULL, NULL);
    R_font2 = LoadFontEx("assets/font/Roboto-Black.ttf", 400, 0, 252);
}

void unload_font_rule()
{
    UnloadFont(R_font1);
    UnloadFont(R_font2);
}

int draw_rule()
{

    // Display images
    DrawTexture(R_background, 0, 0, WHITE);

    DrawRectangleRounded((Rectangle){100, 100, 330, 500}, 0.1f, 0, BLACK);
    DrawRectangleRoundedLines((Rectangle){100, 100, 330, 500}, 0.1f, 0, 2, WHITE);

    DrawTextEx(R_font1, "Rules", (Vector2){230, 120}, 40, 2, WHITE);
    DrawTextEx(R_font2, "Conway's Game of Life, introduced by John ", (Vector2){110, 200}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, " Horton Conway in 1970, is a zero-player", (Vector2){110, 230}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "cellular automaton game played on an infinite  ", (Vector2){110, 260}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "grid. Each cell is either alive or dead. In each  ", (Vector2){110, 290}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "generation, the fate of each cell is determined  ", (Vector2){110, 320}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "by its eight neighbors according to four simple ", (Vector2){110, 350}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "rules of birth, death, and survival. Despite its", (Vector2){110, 380}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, " simplicity, these rules give rise to complex ", (Vector2){110, 410}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "patterns and behaviors, making the Game of ", (Vector2){110, 440}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "Life a fascinating study in emergent ", (Vector2){110, 470}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "phenomena.", (Vector2){110, 500}, 15, 1, LIGHTGRAY);

    // back to menu

    rect_menu = {1070, 25, 100, 30};

    R_mousePoint = GetMousePosition();

    if (CheckCollisionPointRec(R_mousePoint, rect_menu))
    {
        DrawRectangleRounded((Rectangle){1070, 25, 102, 32}, 0.1f, 0, WHITE);
        DrawRectangleRoundedLines((Rectangle){1070, 25, 103, 32}, 0.1f, 0, 2, BLACK);
        DrawTextEx(R_font2, "MENU", (Vector2){1105, 32}, 15, 1, BLACK);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 0;
        }
    }
    else
    {
        DrawRectangleRounded((Rectangle){1070, 25, 100, 30}, 0.1f, 0, BLACK);
        DrawRectangleRoundedLines((Rectangle){1070, 25, 100, 30}, 0.1f, 0, 2, WHITE);
        DrawTextEx(R_font2, "MENU", (Vector2){1105, 32}, 15, 1, LIGHTGRAY);
    }
    return 20;
}