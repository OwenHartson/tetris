#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game{
    public:
        /* Methods */
        Game();
        ~Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        void HandleInput();

        /* Data */
        Grid grid;

    private:
        /* Methods */
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        bool IsBlockOutside();
        void RotateBlock();

        /* Data */
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};