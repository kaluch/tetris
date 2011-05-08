/*
 * Jeu.h
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */
#ifndef JEU_H_
#define JEU_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <SDL/SDL.h>
#include "Joueur.h"
#include "Computer.h"
#include "Humain.h"
#include "Menu.h"
#include "../globale.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <errno.h>
#include <time.h>
#include <typeinfo>
#include "sdlglutils.h"

class Jeu
{
public:

    Jeu(int nb_joueurs):_menu()
    {
        std::cerr<<"constr jeu"<<std::endl;
        std::ostringstream out;

        int ia = 1;

        init_SDL(_screen);
        _menu.lancer_menu();
        std::cerr<<"init joueurs"<<std::endl;
        nb_joueurs = _menu.nb_joueur();
        for (int i = 0; i < nb_joueurs; i++)
        {
            std::cerr<<"ajout j"<<i<<std::endl;
            _humains.push_back(Humain("j",i));
            std::cerr<<"joueur cree n°: "<<i<<std::endl;
        }
        int nb_cpu = _menu.nb_cpu();
        for (int i = 0; i < nb_cpu; i++)
        {
            std::cerr<<"ajout IA"<<nb_joueurs+i<<std::endl;
            _computers.push_back(Computer("j",nb_joueurs+i,ia));
            std::cerr<<"Computer cree n°: "<<nb_joueurs+i<<std::endl;
        }

        std::cerr<<"init joueurs ...........OK"<<std::endl;

        lancer_jeu();
    }

    void init_SDL(SDL_Surface *screen);
    void afficherFond(int x,int y);
    void afficherPerdu(int x,int y);
    void afficherScore(int id,int score);
    void afficherChiffre(int x,int y,int chiffre);
    void afficher();
    void lancer_jeu();
    void tester_fin();
    void gestion_event(SDL_Event event, bool *continuer);
    std::vector<Humain> humains()
    {
        return _humains;
    }
    std::vector<Computer> computers()
    {
        return _computers;
    }

    void lancer_handicap(int id_joueur);


protected:
    std::vector<Humain> _humains;
    SDL_Surface *_screen;
    SDL_Event _event;
    std::vector<Computer> _computers;
    Menu _menu;
};

#endif /* JEU_H_ */
