#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL_ttf.h>

#include "../include/Jeu.h"
#include "../include/Piece.h"
#include "../globale.h"
#include "../include/workspace.h"
using namespace std;

/*void dessinerRepere(unsigned int echelle = 1)
 {
 glPushMatrix();
 glScalef(echelle,echelle,echelle);
 glBegin(GL_LINES);
 glColor3ub(0,0,255);
 glVertex2i(0,0);
 glVertex2i(1,0);
 glColor3ub(0,255,0);
 glVertex2i(0,0);
 glVertex2i(0,1);
 glEnd();
 glPopMatrix();
 }

 */
int main(int argc, char *argv[]) {
//    std::cout<<"Lancement"<<std::endl;
//	SDL_Surface *screen;
//	SDL_Init(SDL_INIT_VIDEO);
//    //TTF_Init();
//    //	police = TTF_OpenFont("varsity_regular.ttf",30);
//    //  SDL_Color Noire =  {0,0,0};
//    //texte = TTF_RenderText_Solid(police,"Lucas",Noire);
//
//	screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL);
//	SDL_WM_SetCaption("Ma super fenÃªtre OpenGL !", NULL);
//   // TTF_Font *police = NULL;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, LARGEUR_ECRAN, 0, HAUTEUR_ECRAN);
//
//	bool continuer = true;
//	SDL_Event event;
//	std::cerr<< "creation Jeu"<<std::endl;
	Jeu jeu(1);
//    Joueur joueur("lucas",1);
//	//Workspace work;
//	std::cerr<<"création JEU OK"<<std::endl;
//
//	//glTranslated(LARGEUR_ECRAN/2,HAUTEUR_ECRAN/2,0);
//
//	while (continuer) {
//		SDL_WaitEvent(&event);
//		switch (event.type) {
//		case SDL_QUIT:
//			continuer = false;
//		}
//		glClear(GL_COLOR_BUFFER_BIT);
//        joueur.afficher();
//        //work.afficher(10,0);
//		glFlush();
//		SDL_GL_SwapBuffers();
//	}
//   // TTF_CloseFont(police);
//	//TTF_Quit();
	SDL_Quit();
	return 0;
}

