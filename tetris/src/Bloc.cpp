#include "../include/Bloc.h"

using namespace std;

void Bloc::afficher()
{
    //glPushMatrix();
    //glTranslated(x,y,0);
    if(!vide())
    {
        //std::cerr<<"vide == faux"<<std::endl;
        glBegin(GL_QUADS);
        glColor3ub(rColor(),gColor(),bColor());

        glVertex2d(_x-LARGEUR_BLOC/2,_y+HAUTEUR_BLOC/2);
        //std::cerr<<"vertice 2"<<x()-LARGEUR_BLOC/2<<y()+HAUTEUR_BLOC/2<<std::endl;

        glVertex2d(_x-(LARGEUR_BLOC/2),_y-HAUTEUR_BLOC/2);
        //std::cerr<<"vertice 1"<<x()-LARGEUR_BLOC/2<<y()-HAUTEUR_BLOC/2<<std::endl;

        glVertex2d(_x+LARGEUR_BLOC/2,_y-HAUTEUR_BLOC/2);
        //std::cerr<<"vertice 3"<<x()+LARGEUR_BLOC/2<<y()-HAUTEUR_BLOC/2<<std::endl;

        glVertex2d(_x+LARGEUR_BLOC/2,_y+HAUTEUR_BLOC/2);
        //std::cerr<<"vertice 4"<<x()+LARGEUR_BLOC/2<<y()+HAUTEUR_BLOC/2<<std::endl;

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
