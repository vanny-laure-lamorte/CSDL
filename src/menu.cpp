#include <raylib.h>
#include <iostream>
#include "menu.h"
#include "screen.h"

Rectangle btn1 = {screenWidth / 2 - 200, 150, 400, 100};
Rectangle btn2 = {screenWidth / 2 - 200, 350, 400, 100};
Rectangle btn3 = {screenWidth / 2 - 200, 550, 400, 100};

bool btn1Action, btn2Action = false;
const char *msg = "Game of Life by Vanny, Lucas & Hamza";
Vector2 mousePoint = {0.0f, 0.0f};
Color nmcolor1 = BLUE;
Color nmcolor2 = BLUE;
Color nmcolor3 = BLUE;
Color hoverColor = DARKBLUE;
Color pressedColor = GREEN;
int btnState = 0; // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED

bool draw_menu(int &framesCounter)
{
    mousePoint = GetMousePosition();

    // Button 1
    if (CheckCollisionPointRec(mousePoint, btn1))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            nmcolor1 = SKYBLUE;
            btnState = 2;
        }
        else
        {
            nmcolor1 = hoverColor;
            btnState = 1;
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return true;
        }
    }
    else
    {
        nmcolor1 = BLUE;
        btnState = 0;
    }

    // Button 2
    if (CheckCollisionPointRec(mousePoint, btn2))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            nmcolor2 = SKYBLUE;
        }
        else
        {
            nmcolor2 = hoverColor;
        }

        // if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        // {
        //     //Rien
        // }
    }
    else
    {
        nmcolor2 = BLUE;
    }

    // Button 3
    if (CheckCollisionPointRec(mousePoint, btn3))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            nmcolor3 = SKYBLUE;
        }
        else
        {
            nmcolor3 = hoverColor;
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            CloseWindow();
        }
    }
    else
    {
        nmcolor3 = BLUE;
    }



    // Gestion des framesCounter
    if (IsKeyDown(KEY_RIGHT))
        framesCounter -= 8;
    else
        framesCounter++;
    if (IsKeyDown(KEY_LEFT))
        framesCounter += 8;

    // Dessin des Buttons
    DrawRectangleRounded(btn1, 0.5, 0, nmcolor1);
    DrawText("Jouer", screenWidth / 2 - (MeasureText("Jouer", 40) / 2), 180, 40, BLACK);

    DrawRectangleRounded(btn2, 0.5, 0, nmcolor2);
    DrawText("Continuer", screenWidth / 2 - (MeasureText("Continuer", 40) / 2), 380, 40, BLACK);

    DrawRectangleRounded(btn3, 0.5, 0, nmcolor3);
    DrawText("Quitter", screenWidth / 2 - (MeasureText("Quitter", 40) / 2), 580, 40, BLACK);

    return false;
}

void draw_title()
{
    DrawText(TextSubtext(msg, 0, framesCounter / 10), 200, 20, 40, BLACK);
}
