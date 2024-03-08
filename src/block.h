/*
    HEADER FILE FOR BLOCK CLASS

    PUBLIC METHODS:
        Draw(int, int)                      -> DRAWS THE BLOCK BASED ON THE GRID
        Move(int, int)                      -> MOVES THE BLOCK AROUND THE GRID BASED OFF PROVIDED OFFSETS X AND Y
        vector<Posisiton> GetCellPositions()-> RETURNS THE CELL POSITION OF THE BLOCKS
        Rotate()                            -> ROTATES THE BLOCK
        UndoRotation()                      -> UNDOES THE BLOCK ROTATION

    PUBLIC DATA:
        int id                                      -> THE ID (TYPE) OF THE BLOCK
        std::map<int, std::vector<Posisiton>> cells -> THE BLOCKS POSITION ON THE GRID
*/

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
        void Draw(int, int);
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