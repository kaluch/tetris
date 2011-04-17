/*
 * Jeu.cpp
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */

#include "../include/Jeu.h"


void Jeu::init_SDL(SDL_Surface *screen) {
	std::cerr << "init SDL";
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL);
	SDL_WM_SetCaption("TETRIS SOUCHET DIGNOIRE 2011", NULL);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluOrtho2D(0,LARGEUR_ECRAN,0,HAUTEUR_ECRAN);
	std::cerr << ".................OK"<<std::endl;
}

void Jeu::afficher() {
	for (unsigned int i = 0; i < _joueurs.size(); i++)
		_joueurs[i].afficher();
}

void Jeu::lancer_jeu(){
	std::cerr<<"Debut de la partie"<<std::endl;
	bool continuer = true;
	while(continuer)
	{
		gestion_event(_event,&continuer);
		for(unsigned int i=0;i<joueurs().size();i++){
            joueurs()[i].gestion_piece_courante();
            joueurs()[i].traitement_workspace();
            joueurs()[i].move();
		}

		afficher();
		//glFlush();
        SDL_GL_SwapBuffers();

	}
}

void Jeu::gestion_event(SDL_Event event,bool *continuer) {
	SDL_WaitEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		*continuer = false;
		break;
	case SDL_KEYDOWN:
		switch(event.key.keysym.sym){
		case SDLK_UP:
			std::cerr<<"Tourner"<<std::endl;
			joueurs()[0].workspace().tourner(joueurs()[0].piece_courante());
			break;
		case SDLK_DOWN:
			std::cerr<<"Descendre"<<std::endl;
			joueurs()[0].workspace().descendre(joueurs()[0].piece_courante());
			break;
		case SDLK_LEFT:
			std::cerr<<"Left"<<std::endl;
			joueurs()[0].workspace().moveG(joueurs()[0].piece_courante());
			break;
		case SDLK_RIGHT:
			std::cerr<<"Right"<<std::endl;
			joueurs()[0].workspace().moveD(joueurs()[0].piece_courante());
			break;
		default:
			break;
		}
	}
}
