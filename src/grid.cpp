#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid() : numRows{20}, numCols{10}, cellSize{30}{ 
    Initialize(); 
    colors = GetCellColors(); 
}

Grid::~Grid(){}

bool Grid::IsCellOutside(int row, int column){
    if(row >= 0 && row < numRows && column >= 0 && column < numCols){
        return false;
    }

    return true;
}

void Grid::Initialize(void){
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            grid[row][column] = 0;
        }
    }

    return;
}

void Grid::Print(void){
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }

    return;
}

void Grid::Draw(void){
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }

    return;
}