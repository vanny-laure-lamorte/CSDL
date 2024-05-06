#include <raylib.h>
#include <iostream>
#include "menu.h"

Rectangle btnBounds = {100, 100, 200, 150};
bool btnAction = false;
const char *msg = "Poupinette, Poupinette, Poupinette, Poupinette";
Vector2 mousePoint = {0.0f, 0.0f};
Color normalColor = BLUE;
Color hoverColor = DARKBLUE;
Color pressedColor = GREEN;
int btnState = 0; // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED

bool draw_menu(int &framesCounter, const char *msg)
{
    mousePoint = GetMousePosition();

    if (CheckCollisionPointRec(mousePoint, btnBounds))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            normalColor = SKYBLUE;
            btnState = 2;
        }
        else
        {
            normalColor = hoverColor;
            btnState = 1;
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            btnAction = true;
        }
    }
    else
    {
        normalColor = BLUE;
        btnState = 0;
    }

    if (btnAction)
    {
        btnAction = false;
        return true;
    }

    if (IsKeyDown(KEY_RIGHT))
        framesCounter -= 8;
    else
        framesCounter++;
    if (IsKeyDown(KEY_LEFT))
        framesCounter += 8;

    DrawRectangleRec(btnBounds, normalColor);
    DrawText(TextSubtext(msg, 0, framesCounter / 10), 210, 160, 20, MAROON);

    return false;
}