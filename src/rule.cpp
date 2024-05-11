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

void unload_img_rule()
{

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

    DrawTextEx(R_font1, "Origins", (Vector2){230, 120}, 40, 2, WHITE);
    DrawTextEx(R_font2, "The Game of Life is not your typical computer ", (Vector2){110, 200}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "game. It is a cellular automaton, and was ", (Vector2){110, 230}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, " invented by Cambridge mathematician John ", (Vector2){110, 260}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "Conway.This game became widely known when", (Vector2){110, 290}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "it was mentioned in an article published by", (Vector2){110, 320}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "Scientific American in 1970. It consists of a", (Vector2){110, 350}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "cells which, based on a few mathematical ", (Vector2){110, 380}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "rules, can live, die or multiply. Depending on  ", (Vector2){110, 410}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "the initial conditions, the cells form various", (Vector2){110, 440}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "patterns throughout the course of the game. ", (Vector2){110, 470}, 15, 1, LIGHTGRAY);

    // Rules
    DrawTextEx(R_font1, "Rules", (Vector2){560, 120}, 40, 2, WHITE);
    DrawTextEx(R_font2, "For a space that is populated", (Vector2){460, 200}, 20, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "Each cell with one or no neighbors dies,", (Vector2){450, 260}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, " as if by solitude.", (Vector2){450, 290}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "Each cell with four or more neighbors dies, as if by", (Vector2){450, 350}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "overpopulation.", (Vector2){450, 380}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "Each cell with two or three neighbors survives.", (Vector2){450, 440}, 15, 1, LIGHTGRAY);

    DrawTextEx(R_font2, "For a space that is empty or unpopulated", (Vector2){460, 500}, 20, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "Each cell with three neighbors becomes populated.", (Vector2){450, 560}, 15, 1, LIGHTGRAY);

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