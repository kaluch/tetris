#include "../include/Piece.h"
#include <iostream>
#include "stdio.h"


using namespace std;

/*
Piece::Piece()
{
    //dtor
}
*/

void Piece::afficher(){
	glPushMatrix();
	//glTranslated(+LARGEUR_ECRAN/2,+HAUTEUR_ECRAN/2,0);
	glBegin(GL_TRIANGLE_STRIP);

		glColor3ub(rColor(),gColor(),bColor());

		glVertex2d(x()-(LARGEUR/2),y()-HAUTEUR/2);
		printf("vertice 1 : %d %d ",x()-LARGEUR/2,y()-HAUTEUR/2);
		glVertex2d(x()-LARGEUR/2,y()+HAUTEUR/2);
		printf("vertice 2 : %d %d ",x()-LARGEUR/2,y()+HAUTEUR/2);
		glVertex2d(x()+LARGEUR/2,y()-HAUTEUR/2);
		printf("vertice 3 : %d %d ",x()+LARGEUR/2,y()-HAUTEUR/2);
		glVertex2d(x()+LARGEUR/2,y()+HAUTEUR/2);
		printf("vertice 4 : %d %d\n",x()+LARGEUR/2,y()+HAUTEUR/2);/**/
	glEnd();

}

