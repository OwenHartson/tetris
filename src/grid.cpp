/*
    IMPLEMENTATION FILE FOR GRID CLASS
*/

/*==================== IMPORTS ====================*/
#include "grid.h"
#include "colors.h"
#include <iostream>

/*==================== CONSTRUCTOR ====================*/
Grid::Grid() : numRows{20}, numCols{10}, cellSize{30}{ 
    Initialize(); 
    colors = GetCellColors(); 
}

/*==================== DESTRUCTOR ====================*/
Grid::~Grid(){}

/*==================== IS CELL OUTSIDE ====================*/
bool Grid::IsCellOutside(int row, int column){
    if(row >= 0 && row < numRows && column >= 0 && column < numCols){
        return false;
    }

    return true;
}

/*==================== INITIALIZE ====================*/
void Grid::Initialize(void){
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            grid[row][column] = 0;
        }
    }

    return;
}

/*==================== PRINT ====================*/
void Grid::Print(void){
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }

    return;
}

/*==================== DRAW ====================*/
void Grid::Draw(void){
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }

    return;
}

/*==================== IS CELL EMPTY ====================*/
bool Grid::IsCellEmpty(int row, int column){
    if(grid[row][column] == 0){
        return true;
    }

    return false;
}

/*==================== IS ROW FULL ====================*/
bool Grid::IsRowFull(int row){
    for(int column = 0; column < numCols; column++){
        if(grid[row][column] == 0){
            return false;
        }
    }

    return true;
}

/*==================== CLEAR ROW ====================*/
void Grid::ClearRow(int row){
    for(int column = 0; column < numCols; column++){
        grid[row][column] = 0;
    }

    return;
}

/*==================== MOVE ROW DOWN ====================*/
void Grid::MoveRowDown(int row, int numberRows){
    for(int column = 0; column < numCols; column++){
        grid[row + numberRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
    
    return;
}

/*==================== CLEAR FULL ROWS ====================*/
int Grid::ClearFullRows(void){
    int completed = 0;

    for(int row = numRows - 1; row >= 0; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        }else if(completed > 0){
            MoveRowDown(row, completed);
        }
    }

    return completed;
}