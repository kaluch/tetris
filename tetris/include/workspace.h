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
        Set_nb_col(10);
        Set_nb_lignes(20);
        Set_tableau();
        std::cerr<<"...........OK"<<std::endl;
    }

    ~Workspace()
    {
        free_tableau();
    }
    int nb_col()
    {
        return _nb_col;
    }
    void Set_nb_col(const int& val)
    {
        _nb_col = val;
    }
    int nb_lignes()
    {
        return _nb_lignes;
    }
    void Set_nb_lignes(const int& val)
    {
        _nb_lignes = val;
    }
    void Set_tableau()
    {
        _tableau = (Bloc **)malloc(_nb_lignes * sizeof(Bloc *));
        for (int i = 0; i < nb_lignes(); i++)
            _tableau[i] = (Bloc*)malloc(_nb_col * sizeof(Bloc));
        for(int i=0;i<nb_lignes();i++){
            for(int j=0;j<nb_col();j++){
                Bloc tmp(i,j,false);
                _tableau[i][j] = tmp;
            }
        }
    }
    void free_tableau()
    {
        for (int i = 0; i < _nb_lignes; i++)
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
    int _nb_col;
    int _nb_lignes;
    Bloc **_tableau;
};

#endif // WORKSPACE_H
