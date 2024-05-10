#include <raylib.h>
#include "string"

#include "../include/screen.hpp"
using namespace std;
Vector2 mousePoint_rule = {0.0f, 0.0f};

int rule_state()
{
    mousePoint_rule = GetMousePosition();

    DrawRectangle(screenWidth - 100, 20, 90, 25, RED);
    DrawText("Menu", screenWidth - 90, 22, 18, BLACK);

    Rectangle menu_btn = {screenWidth - 100, 20, 90, 25};

    if (CheckCollisionPointRec(mousePoint_rule, menu_btn))
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 0;
        }
    }
    return 20;
}
