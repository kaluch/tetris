#include <iostream>

#include "../include/workspace.h"
#include "../globale.h"


Workspace::Workspace()
{
    Set_nb_col(10);
    Set_nb_lignes(20);
    Set_tableau();
}

Workspace::~Workspace()
{
    free_tableau();
}

void Workspace::afficher(const int& x, const int& y)
{
	std::cerr << "affichage workspace joueur" << std::endl;
}
/*
void Workspace::switch_piece(Piece next, Piece courante){
	ajouter_Piece(courante);
}*/
