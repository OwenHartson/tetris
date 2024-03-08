/*
    HEADER FILE FOR GRID CLASS

    PUBLIC METHODS:
        Initialize()            -> CREATES THE INITIAL GRID
        Print()                 -> PRINTS THE GRID IN THE TERMINAL
        Draw()                  -> DRAWS THE GRID TO THE GAME WINDOW
        IsCellOutside(int, int) -> CHECKS IF A POSITION IS OUTSIDE OF THE GRID
        IsCellEmpty(int, int)   -> CHECKS IF A CELL POSITION IS EMPTY
        ClearFullRows()         -> CLEARS ROWS OF THE GRID
    
    PUBLIC DATA:
        int grid[20][10]        -> SIZE OF THE GAME GRID
*/

#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
        /* Methods */
        Grid();
        ~Grid();
        void Initialize();
        void Print();
        void Draw();
        bool IsCellOutside(int, int);
        bool IsCellEmpty(int, int);
        int ClearFullRows();

        /* Data */
        int grid[20][10];

    private:
        /* Methods */
        bool IsRowFull(int);
        void ClearRow(int);
        void MoveRowDown(int, int);

        /* Data */
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};