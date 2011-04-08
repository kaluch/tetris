
#include "../include/Joueur.h"

Joueur::Joueur(std::string name)
{
	_nom = name;
	_score = 0;
	_workspace = Workspace();
	_nb_next = 1;
	init_next_piece();
	_piece_courante = Piece();
	//_workspace.sw



}

Joueur::~Joueur()
{
    ;
}

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
