#ifndef COMPUTER_H
#define COMPUTER_H
#include "../globale.h"
#include "Joueur.h"


class Computer : public Joueur
{
    public:
        Computer(std::string name,int id,int ia): Joueur(name,id), _ia(ia){
            _speed=30;
            std::cerr<<"computer cree "<<std::endl;}
        void move();
        void idiot();
        void intelligent();
        void simtourner(Piece *courante,int ymin);
        //ACCESSEURS
        int ia(){return _ia;}
        void setIa(int val){_ia=val;}
    private:
        int _ia;
};
#endif // COMPUTER_H
