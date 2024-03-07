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

        /* Data */
        int grid[20][10];

    private:
        /* Methods */

        /* Data */
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};