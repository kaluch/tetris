
#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Piece.h"
#include "workspace.h"

class Joueur
{
    protected:
    std::string _nom;
    int _id_joueur;
    int _score;
    Workspace _workspace;
    int _nb_next;
    std::vector<Piece> _next_piece;
    Piece _piece_courante;
public:
    Joueur(std::string name,int id) :_nom(name), _id_joueur(id),_score(0)
    ,_workspace(),_nb_next(1),_next_piece(_nb_next),_piece_courante()
    {
        std::cerr<<"creation joueur "<<name<<std::endl;
        std::cerr<<"init next"<<std::endl;
        init_next_piece();
        std::cerr<<"fin init next"<<std::endl;
        std::cerr<<"fin creation "<< std::endl;
        //_workspace.s

    }
    void init_next_piece();
    void changer_pieces();
    void afficher();
    std::string nom() const {return _nom;}
    Piece piece_courante(){
        return _piece_courante;
    }
    Piece *next_p(){
        return &_next_piece[0];
    }
    Workspace workspace(){return _workspace;}
    void gestion_piece_courante();
    void poser_piece();
    void move();
    void traitement_workspace();
    int score(){return _score;}
    void setScore(int val){_score = val;}

    int id_joueur(){return _id_joueur;}
    int nb_next(){return _nb_next;}
    std::vector<Piece> next_piece(){return _next_piece;}

};

#endif // JOUEUR_H
