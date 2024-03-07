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