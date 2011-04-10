#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "include/Piece.h"
using namespace std;

/*SDL*/
int main(int argc, char *argv[]) {
	printf("Coucou");
	/*SDL_Init(SDL_INIT_VIDEO);
	SDL_Event event;
	SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);
	bool continuer = true;
	while (continuer)//pause();
	{

	}

	SDL_Quit();
*/
	return EXIT_SUCCESS;
}

/*OpenGL

 int main(int argc, char *argv[])
 {

 SDL_Init(SDL_INIT_VIDEO);

 SDL_SetVideoMode(640, 480, 32,SDL_HWSURFACE);//TODO afficher fenetre opengl
 SDL_WM_SetCaption("Ma super fenetre OpenGL !", NULL);

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
 glFlush();
 SDL_GL_SwapBuffers();
 }

 SDL_Quit();

 return 0;
 }*/

