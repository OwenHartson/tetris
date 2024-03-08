/*
    IMPLEMENTATION FILE FOR BLOCK CLASS
*/

/*==================== IMPORTS ====================*/
#include "block.h"

/*==================== CONSTRUCTOR ====================*/
Block::Block() : cellSize{30}, 
                 rotationState{0}, 
                 colors{GetCellColors()},
                 rowOffset{0},
                 columnOffset{0} {};

/*==================== DESTRUCTOR ====================*/
Block::~Block(){};

/*==================== DRAW ====================*/
void Block::Draw(int offsetX, int offsetY){
    std::vector<Posisiton> tiles = GetCellPositions();

    for(Posisiton item : tiles){
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }

    return;
}

/*==================== MOVE ====================*/
void Block::Move(int rows, int columns){
    rowOffset += rows;
    columnOffset += columns;

    return;
}

/*==================== GET CELL POSITIONS ====================*/
std::vector<Posisiton> Block::GetCellPositions(){
    std::vector<Posisiton> tiles = cells[rotationState];
    std::vector<Posisiton> movedTiles;

    for(Posisiton item : tiles){
        Posisiton newPos = Posisiton(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}

/*==================== ROTATE ====================*/
void Block::Rotate(void){
    rotationState++;

    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }

    return;
}

/*==================== UNDO-ROTATION ====================*/
void Block::UndoRotation(void){
    rotationState--;

    if(rotationState == -1){
        rotationState = static_cast<int>(cells.size() - 1);
    }

    return;
}