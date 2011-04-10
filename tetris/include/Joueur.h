
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
public:
    Joueur(std::string name)
    {
        _nom = name;
        _score = 0;
        _workspace = Workspace();
        _nb_next = 1;
        init_next_piece();
        _piece_courante = Piece();
        //_workspace.s

    }
    ~Joueur() {}
    void init_next_piece();
    void changer_pieces();
    void afficher(int i);
protected:
    std::string _nom;
    int _score;
    Workspace _workspace;
    Piece *_next_piece;
    int _nb_next;
    Piece _piece_courante;
private:
};

#endif // JOUEUR_H
