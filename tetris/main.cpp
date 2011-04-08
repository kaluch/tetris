#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "include/Piece.h"
#include "globale.h"
using namespace std;

/*SDL
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);

    pause();

    SDL_Quit();

    return EXIT_SUCCESS;
}*/


/*OpenGL*/

int main(int argc, char *argv[])
{
	SDL_Surface *screen;
	SDL_Init(SDL_INIT_VIDEO);

	 screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32,SDL_OPENGL);
	    SDL_WM_SetCaption("Ma super fenêtre OpenGL !", NULL);

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluOrtho2D(0,LARGEUR_ECRAN,0,HAUTEUR_ECRAN);

    bool continuer = true;
    SDL_Event event;
    Piece p1(1,255,0,0);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = false;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        p1.afficher();

        cout << p1.x() << p1.y() << endl;
        glFlush();
        SDL_GL_SwapBuffers();
    }

    SDL_Quit();

    return 0;
}


