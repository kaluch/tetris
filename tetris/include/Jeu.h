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
#include "../globale.h"


#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <errno.h>
#include <time.h>
#include <typeinfo>


class Jeu
{
public:
    Jeu(int nb_joueurs)
    {
        std::cerr<<"constr jeu"<<std::endl;
        std::cerr<<"init joueurs"<<std::endl;
        std::ostringstream out;

        for (int i = 0; i < nb_joueurs; i++){
            std::cerr<<"ajout j"<<i<<std::endl;
            _humains.push_back(Humain("j",i));
            std::cerr<<"joueur cree n°: "<<i<<std::endl;
        }
        std::cerr<<"ajout IA"<<nb_joueurs<<std::endl;
        _computers.push_back(Computer("j",nb_joueurs,0));
        std::cerr<<"joueur cree n°: "<<nb_joueurs<<std::endl;

        std::cerr<<"init joueurs ...........OK"<<std::endl;
        init_SDL(_screen);
        lancer_jeu();

    }
    ~Jeu(){}

    void init_SDL(SDL_Surface *screen);
    void afficher();
    void lancer_jeu();
    void tester_fin();
    void gestion_event(SDL_Event event, bool *continuer);
    std::vector<Humain> humains(){
        return _humains;
        }
    std::vector<Computer> computers(){
            return _computers;
            }

protected:
    std::vector<Humain> _humains;
    SDL_Surface *_screen;
    SDL_Event _event;
    std::vector<Computer> _computers;
};

#endif /* JEU_H_ */
