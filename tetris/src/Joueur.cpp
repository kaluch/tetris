
#include "../include/Joueur.h"

void Joueur::init_next_piece(){
	_next_piece = (Piece *)malloc(_nb_next * sizeof(Piece));
	for(int i=0;i<_nb_next;i++)
		_next_piece[i] = Piece();
}

void Joueur::changer_pieces(){
	_piece_courante = _next_piece[0];
	for(int i=0;i<_nb_next-1;i++)
		_next_piece[i] = _next_piece[i+1];
	_next_piece[_nb_next] = Piece();
}

void Joueur::afficher(int i){
    _piece_courante.afficher();
    Workspace().afficher(20+i*300,20);

}
