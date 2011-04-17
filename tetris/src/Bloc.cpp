#include "../include/Bloc.h"

using namespace std;

void Bloc::afficher()
{
    //glPushMatrix();
    //glTranslated(x,y,0);

    if(!vide())
    {

        glBegin(GL_QUADS);

        glColor3ub(rColor(),gColor(),bColor());

        glVertex2d(x()-LARGEUR_BLOC/2,y()+HAUTEUR_BLOC/2);
        printf("vertice 2 : %d %d ",x()-LARGEUR_BLOC/2,y()+HAUTEUR_BLOC/2);
        glVertex2d(x()-(LARGEUR_BLOC/2),y()-HAUTEUR_BLOC/2);
        printf("vertice 1 : %d %d ",x()-LARGEUR_BLOC/2,y()-HAUTEUR_BLOC/2);
        glVertex2d(x()+LARGEUR_BLOC/2,y()-HAUTEUR_BLOC/2);
        printf("vertice 3 : %d %d ",x()+LARGEUR_BLOC/2,y()-HAUTEUR_BLOC/2);
        glVertex2d(x()+LARGEUR_BLOC/2,y()+HAUTEUR_BLOC/2);
        printf("vertice 4 : %d %d\n",x()+LARGEUR_BLOC/2,y()+HAUTEUR_BLOC/2);/**/
        glEnd();
    }
}
