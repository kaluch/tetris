
#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <time.h>
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Piece.h"
#include "workspace.h"
#include "sdlglutils.h"


class Joueur
{
protected:
    std::string _nom;
    int _id_joueur;
    int _score;
    Workspace _workspace;
    int _nb_next;
    std::vector<Piece> _next_piece;
    Piece* _piece_courante;
    bool _play;
    int _cmp;
    int _speed;
    int _cmpSpeed;
    int _nb_handicap;
    int _reserveHandicap;

public:
    Joueur(std::string name,int id) :_nom(name), _id_joueur(id),_score(0)
        ,_workspace(id),_nb_next(3),_next_piece(_nb_next),_piece_courante(),_play(true),_cmp(80),_speed(80),_cmpSpeed(0), _nb_handicap(0), _reserveHandicap(0)
    {
        std::cerr<<"creation joueur "<<name<<std::endl;
        _piece_courante = new Piece();
        _piece_courante->translateX(_id_joueur*(100+LARGEUR_BLOC * NB_COL));

        init_next_piece();
        std::cerr<<"fin creation "<< std::endl;
        //_workspace.s

    }
//    ~Joueur(){
//        delete(_piece_courante);
//    }
            void init_next_piece();
    void init_next();
    void sleep(unsigned int mseconds);
    void changer_pieces();
    void afficher();
     void gestion_piece_courante();
    void poser_piece();
    void move();
    void traitement_workspace();
    std::string nom() const{return _nom;}
    Piece* piece_courante(){return _piece_courante;   }
    Piece next_p()    {return _next_piece[0];}
    Workspace workspace()    {return _workspace;    }
    int score()    {        return _score;    }
    void setScore(int val)    {        _score = val;    }
    int cmp()    {        return _cmp;    }
    void setCmp(int val)    {        _cmp = val;    }
    int speed()    {        return _speed;    }
    void setSpeed(int val)    {        _speed = val;    }
    int cmpSpeed()    {        return _cmpSpeed;    }
    void setCmpSpeed(int val)    {       _cmpSpeed = val;    }
    int id_joueur()    {        return _id_joueur;    }
    int nb_next()    {        return _nb_next;    }
    std::vector<Piece> next_piece(){        return _next_piece;    }

    int nb_handicap(){ return _nb_handicap;}
    void setHandicap(int val){ _nb_handicap = val;}
    int reserveHandicap(){return _reserveHandicap;}
    void setReserveHandicap(int val){_reserveHandicap =val;}

    void ajouterHandicap();
    void retirerHandicap();

    void setPlay(bool play){ _play = play;}
    bool play(){return _play;}

};

#endif // JOUEUR_H
