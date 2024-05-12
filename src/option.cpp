#include <raylib.h>
#include "string"

// Load Files
#include "../include/screen.hpp"
using namespace std;

//**** IMAGES
Image square1;
Image square2;
Image square3;
Image square4;
Image square5;
Image square6;
Image square7;
Image square8;
Texture2D R_background;
Texture2D t_square1;
Texture2D t_square2;
Texture2D t_square3;
Texture2D t_square4;
Texture2D t_square5;
Texture2D t_square6;
Texture2D t_square7;
Texture2D t_square8;

//**** FONT
Font R_font1;
Font R_font2;

//**** CLICK
Vector2 R_mousePoint = {0.0f, 0.0f};

//**** RECT
Rectangle rect_menu;
Rectangle pattern1_rect;
Rectangle pattern2_rect;
Rectangle pattern3_rect;
Rectangle pattern4_rect;
Rectangle pattern5_rect;

// Images
void load_img_option()
{
    square1 = LoadImage("assets/img/square1.png");
    square2 = LoadImage("assets/img/square2.png");
    square3 = LoadImage("assets/img/square3.png");
    square4 = LoadImage("assets/img/square4.png");
    square5 = LoadImage("assets/img/square5.png");
    square6 = LoadImage("assets/img/square6.png");
    square7 = LoadImage("assets/img/square7.png");
    square8 = LoadImage("assets/img/square8.png");

    // Images Texture
    R_background = LoadTexture("assets/img/background4.png");
    t_square1 = LoadTextureFromImage(square1);
    t_square2 = LoadTextureFromImage(square2);
    t_square3 = LoadTextureFromImage(square3);
    t_square4 = LoadTextureFromImage(square4);
    t_square5 = LoadTextureFromImage(square5);
    t_square6 = LoadTextureFromImage(square6);
    t_square7 = LoadTextureFromImage(square7);
    t_square8 = LoadTextureFromImage(square8);
}

void unload_img_option()
{

    UnloadImage(square1);
    UnloadImage(square2);
    UnloadImage(square3);
    UnloadImage(square4);
    UnloadImage(square5);
    UnloadImage(square6);
    UnloadImage(square7);
    UnloadImage(square8);

    UnloadTexture(R_background);
    UnloadTexture(t_square1);
    UnloadTexture(t_square2);
    UnloadTexture(t_square3);
    UnloadTexture(t_square4);
    UnloadTexture(t_square5);
    UnloadTexture(t_square6);
    UnloadTexture(t_square7);
    UnloadTexture(t_square8);
}

// Font
void load_font_option()
{
    R_font1 = LoadFontEx("assets/font/Television.ttf", 400, NULL, NULL);
    R_font2 = LoadFontEx("assets/font/Roboto-Black.ttf", 400, 0, 252);
}

void unload_font_option()
{
    UnloadFont(R_font1);
    UnloadFont(R_font2);
}

int draw_option()
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
    DrawTextEx(R_font2, "For a space that is populated", (Vector2){500, 200}, 22, 2, LIGHTGRAY);
    DrawTextEx(R_font2, "- Each cell with one or no neighbors dies,", (Vector2){500, 270}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, " as if by solitude.", (Vector2){500, 290}, 15, 1, LIGHTGRAY);

    DrawTextEx(R_font2, "- Each cell with four or more neighbors dies, as if by", (Vector2){500, 350}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, "overpopulation.", (Vector2){500, 370}, 15, 1, LIGHTGRAY);
    DrawTextEx(R_font2, " - Each cell with two or three neighbors survives.", (Vector2){500, 440}, 15, 1, LIGHTGRAY);

    DrawTextEx(R_font2, "For a space that is empty or unpopulated", (Vector2){500, 520}, 22, 2, LIGHTGRAY);
    DrawTextEx(R_font2, "- Each cell with three neighbors becomes populated.", (Vector2){500, 590}, 15, 1, LIGHTGRAY);

    // Images Option
    DrawTexture(t_square1, 900, 250, WHITE);
    DrawTexture(t_square2, 1050, 250, WHITE);
    DrawTexture(t_square3, 900, 340, WHITE);
    DrawTexture(t_square4, 1050, 340, WHITE);
    DrawTexture(t_square5, 900, 430, WHITE);
    DrawTexture(t_square6, 1050, 430, WHITE);
    DrawTexture(t_square7, 900, 555, WHITE);
    DrawTexture(t_square8, 1050, 555, WHITE);

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

    // Load from Patterns
    DrawRectangleRounded((Rectangle){100, 650, 1000, 125}, 0.1f, 0, BLACK);
    DrawRectangleRoundedLines((Rectangle){100, 650, 1000, 125}, 0.1f, 0, 2, WHITE);

    pattern1_rect = {145, 690, 120, 70};
    DrawRectangle(145, 690, 120, 70, BLUE);
    DrawTextEx(R_font2, "Pattern 1", (Vector2){170, 665}, 15, 1, LIGHTGRAY);

    pattern2_rect = {345, 690, 120, 70};
    DrawRectangle(345, 690, 120, 70, BLUE);
    DrawTextEx(R_font2, "Pattern 2", (Vector2){370, 665}, 15, 1, LIGHTGRAY);

    pattern3_rect = {545, 690, 120, 70};
    DrawRectangle(545, 690, 120, 70, BLUE);
    DrawTextEx(R_font2, "Pattern 3", (Vector2){570, 665}, 15, 1, LIGHTGRAY);

    pattern4_rect = {745, 690, 120, 70};
    DrawRectangle(745, 690, 120, 70, BLUE);
    DrawTextEx(R_font2, "Pattern 4", (Vector2){770, 665}, 15, 1, LIGHTGRAY);

    pattern5_rect = {945, 690, 120, 70};
    DrawRectangle(945, 690, 120, 70, BLUE);
    DrawTextEx(R_font2, "Pattern 5", (Vector2){970, 665}, 15, 1, LIGHTGRAY);

    if (CheckCollisionPointRec(R_mousePoint, pattern1_rect))
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 11;
        }
    }
    else if (CheckCollisionPointRec(R_mousePoint, pattern2_rect))
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 12;
        }
    }
    return 20;
}