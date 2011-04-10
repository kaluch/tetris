/*
 * Jeu.cpp
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */

#include "../include/Jeu.h"

void Jeu::init_SDL(SDL_Surface *screen) {
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL);
	SDL_WM_SetCaption("TETRIS SOUCHET DIGNOIRE 2011", NULL);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluOrtho2D(0,LARGEUR_ECRAN,0,HAUTEUR_ECRAN);
}

void Jeu::afficher() {
	for (unsigned int i = 0; i < _joueurs.size(); i++)
		_joueurs[i].afficher(i);
}

void Jeu::lancer_jeu(){
	bool continuer = true;
	int tmp;
	while(continuer)
	{
		switch(tmp = gestion_event(_event)){
		case 0:
			continuer = false;
			break;
		/*case 1:
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
		break;*/
		default:
            break;
		}
		afficher();
		        glFlush();
        SDL_GL_SwapBuffers();

	}
}

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
		default:
			break;
		}
	}
}
