
#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>

#include "Piece.h"
#include "workspace.h"

class Joueur
{
    public:
        Joueur(std::string name);
        virtual ~Joueur();
        void init_next_piece();
        void changer_pieces();
        void afficher();
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
