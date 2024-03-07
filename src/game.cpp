#include "game.h"
#include <random>

Game::Game() : grid{Grid()}, 
               blocks{GetAllBlocks()}, 
               currentBlock{GetRandomBlock()}, 
               nextBlock{GetRandomBlock()} {}

Game::~Game(){}

Block Game::GetRandomBlock(void){
    if(blocks.empty()){
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    
    return block;
}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(void){
    grid.Draw();
    currentBlock.Draw();

    return;
}

void Game::HandleInput(void){
    int keyPressed = GetKeyPressed();

    switch(keyPressed){
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_A:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_D:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_S:
            MoveBlockDown();
            break;
        case KEY_UP:
            RotateBlock();
            break;
        case KEY_W:
            RotateBlock();
            break;
        default:
            break;
    }

    return;
}

void Game::MoveBlockLeft(void){
    currentBlock.Move(0, -1);

    if(IsBlockOutside()){
        currentBlock.Move(0, 1);
    }

    return;
}

void Game::MoveBlockRight(void){
    currentBlock.Move(0, 1);

    if(IsBlockOutside()){
        currentBlock.Move(0, -1);
    }

    return;
}

void Game::MoveBlockDown(void){
    currentBlock.Move(1, 0);

    if(IsBlockOutside()){
        currentBlock.Move(-1, 0);
    }

    return;
}

bool Game::IsBlockOutside(void){
    std::vector<Posisiton> tiles = currentBlock.GetCellPositions();

    for(Posisiton item : tiles){
        if(grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }

    return false;
}

void Game::RotateBlock(void){
    currentBlock.Rotate();

    if(IsBlockOutside()){
        currentBlock.UndoRotation();
    }

    return;
}