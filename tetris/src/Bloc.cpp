#include "../include/Bloc.h"

using namespace std;

void Bloc::afficher()
{
    if(!vide())
    {
        glBegin(GL_QUADS);
        glColor3ub(rColor(),gColor(),bColor());
        glVertex2d(_x-LARGEUR_BLOC/2,_y+HAUTEUR_BLOC/2);
        glVertex2d(_x-(LARGEUR_BLOC/2),_y-HAUTEUR_BLOC/2);
        glVertex2d(_x+LARGEUR_BLOC/2,_y-HAUTEUR_BLOC/2);
        glVertex2d(_x+LARGEUR_BLOC/2,_y+HAUTEUR_BLOC/2);
        glEnd();

        glBegin(GL_LINE_LOOP),
        glColor3ub(80,80,80);
        glVertex2d(_x-LARGEUR_BLOC/2,_y+HAUTEUR_BLOC/2);
        glVertex2d(_x-(LARGEUR_BLOC/2),_y-HAUTEUR_BLOC/2);
        glVertex2d(_x+LARGEUR_BLOC/2,_y-HAUTEUR_BLOC/2);
        glVertex2d(_x+LARGEUR_BLOC/2,_y+HAUTEUR_BLOC/2);
        glEnd();
   }
}
