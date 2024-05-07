
// void displayTxt(const char *message, int fontSize, Color color, Vector2 position, const char *fontPath) {
//     Font font = LoadFontEx(fontPath, fontSize, 0, 250); 
//     Vector2 textSize = MeasureTextEx(font, message, fontSize, 0);
//     Vector2 textPosition;
//     textPosition.x = position.x - (textSize.x / 2);
//     textPosition.y = position.y - (textSize.y / 2);
//     DrawTextEx(font, message, textPosition, fontSize, 0, color);
//     // UnloadFont(font);
// }

// void displayImg(const char* imagePath, int screenWidth, int screenHeight, int size_x, int size_y) {
//     Image image = LoadImage(imagePath); 
//     ImageResize(&image, size_x, size_y);
//     Texture2D texture = LoadTextureFromImage(image); 
//     UnloadImage(image);
//     DrawTexture(texture, (screenWidth - texture.width) / 2, (screenHeight - texture.height) / 2, WHITE);
//     // UnloadTexture(texture);
// }


// void displayImg(Texture2D name, int pos_x, int pos_y, int size_x, int size_y) {
//      DrawTexture(name, pos_x, pos_y, WHITE);
//     // UnloadTexture(texture);
// }

// void displayBackground(const char* imagePath ) {
//   Texture2D background = LoadTexture(imagePath);
//     DrawTexturePro(background,
//                    (Rectangle){ 0.0f, 0.0f, (float)background.width, (float)background.height },
//                    (Rectangle){ 0.0f, 0.0f, (float)screenWidth, (float)screenHeight },      
//                    (Vector2){ 0.0f, 0.0f },                                                       
//                    0.0f,             
//                    WHITE);
// }