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
#include "../globale.h"


#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
class Jeu
{
public:
    Jeu(int nb_joueurs)
    {
        std::cerr<<"constr jeu"<<std::endl;
        _joueurs = std::vector<Joueur>();
        std::cerr<<"init joueurs"<<std::endl;
        std::ostringstream out;

        for (int i = 0; i < nb_joueurs; i++){
            std::cerr<<"ajout j"<<i<<std::endl;
            out << i;

            //Joueur tmp("j"+out.str(),i);
            std::cerr<<"joueur cr��"<<std::endl;
            _joueurs.push_back(Joueur("j",i));
            std::cerr<<i<<std::endl;
        }
        std::cerr<<"init joueurs ...........OK"<<std::endl;
        init_SDL(_screen);
        lancer_jeu();

    }
    ~Jeu() {}

    void init_SDL(SDL_Surface *screen);
    void afficher();
    void lancer_jeu();
    void gestion_event(SDL_Event event, bool *continuer);
    std::vector<Joueur> joueurs(){
        return _joueurs;
        }

protected:
    std::vector<Joueur> _joueurs;
    SDL_Surface *_screen;
    SDL_Event _event;
};

#endif /* JEU_H_ */