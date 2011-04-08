/*
 * Jeu.cpp
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */

#include "../include/Jeu.h"

Jeu::Jeu(int nb_joueurs) {
	_joueurs = std::vector<Joueur>();
	for (int i = 0; i < nb_joueurs; i++)
		_joueurs.push_back(Joueur("j" + i));
	init_SDL(_screen);
	afficher();
	lancer_jeu();

}

Jeu::~Jeu() {
	// TODO Auto-generated destructor stub
}

void Jeu::init_SDL(SDL_Surface *screen) {
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL);
	SDL_WM_SetCaption("TETRIS SOUCHET DIGNOIRE 2011", NULL);
}

void Jeu::afficher() {
	for (unsigned int i = 0; i < _joueurs.size(); i++)
		;//_joueurs[i].afficher();
}

void Jeu::lancer_jeu(){
	bool continuer = true;
	int tmp;
	while(continuer)
	{
		/*switch(tmp = gestion_event(_event)){
		case 0:
			continuer = false;
			break;
		case 1:
			piece_courante().tourner();
			break;
		case 2:
			piece_courante().descendre();
			break;
		case 3:
			piece_courante().moveG();
			break;
		case 4:
			piece_courante().moveR();
			break;
		}*/
		continuer = true;
	}
}
/*
int Jeu::gestion_event(SDL_Event event) {
	SDL_WaitEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		return 0;
	case SDL_KEYDOWN:
		switch(event.key.keysym.sym){
		case SDLK_UP:
			return 1;
		case SDLK_DOWN:
			return 2;
		case SDLK_LEFT:
			return 3;
		case SDLK_RIGHT:
			return 4;
		}
	}
}*/
