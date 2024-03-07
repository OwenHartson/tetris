#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game{
    public:
        /* Methods */
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();

        /* Data */
        bool gameOver;
        int score;
        bool paused{false};

    private:
        /* Methods */
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void MoveBlockLeft();
        void MoveBlockRight();
        bool IsBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int, int);

        /* Data */
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Grid grid;
};