#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "include/Jeu.h"
#include "include/Piece.h"
#include "globale.h"
#include "include/workspace.h"
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
	SDL_Surface *screen;
	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL);
	SDL_WM_SetCaption("Ma super fenêtre OpenGL !", NULL);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, LARGEUR_ECRAN, 0, HAUTEUR_ECRAN);

	bool continuer = true;
	SDL_Event event;
	//Jeu jeu(1);
	Joueur j1("j1");
	Joueur j2("j2");
	//Workspace ws;
	/*
	 Piece p0(0,255,0,0);
	 Piece p1(1,255,0,0);
	 Piece p2(2,255,0,0);
	 Piece p3(3,255,0,0);
	 Piece p4(4,255,0,0);
	 Piece p5(5,255,0,0);
	 Piece p6(6,255,0,0);*/

	//glTranslated(LARGEUR_ECRAN/2,HAUTEUR_ECRAN/2,0);

	while (continuer) {
		SDL_WaitEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			continuer = false;
		}

		glClear(GL_COLOR_BUFFER_BIT);
		j1.afficher(0);
		j2.afficher(1);
		//ws.afficher(20,20);
		/*p0.afficher();
		 p1.afficher();
		 p2.afficher();
		 p3.afficher();
		 p4.afficher();
		 p5.afficher();*/
		//p6.afficher();
		//dessinerRepere(10);
		//std::cout << p6.x() << p6.y() << std::endl;

		glFlush();
		SDL_GL_SwapBuffers();
	}

	SDL_Quit();

	return 0;
}

