/*
    HEADER FILE FOR GAME CLASS

    PUBLIC METHODS:
        Draw()          -> DRAWS THE GAME FIELD
        HandleInput()   -> HANDLES THE USER INPUT/KEY PRESSES
        MoveBlockDown() -> MOVES THE  CURRENT BLOCK DOWN THE GAME FIELD

    PUBLIC DATA:
        bool gameOver   -> IF TRUE THE GAME IS OVER (SET TO FALSE BY DEFAULT)
        int score       -> HOLDS THE GAME TOTAL SCORE (SET TO 0 BY DEFAULT)
        bool paused     -> IF TRUE THE GAME WILL BE PAUSED (SET TO FALSE BY DEFAULT)
*/

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