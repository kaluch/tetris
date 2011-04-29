#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <iostream>
#include <stdlib.h>
#include "Piece.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../globale.h"

class Workspace
{
public:
    Workspace(int id)
    {
        std::cerr<<"constr ws()";
        //Set_nb_col(10);
        //Set_nb_lignes(20);
        _nb_col = NB_COL;
        _nb_lignes = NB_LIGNES;

        Set_tableau(NB_LIGNES,NB_COL,id);
        //_tableau[NB_COL][NB_LIGNES];        std::cerr<<"...........OK"<<std::endl;
    }
    Workspace(){}
    ~Workspace()
    {
        //free_tableau();
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
    /*void Set_tableau()
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
    }*/

    void setTableau(int i,int j,Bloc bloc){
        _tableau[i][j]= bloc;
    }

    void Set_tableau(int nbLigne,int nbCol,int id)
    {
        _tableau.resize(nbLigne+2);
        for(int i=0; i<nbLigne+2; i++)
        {
            _tableau[i].resize(nbCol);
            for(int j=0; j<nbCol; j++)
            {
                _tableau[i][j] = Bloc(30+LARGEUR_BLOC*j+(100+LARGEUR_BLOC * NB_COL)*id,30+LARGEUR_BLOC*i,false);
            }
        }
    }

    std::vector<std::vector< Bloc > > tableau()
    {
        return _tableau;
    }

    void afficher(int x,int y);
    void afficher_tableau();
    void switch_piece(Piece *next);
    void ajouter_piece(Piece *courante);
    void afficher_tab_nonvide();
    int compte_ligne(int ligne);
    void detruire_ligne(int ligne);
    void descendre(Piece *courante);
    void tourner(Piece *courante);
    void moveG(Piece *courante);
    void moveD(Piece *courante);
protected:
private:
    int _nb_col;
    int _nb_lignes;
    //Bloc **_tableau;
    std::vector< std::vector< Bloc > > _tableau;
};

#endif // WORKSPACE_H
