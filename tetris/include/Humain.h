#ifndef HUMAIN_H
#define HUMAIN_H

#include <SDL/SDL.h>
#include <iostream>
#include "Joueur.h"

class Humain : public Joueur
{
    public:
        Humain(std::string name,int id) : Joueur(name, id){

        if(id == 0)
            charger_touches(SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT);
        else if(id == 1)
            charger_touches(SDLK_w,SDLK_s,SDLK_a,SDLK_d);
        else if(id == 2)
            charger_touches(SDLK_i,SDLK_k,SDLK_j,SDLK_l);
        }

    void charger_touches(int tUP, int tDown,int tLeft,int tRight);

    //ACCESSEURS
    int toucheUp(){ return _toucheUp;}
    int toucheDown(){ return _toucheDown;}
    int toucheLeft(){ return _toucheLeft;}
    int toucheRight(){ return _toucheRight;}
    void setUp(int val){ _toucheUp = val;}
    void setDown(int val){ _toucheDown = val;}
    void setLeft(int val){ _toucheLeft = val;}
    void setRight(int val){ _toucheRight = val;}

    bool lastUp(){return _lastUp;}

    int lastDown(){return _lastDown;}
    int lastLeft(){return _lastLeft;}
    int lastRight(){return _lastRight;}
    void setLastUp(bool val){ _lastUp = val;    }
    void setLastDown(int val){ _lastDown = val;}
    void setLastLeft(int val){ _lastLeft = val;}
    void setLastRight(int val){ _lastRight = val;}

    protected:
    bool _cpu;
    int _toucheUp;
    int _toucheDown;
    int _toucheLeft;
    int _toucheRight;
    bool _lastUp;
    int _lastDown;
    int _lastLeft;
    int _lastRight;
    int _cmp;
    private:
};

#endif // HUMAIN_H
