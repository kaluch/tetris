#ifndef COMPUTER_H
#define COMPUTER_H

#include "Joueur.h"


class Computer : public Joueur
{
    public:
        Computer(std::string name,int id,int ia): Joueur(name,id), _ia(ia){std::cerr<<"computer cree "<<std::endl;}
        void move();
        void idiot();
        void intelligent();
        int ia(){return _ia;}
        void setIa(int val){_ia=val;}
    private:
        int _ia;

};

#endif // COMPUTER_H
