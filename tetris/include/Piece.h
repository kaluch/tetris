#ifndef PIECE_H
#define PIECE_H

#include "Liste_piece.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>

class Piece
{
public:

    Piece(const int& val)
    {
        _id_piece = val;
        _id_rot = 1;
    }

    Piece()
    {
        srand(time(NULL));
        int alea = (int)round((rand()*6)+1);
        _id_piece = alea;
        _id_rot = 1;
    }

    void tourner()
    {
        _id_rot++;
        if(_id_rot > NB_ROT)
            _id_rot = 1;
    }

    /*-------GETTERS-----------*/
    int id_piece(){return _id_piece;}
    int id_rot(){return _id_rot;}
    int x(){return _x;}
    int y(){return _y;}
    /*--------------------------*/
protected:
    int _id_piece;
    int _id_rot;
    int _x;
    int _y;
};

#endif // PIECE_H
