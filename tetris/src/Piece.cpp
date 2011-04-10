#include "../include/Piece.h"

using namespace std;

void Piece::afficher(){
        for(int i=0;i<4;i++){
                _blocs[i].afficher();
        }
}



