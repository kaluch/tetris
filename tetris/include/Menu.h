#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <sstream>
#include <SDL/SDL.h>
#include "../globale.h"
#include "sdlglutils.h"
#include <GL/gl.h>
#include <GL/glu.h>

class Menu
{
    public:
        Menu(): _nb_joueur(1), _nb_cpu(1), _select(false){
            std::cerr<<"constr menu"<<std::endl;
        }
        ~Menu(){}

        void afficher();
        void afficherEntree();
        void afficherLogo();
        void afficherNbjoueur();
        void afficherChiffre(int chiffre,int x,int y);
        void gestion_event(SDL_Event event,bool *continuer);
        void lancer_menu();

        void switch_menu();

    //ACCESSEURS
        int nb_joueur(){ return _nb_joueur;}
        void setNbJoueur(int val){_nb_joueur = val;}
        int nb_cpu(){ return _nb_cpu;}
        void setNbCpu(int val){_nb_cpu = val;}
        bool select(){return _select;}
        void setSelect(bool val){ _select = val;}

    protected:
        SDL_Event _event;
        int _nb_joueur;
        int _nb_cpu;
        bool _select;
    private:
};

#endif // MENU_H
