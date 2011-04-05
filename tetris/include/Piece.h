#ifndef PIECE_H
#define PIECE_H

#inlude "Liste_piece.h"
#include <iostream>

class Piece
{
    public:
        Pieces(){
            _pir
        }

             int **creer_piece(const int& val)
             {
                 return _pieces[val][1];
             }

             int **creer_piece()
             {
                 srand(time(null));
                 int alea = round((rand()*6)+1);
                 return _pieces[alea][1];
             }
    protected:
      int _piece[4][4];
    private:
};

#endif // PIECE_H
