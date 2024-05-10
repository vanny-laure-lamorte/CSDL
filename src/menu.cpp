#include <raylib.h>
#include "string"
using namespace std;

// Load Files
#include "../include/menu.hpp"
#include "../include/screen.hpp"

//**** COLOR
Color grey1 = Color{100, 54, 54, 54};

//**** CLICK
Vector2 mousePoint = {0.0f, 0.0f};

//**** IMAGES
Image logo;
Image btn1;
Image btn2;
Image btn3;

Texture2D background;
Texture2D t_btn1;
Texture2D t_btn2;
Texture2D t_btn3;

//**** FONT
Font font1;
Font font2;

//**** TEXTE
float textWidth_title;
float textWidth_name;
float textWidth_op1;
float textWidth_op2;
float textWidth_op3;
float textWidth_copy;


void load_img_menu()
{
    logo = LoadImage("src/img/icon.png");
    SetWindowIcon(logo);
    btn1 = LoadImage("assets/img/button1.png");
    btn2 = LoadImage("assets/img/button2.png");
    btn3 = LoadImage("assets/img/button3.png");
    ImageResize(&btn1, 330, 330);
    ImageResize(&btn2, 330, 330);
    ImageResize(&btn3, 330, 330);

    // Images Texture
    background = LoadTexture("assets/img/background3.png");
    t_btn1 = LoadTextureFromImage(btn1);
    t_btn2 = LoadTextureFromImage(btn2);
    t_btn3 = LoadTextureFromImage(btn3);
}

void unload_img_menu()
{
    UnloadImage(logo);
    UnloadImage(btn1);
    UnloadImage(btn2);
    UnloadImage(btn3);

    UnloadTexture(background);
    UnloadTexture(t_btn1);
    UnloadTexture(t_btn2);
    UnloadTexture(t_btn3);
}

void load_font_menu()
{

    font1 = LoadFontEx("assets/font/Television.ttf", 400, NULL, NULL);
    font2 = LoadFontEx("assets/font/Roboto-Black.ttf", 400, 0, 252);
}

void unload_font_menu()
{
    UnloadFont(font1);
    UnloadFont(font2);
}

//**** RECT
Rectangle rect_btn1;
Rectangle rect_btn2;
Rectangle rect_btn3;

int menu()
{
    // Update text position
textWidth_title = MeasureTextEx(font1, "Game of Life", 50, 2).x;
textWidth_name = textWidth_title = MeasureTextEx(font1, "by Hamza N., Lucas M.D.M & Vanny L.", 16, 2).x;
    textWidth_op1 = MeasureTextEx(font1, "Game of Life", 30, 2).x;
textWidth_op2 = MeasureTextEx(font1, "Rules & Origins", 30, 2).x;
textWidth_op3 = MeasureTextEx(font1, "Exit", 30, 2).x;
textWidth_copy = MeasureTextEx(font2, "Copyright | All rights reversed.", 11, 2).x;


    // Update button rectangles
    rect_btn1 = { float(GetScreenWidth() - 245) / 2, 170, 245, 80 };
    rect_btn2 = { float(GetScreenWidth() - 245) / 2, 270, 245, 80 };
    rect_btn3 = { float(GetScreenWidth() - 245) / 2, 370, 245, 80 };

    // Display images
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(t_btn1, (GetScreenWidth() - t_btn1.width) / 2, 50, WHITE);
    DrawTexture(t_btn2, (GetScreenWidth() - t_btn2.width) / 2, 150, WHITE);
    DrawTexture(t_btn3, (GetScreenWidth() - t_btn3.width) / 2, 250, WHITE);

    // Title
    DrawTextEx(font1, "Game of Life", (Vector2){float (GetScreenWidth() - textWidth_name)/2, 50}, 50, 2, DARKGRAY);
    DrawTextEx(font1, "by Hamza N., Lucas M.D.M & Vanny L.", (Vector2){float (GetScreenWidth() - textWidth_name)/2, 100}, 16, 2, DARKGRAY);

    // Copyright
    DrawTextEx(font2, "© ", (Vector2){380, 458}, 15, 2, DARKGRAY);
    DrawTextEx(font2, "Copyright | All rights reversed.", (Vector2){float (GetScreenWidth() - textWidth_copy)/2, 460}, 11, 2, DARKGRAY);

    // Event
    mousePoint = GetMousePosition();

    // Button 1
    if (CheckCollisionPointRec(mousePoint, rect_btn1))
    {
        DrawTexture(t_btn1, (GetScreenWidth() - t_btn1.width) / 2, 53, WHITE);
        DrawTextEx(font1, "Game of Life", (Vector2){float (GetScreenWidth() - textWidth_op1)/2, 200}, 30, 2, DARKGRAY);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 10;
        }
    }
    else
    {
        DrawTexture(t_btn1, (GetScreenWidth() - t_btn1.width)/ 2, 50, WHITE);
        DrawTextEx(font1, "Game of Life",  (Vector2){float (GetScreenWidth() - textWidth_op1)/2, 200}, 30, 2, DARKGRAY);
    }

    // Button 2
    if (CheckCollisionPointRec(mousePoint, rect_btn2))
    {
        DrawTexture(t_btn2, (GetScreenWidth() - t_btn2.width)/ 2, 153, WHITE);
        DrawTextEx(font1, "Rules & Origins", (Vector2){float (GetScreenWidth() - textWidth_op2)/2, 300}, 30, 2, DARKGRAY);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return 20;
        }
    }
    else
    {
        DrawTexture(t_btn2, (GetScreenWidth() - t_btn2.width) / 2, 150, WHITE);
        DrawTextEx(font1, "Rules & Origins",  (Vector2){float (GetScreenWidth() - textWidth_op2)/2, 300}, 30, 2, DARKGRAY);
    }

    // Button 3
    if (CheckCollisionPointRec(mousePoint, rect_btn3))
    {
        DrawTexture(t_btn3, (GetScreenWidth() - t_btn3.width) / 2, 253, WHITE);
        DrawTextEx(font1, "Exit",  (Vector2){float (GetScreenWidth() - textWidth_op3)/2, 390}, 30, 2, DARKGRAY);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            return -1;
        }
    }
    else
    {
        DrawTexture(t_btn3, (GetScreenWidth() - t_btn3.width)/ 2, 250, WHITE);
        DrawTextEx(font1, "Exit", (Vector2){float (GetScreenWidth() - textWidth_op3)/2, 390}, 30, 2, DARKGRAY);
    }

    return 0;
}
