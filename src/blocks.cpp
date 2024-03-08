/*
    INHERITED CLASSES FOR EACH BLOCK TYPE

    EACH BLOCK SETS:
        -> ID TO IDENTIFY THE TYPE OF BLOCK
        -> ITS COLORED IN POSITIONS (CELLS)
        -> ITS STARTING POSITION ON THE SCREEN, MOVE(X, Y)
*/

#include "block.h"
#include "position.h"

class LBlock : public Block{
    public:
        /* Data */
        /* Methods */
        LBlock(){
            id = 1;
            cells[0] = { Posisiton(0, 2), Posisiton(1, 0), Posisiton(1, 1), Posisiton(1, 2) };
            cells[1] = { Posisiton(0, 1), Posisiton(1, 1), Posisiton(2, 1), Posisiton(2, 2) };
            cells[2] = { Posisiton(1, 0), Posisiton(1, 1), Posisiton(1, 2), Posisiton(2, 0) };
            cells[3] = { Posisiton(0, 0), Posisiton(0, 1), Posisiton(1, 1), Posisiton(2, 1) };
            Move(0, 3);
        }
};

class JBlock : public Block{
    public:
        /* Data */
        /* Methods */
        JBlock(){
            id = 2;
            cells[0] = { Posisiton(0, 0), Posisiton(1, 0), Posisiton(1, 1), Posisiton(1, 2) };
            cells[1] = { Posisiton(0, 1), Posisiton(0, 2), Posisiton(1, 1), Posisiton(2, 1) };
            cells[2] = { Posisiton(1, 0), Posisiton(1, 1), Posisiton(1, 2), Posisiton(2, 2) };
            cells[3] = { Posisiton(0, 1), Posisiton(1, 1), Posisiton(2, 0), Posisiton(2, 1) };
            Move(0, 3);
        }
};

class IBlock : public Block{
    public:
        /* Data */
        /* Methods */
        IBlock(){
            id = 3;
            cells[0] = { Posisiton(1, 0), Posisiton(1, 1), Posisiton(1, 2), Posisiton(1, 3) };
            cells[1] = { Posisiton(0, 2), Posisiton(1, 2), Posisiton(2, 2), Posisiton(3, 2) };
            cells[2] = { Posisiton(2, 0), Posisiton(2, 1), Posisiton(2, 2), Posisiton(2, 3) };
            cells[3] = { Posisiton(0, 1), Posisiton(1, 1), Posisiton(2, 1), Posisiton(3, 1) };
            Move(-1, 3);
        }
};

class OBlock : public Block{
    public:
        /* Data */
        /* Methods */
        OBlock(){
            id = 4;
            cells[0] = { Posisiton(0, 0), Posisiton(0, 1), Posisiton(1, 0), Posisiton(1, 1) };
            cells[1] = { Posisiton(0, 0), Posisiton(0, 1), Posisiton(1, 0), Posisiton(1, 1) };
            cells[2] = { Posisiton(0, 0), Posisiton(0, 1), Posisiton(1, 0), Posisiton(1, 1) };
            cells[3] = { Posisiton(0, 0), Posisiton(0, 1), Posisiton(1, 0), Posisiton(1, 1) };
            Move(0, 4);
        }
};

class SBlock : public Block{
    public:
        /* Data */
        /* Methods */
        SBlock(){
            id = 5;
            cells[0] = { Posisiton(0, 1), Posisiton(0, 2), Posisiton(1, 0), Posisiton(1, 1) };
            cells[1] = { Posisiton(0, 1), Posisiton(1, 1), Posisiton(1, 2), Posisiton(2, 2) };
            cells[2] = { Posisiton(1, 1), Posisiton(1, 2), Posisiton(2, 0), Posisiton(2, 1) };
            cells[3] = { Posisiton(0, 0), Posisiton(1, 0), Posisiton(1, 1), Posisiton(2, 1) };
            Move(0, 3);
        }
};

class TBlock : public Block{
    public:
        /* Data */
        /* Methods */
        TBlock(){
            id = 6;
            cells[0] = { Posisiton(0, 1), Posisiton(1, 0), Posisiton(1, 1), Posisiton(1, 2) };
            cells[1] = { Posisiton(0, 1), Posisiton(1, 1), Posisiton(1, 2), Posisiton(2, 1) };
            cells[2] = { Posisiton(1, 0), Posisiton(1, 1), Posisiton(1, 2), Posisiton(2, 1) };
            cells[3] = { Posisiton(0, 1), Posisiton(1, 0), Posisiton(1, 1), Posisiton(2, 1) };
            Move(0, 3);
        }
};

class ZBlock : public Block{
    public:
        /* Data */
        /* Methods */
        ZBlock(){
            id = 7;
            cells[0] = { Posisiton(0, 0), Posisiton(0, 1), Posisiton(1, 1), Posisiton(1, 2) };
            cells[1] = { Posisiton(0, 2), Posisiton(1, 1), Posisiton(1, 2), Posisiton(2, 1) };
            cells[2] = { Posisiton(1, 0), Posisiton(1, 1), Posisiton(2, 1), Posisiton(2, 2) };
            cells[3] = { Posisiton(0, 1), Posisiton(1, 0), Posisiton(1, 1), Posisiton(2, 0) };
            Move(0, 3);
        }
};