#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block{
    public:
        /* Methods */
        Block();
        ~Block();
        void Draw();
        void Move(int, int);
        std::vector<Posisiton> GetCellPositions();
        void Rotate();
        void UndoRotation();

        /* Data */
        int id;
        std::map<int, std::vector<Posisiton>> cells;

    private:
        /* Methods */
        /* Data */
        int cellSize;
        int rotationState;
        int rowOffset;
        int columnOffset;
        std::vector<Color> colors;
};