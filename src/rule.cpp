#include <raylib.h>
#include "string"

#include "screen.h"

using namespace std;


// Color
Color grey1 = Color{100, 54, 54, 54};
Font font1;
Font font2;

void displayTxt(const char *message, int fontSize, Color color, Vector2 position, const char *fontPath) {
    Font font = LoadFontEx(fontPath, fontSize, 0, 250); 
    Vector2 textSize = MeasureTextEx(font, message, fontSize, 0);
    Vector2 textPosition;
    textPosition.x = position.x - (textSize.x / 2);
    textPosition.y = position.y - (textSize.y / 2);
    DrawTextEx(font, message, textPosition, fontSize, 0, color);
    // UnloadFont(font);
}

void load_font_menu() {
   // Load font
   // Font font1 = LoadFont("resources/Television.ttf"); 
   // Font font2 = LoadFont("resources/Roboto-Black.ttf");
   Font font1 = LoadFont("src/font/Television.ttf"); 
   Font font2 = LoadFont("src/font/Roboto-Black.ttf"); 
}

void unload_font_menu() {
    UnloadFont(font1);
    UnloadFont(font2); 
}

int menu(){    

    // Title
DrawTextEx(font1, "Game of Life", (Vector2){ 260,10 }, 50, 2, DARKGRAY);
DrawTextEx(font1, "by Hamza N., Lucas M.D.M & Vanny L.", (Vector2){ 260,130 }, 16, 2, DARKGRAY);

// Menu options
DrawTextEx(font1, "Game of Life", (Vector2){ 260,215 }, 30, 2, DARKGRAY);
DrawTextEx(font1, "Rules & Origins", (Vector2){ 270, 315 }, 30, 2, DARKGRAY);
DrawTextEx(font1, "Exit", (Vector2){ 260, 410}, 30, 2, DARKGRAY);

// Copyright
DrawTextEx(font1, "© ", (Vector2){ 190,470}, 15, 2, DARKGRAY);
DrawTextEx(font2,"Copyright | All rights reversed.", (Vector2){ 250, 470}, 11, 2, DARKGRAY);
  


    return 0;
}
