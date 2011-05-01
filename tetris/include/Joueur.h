
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
    bool _cpu;
    int _toucheUp;
    int _toucheDown;
    int _toucheLeft;
    int _toucheRight;
    bool _lastUp;
    bool _lastDown;
    bool _lastLeft;
    bool _lastRight;

public:
    Joueur(std::string name,int id) :_nom(name), _id_joueur(id),_score(0)
        ,_workspace(id),_nb_next(3),_next_piece(_nb_next),_piece_courante(),_play(true),_cmp(0),_speed(80),_cmpSpeed(0)
    {
        std::cerr<<"creation joueur "<<name<<std::endl;
        _piece_courante = new Piece();
        _piece_courante->translateX(_id_joueur*(100+LARGEUR_BLOC * NB_COL));

        init_next_piece();
        if(id == 0)
            charger_touches(SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT);
        else if(id == 1)
            charger_touches(SDLK_w,SDLK_s,SDLK_a,SDLK_d);
        std::cerr<<"fin creation "<< std::endl;
        //_workspace.s

    }
    Joueur() {}
    ~Joueur() {}

    void init_next_piece();
    void init_next();
    void sleep(unsigned int mseconds);
    void changer_pieces();
    void afficher();
     void gestion_piece_courante();
    void poser_piece();
    void move();
    void traitement_workspace();
    void charger_touches(int tUP, int tDown,int tLeft,int tRight);

    std::string nom() const
    {
        return _nom;
    }
    Piece* piece_courante()
    {
        return _piece_courante;
    }
    Piece next_p()
    {
        return _next_piece[0];
    }
    Workspace workspace()
    {
        return _workspace;
    }
    int score()
    {
        return _score;
    }
    void setScore(int val)
    {
        _score = val;
    }
    int cmp()
    {
        return _cmp;
    }
    void setCmp(int val)
    {
        _cmp = val;
    }
    int speed()
    {
        return _speed;
    }
    void setSpeed(int val)
    {
        _speed = val;
    }
    int cmpSpeed()
    {
        return _cmpSpeed;
    }
    void setCmpSpeed(int val)
    {
        _cmpSpeed = val;
    }
    int id_joueur()
    {
        return _id_joueur;
    }
    int nb_next()
    {
        return _nb_next;
    }
    std::vector<Piece> next_piece()
    {
        return _next_piece;
    }
    int toucheUp(){ return _toucheUp;}
    int toucheDown(){ return _toucheDown;}
    int toucheLeft(){ return _toucheLeft;}
    int toucheRight(){ return _toucheRight;}
    void setUp(int val){ _toucheUp = val;}
    void setDown(int val){ _toucheDown = val;}
    void setLeft(int val){ _toucheLeft = val;}
    void setRight(int val){ _toucheRight = val;}

    bool lastUp(){return _lastUp;}
    bool lastDown(){return _lastDown;}
    bool lastLeft(){return _lastLeft;}
    bool lastRight(){return _lastRight;}
    void setLastUp(bool val){ _lastUp = val;
        std::cerr<<"Mutation lastup : "<<_lastUp<<std::endl;
    }
    void setLastDown(bool val){ _lastDown = val;}
    void setLastLeft(bool val){ _lastLeft = val;}
    void setLastRight(bool val){ _lastRight = val;}


    void setPlay(bool play){ _play = play;}
    bool play(){return _play;}

};

#endif // JOUEUR_H
