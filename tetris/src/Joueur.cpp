#include "../include/Joueur.h"

void Joueur::init_next_piece(){
	for(int i=0;i<nb_next();i++)
		next_piece().push_back(Piece());
}

void Joueur::changer_pieces(){
	_piece_courante = _next_piece[0];
	for(int i=0;i<_nb_next-1;i++)
		_next_piece[i] = _next_piece[i+1];
	_next_piece[_nb_next] = Piece();
}

void Joueur::afficher(){
	std::cout << "Joueur " << nom() << std::endl;
    _piece_courante.afficher();
    Workspace().afficher(20+id_joueur()*300,20);

}

void Joueur::gestion_piece_courante(){
    int xMin = piece_courante().downest().x();
    int yMin = piece_courante().downest().y();
    if(!workspace().tableau()[yMin - 1][xMin].vide())
            poser_piece();
    }

void Joueur::poser_piece(){
    for(int i=0;i<4;i++)
        workspace().tableau()[piece_courante().blocs()[i].x()][piece_courante().blocs()[i].y()] = piece_courante().blocs()[i];
    workspace().switch_piece(next_p());
    changer_pieces();
}

void Joueur::move(){
	if(piece_courante().y() > 1)
		piece_courante().setY(piece_courante().y() - 1);
	else
        poser_piece();
}

void Joueur::traitement_workspace(){
    int i=0;
    do{
        if(workspace().compte_ligne(i) == workspace().nb_col()){
              workspace().detruire_ligne(i);
              setScore(score() +1);
        }
        i++;

    }while(workspace().compte_ligne(i)>0);
}

