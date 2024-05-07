#include <raylib.h>
#include "menu.h"
#include "screen.h"

#include "raylib.h"
#include "string"

using namespace std;

// Font
const char *font1 = "src/font/Television.ttf";
const char *font2 = "src/font/Roboto-Black.ttf";

// Color
Color grey1 = Color{100, 54, 54, 54};

void displayTxt(const char *message, int fontSize, Color color, Vector2 position, const char *fontPath) {
    Font font = LoadFontEx(fontPath, fontSize, 0, 250); 
    Vector2 textSize = MeasureTextEx(font, message, fontSize, 0);
    Vector2 textPosition;
    textPosition.x = position.x - (textSize.x / 2);
    textPosition.y = position.y - (textSize.y / 2);
    DrawTextEx(font, message, textPosition, fontSize, 0, color);
    // UnloadFont(font);
}

void displayImg(const char* imagePath, int screenWidth, int screenHeight, int size_x, int size_y) {
    Image image = LoadImage(imagePath); 
    ImageResize(&image, size_x, size_y);
    Texture2D texture = LoadTextureFromImage(image); 
    UnloadImage(image);
    DrawTexture(texture, (screenWidth - texture.width) / 2, (screenHeight - texture.height) / 2, WHITE);
    // UnloadTexture(texture);
}


void displayImg(Texture2D name, int pos_x, int pos_y, int size_x, int size_y) {
     DrawTexture(name, pos_x, pos_y, WHITE);
    // UnloadTexture(texture);
}

void displayBackground(const char* imagePath ) {
  Texture2D background = LoadTexture(imagePath);
    DrawTexturePro(background,
                   (Rectangle){ 0.0f, 0.0f, (float)background.width, (float)background.height },
                   (Rectangle){ 0.0f, 0.0f, (float)screenWidth, (float)screenHeight },      
                   (Vector2){ 0.0f, 0.0f },                                                       
                   0.0f,             
                   WHITE);
}


int menu(){  

    displayTxt("Game of Life", 50, DARKGRAY, (Vector2){260, 100}, font1);
    displayTxt("by Hamza N., Lucas M.D.M & Vanny L.", 16, DARKGRAY, (Vector2){260, 130}, font1);    
 
    displayTxt("Game of Life ", 30, DARKGRAY, (Vector2){260, 215}, font1);
    displayTxt("Rules & Origins", 30, DARKGRAY, (Vector2){270, 315}, font1);
    displayTxt("Exit", 30, DARKGRAY, (Vector2){260, 410}, font1);
    
    // Copyright
    displayTxt("© ", 15, DARKGRAY, (Vector2){190, 470}, font2);
    displayTxt("Copyright | All rights reversed.", 11, DARKGRAY, (Vector2){250, 470}, font2);
  

    return 0;
}
