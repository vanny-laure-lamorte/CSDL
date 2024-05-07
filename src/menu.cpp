#include <raylib.h>
#include "string"
using namespace std;


// Load Files
#include "menu.h"
#include "screen.h"


// COLOR
Color grey1 = Color{100, 54, 54, 54};

//**** IMAGES

Image logo; 
Image btn1; 
Image btn2; 
Image btn3; 

Texture2D background;
Texture2D t_btn1;
Texture2D t_btn2;
Texture2D t_btn3;

void load_img_menu()
{  
 
logo = LoadImage("src/img/icon.png");
    SetWindowIcon(logo);
    btn1 = LoadImage("src/img/button1.png");
     btn2 = LoadImage("src/img/button2.png");
     btn3 = LoadImage("src/img/button3.png");
    ImageResize(&btn1, 330, 330);
    ImageResize(&btn2, 330, 330);
    ImageResize(&btn3, 330, 330);

    // Images Texture
     background = LoadTexture("src/img/background.png");
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
    UnloadTexture(t_btn1);
    UnloadTexture(t_btn1);
    
}

//**** FONT
Font font1;
Font font2;

void load_font_menu() {

   font1 = LoadFontEx("src/font/Television.ttf", 400, NULL, NULL); 
   font2 = LoadFontEx("src/font/Roboto-Black.ttf", 400, 0, 252); 
}

void unload_font_menu() {
    UnloadFont(font1);
    UnloadFont(font2); 
}


int menu(){  

// Display images
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(t_btn1, 100, 50, WHITE);
    DrawTexture(t_btn2, 100, 150, WHITE);
    DrawTexture(t_btn3, 100, 250, WHITE);

// Title
DrawTextEx(font1, "Game of Life",(Vector2){ 140, 80 }, 50, 2, DARKGRAY);
DrawTextEx(font1, "by Hamza N., Lucas M.D.M & Vanny L.", (Vector2){ 140, 120 }, 16, 2, DARKGRAY);

// Menu options
DrawTextEx(font1, "Game of Life", (Vector2){ 170,200 }, 30, 2, DARKGRAY);
DrawTextEx(font1, "Rules & Origins", (Vector2){ 170, 300 }, 30, 2, DARKGRAY);
DrawTextEx(font1, "Exit", (Vector2){ 240, 390}, 30, 2, DARKGRAY);

// Copyright
DrawTextEx(font2, "© ", (Vector2){ 155, 458}, 15, 2, DARKGRAY);
DrawTextEx(font2,"Copyright | All rights reversed.", (Vector2){ 170, 460}, 11, 2, DARKGRAY);


    return 0;
}
