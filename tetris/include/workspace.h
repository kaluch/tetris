#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <iostream>
#include <stdlib.h>
#include "Piece.h"
#include "../globale.h"

class Workspace
{
public:
    Workspace()
    {
        std::cerr<<"constr ws()";
        Set_tableau();
        std::cerr<<"...........OK"<<std::endl;
    }

    ~Workspace()
    {
        free_tableau();
    }
    void Set_tableau()
    {
        _tableau = (Bloc **)malloc(NB_LIGNES * sizeof(Bloc *));
        for (int i = 0; i < NB_LIGNES; i++)
            _tableau[i] = (Bloc*)malloc(NB_COL * sizeof(Bloc));
        for(int i=0;i<NB_LIGNES;i++){
            for(int j=0;j<NB_COL;j++){
                Bloc tmp(i,j,false);
                _tableau[i][j] = tmp;
            }
        }
    }
    void free_tableau()
    {
        for (int i = 0; i < NB_LIGNES; i++)
            free(_tableau[i]);
        free(_tableau);

    }
    Bloc **tableau(){
        return _tableau;
    }
    void setTableau(int i,int j,Bloc bloc){
        _tableau[i][j]= bloc;
    }
    void afficher(int x,int y);
    void switch_piece(Piece *next);
    void ajouter_piece(Piece courante);
    int compte_ligne(int ligne);
    void detruire_ligne(int ligne);
    void descendre(Piece courante);
    void tourner(Piece courante);
    void moveG(Piece courante);
    void moveD(Piece courante);
protected:
private:
    Bloc **_tableau;
};

#endif // WORKSPACE_H
