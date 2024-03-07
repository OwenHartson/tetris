#include "block.h"

Block::Block() : cellSize{30}, 
                 rotationState{0}, 
                 colors{GetCellColors()},
                 rowOffset{0},
                 columnOffset{0} {};

Block::~Block(){};

void Block::Draw(void){
    std::vector<Posisiton> tiles = GetCellPositions();

    for(Posisiton item : tiles){
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }

    return;
}

void Block::Move(int rows, int columns){
    rowOffset += rows;
    columnOffset += columns;

    return;
}

std::vector<Posisiton> Block::GetCellPositions(){
    std::vector<Posisiton> tiles = cells[rotationState];
    std::vector<Posisiton> movedTiles;

    for(Posisiton item : tiles){
        Posisiton newPos = Posisiton(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}

void Block::Rotate(void){
    rotationState++;

    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }

    return;
}

void Block::UndoRotation(void){
    rotationState--;

    if(rotationState == -1){
        rotationState = cells.size() - 1;
    }

    return;
}