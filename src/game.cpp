#include <raylib.h>
#include <iostream>
using namespace std;

#include "../include/game.hpp"
#include "../include/screen.hpp"
#include <iostream>
int cellSize = 5;
int columns = screenWidth / cellSize;
int rows = screenHeight / cellSize;

int draw_grid()
{
    for (int row = 0; row < rows - 25; row++)
    {
        for (int column = 0; column < columns - 10; column++)
        {
         DrawRectangle(25 + column * cellSize, 30+ row * cellSize, cellSize - 1, cellSize - 1, WHITE);
        }
    }
}