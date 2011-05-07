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
        Menu(): _nb_joueur(0){
            std::cerr<<"constr menu"<<std::endl;
        }
        ~Menu(){}

        void afficher();
        void afficherEntree();
        void afficherNbjoueur();
        void afficherChiffre(int chiffre,int x,int y);
        void gestion_event(SDL_Event event,bool *continuer);
        void lancer_menu();
        int nb_joueur(){ return _nb_joueur;}


    protected:
        SDL_Event _event;
        int _nb_joueur;
    private:
};

#endif // MENU_H
