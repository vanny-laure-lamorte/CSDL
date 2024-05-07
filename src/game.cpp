#include <raylib.h>
#include "game.hpp"
#include "screen.h"
#include <iostream>
int cellSize = 25;
int columns = screenWidth / cellSize;
int rows = screenHeight / cellSize;
using namespace std;
void draw_grid()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (((column == 0) && (row == 0)) || ((column == columns -1) & (row == 0)) || ((row == rows -1) && (column == 0)) || ((row == rows -1) && (column == columns -1)))
                DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, BLACK);
            else
                DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, WHITE);
        }
    }
}