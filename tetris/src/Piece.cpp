#include "../include/Piece.h"

using namespace std;

void Piece::afficher(){
        for(int i=0;i<4;i++){
                _blocs[i].afficher();
        }
}

Bloc Piece::downest(){
    Bloc min=blocs()[0];
    for(int i=1;i<4;i++){
        if(blocs()[i].y()<min.y())
            min = blocs()[i];
    }
    return min;
}

void Piece::tourner() {
		_id_rot++;
		if (_id_rot > NB_ROT)
			_id_rot = 1;
        charger_blocs(id_piece(),id_rot());
	}

void Piece::charger_blocs(int id_piece, int id_rot){
    changerPiece(id_piece,id_rot,rColor(),gColor(),bColor());
}

