/*
    IMPLEMENTATION FILE FOR GAME CLASS
*/

/*==================== IMPORTS ====================*/
#include "game.h"
#include <random>

/*==================== CONSTRUCTOR ====================*/
Game::Game() : grid{Grid()}, 
               blocks{GetAllBlocks()}, 
               currentBlock{GetRandomBlock()}, 
               nextBlock{GetRandomBlock()},
               gameOver{false},
               score{0} {}

/*==================== DESTRUCTOR ====================*/
Game::~Game(){}

/*==================== UPDATE SCORE ====================*/
void Game::UpdateScore(int linesCleared, int moveDownPoints){
    switch(linesCleared){
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }

    score += moveDownPoints;

    return;
}

/*==================== GET RANDOM BLOCK ====================*/
Block Game::GetRandomBlock(void){
    if(blocks.empty()){
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    
    return block;
}

/*==================== GET ALL BLOCKS ====================*/
std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

/*==================== DRAW ====================*/
void Game::Draw(void){
    grid.Draw();
    currentBlock.Draw(11, 11);

    switch(nextBlock.id){
        case 3:
            nextBlock.Draw(255, 290);
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        default:
            nextBlock.Draw(270, 270);
            break;
    }

    return;
}

/*==================== RESET ====================*/
void Game::Reset(void){
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;

    return;
}

/*==================== HANDLE INPUT ====================*/
void Game::HandleInput(void){
    int keyPressed = GetKeyPressed();

    if(gameOver && keyPressed != 0){
        gameOver = false;
        Reset();
    }

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
            UpdateScore(0, 1);
            break;
        case KEY_S:
            MoveBlockDown();
            UpdateScore(0, 1);
            break;
        case KEY_UP:
            RotateBlock();
            break;
        case KEY_W:
            RotateBlock();
            break;
        case KEY_ESCAPE:
            if(paused){
                paused = false;
            }else{
                paused = true;
            }
            break;
        default:
            break;
    }

    return;
}

/*==================== MOVE BLOCK LEFT ====================*/
void Game::MoveBlockLeft(void){
    if(!gameOver){
        currentBlock.Move(0, -1);

        if(IsBlockOutside() || !BlockFits()){
            currentBlock.Move(0, 1);
        }
    }

    return;
}

/*==================== MOVE BLOCK RIGHT ====================*/
void Game::MoveBlockRight(void){
    if(!gameOver){
        currentBlock.Move(0, 1);

        if(IsBlockOutside() || !BlockFits()){
            currentBlock.Move(0, -1);
        }
    }

    return;
}

/*==================== MOVE BLOCK DOWN ====================*/
void Game::MoveBlockDown(void){
    if(!gameOver){
        currentBlock.Move(1, 0);

        if(IsBlockOutside() || !BlockFits()){
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }

    return;
}

/*==================== ROTATE BLOCK ====================*/
void Game::RotateBlock(void){
    if(!gameOver){
        currentBlock.Rotate();

        if(IsBlockOutside() || !BlockFits()){
            currentBlock.UndoRotation();
        }
    }

    return;
}

/*==================== IS BLOCK OUTSIDE ====================*/
bool Game::IsBlockOutside(void){
    std::vector<Posisiton> tiles = currentBlock.GetCellPositions();

    for(Posisiton item : tiles){
        if(grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }

    return false;
}

/*==================== LOCK BLOCK ====================*/
void Game::LockBlock(void){
    std::vector<Posisiton> tiles = currentBlock.GetCellPositions();

    for(Posisiton item : tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }

    currentBlock = nextBlock;

    if(!BlockFits()){
        gameOver = true;
    }

    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);

    return;
}

/*==================== BLOCK FITS ====================*/
bool Game::BlockFits(void){
    std::vector<Posisiton> tiles = currentBlock.GetCellPositions();

    for(Posisiton item : tiles){
        if(!grid.IsCellEmpty(item.row, item.column)){
            return false;
        }
    }

    return true;
}