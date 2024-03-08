/*
    HEADER FILE FOR POSITION CLASS

    PUBLIC METHODS:
        Posisiton(int, int) -> CONSTRUCTOR, TAKES ROW AND COLUMN
    
    PUBLIC DATA:
        int row             -> THE ROW (X) POSITION
        int column          -> THE COLUMN (Y) POSITION
*/

#pragma once

class Posisiton{
    public:
        /* Methods */
        Posisiton(int, int);
        ~Posisiton();

        /* Data */
        int row;
        int column;
        
    private:
        /* Methods */
        /* Data */
};