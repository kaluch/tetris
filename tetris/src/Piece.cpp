#include "../include/Piece.h"

using namespace std;

/*
Piece::Piece()
{
    //dtor
}
*/

void Piece::afficher(){
	glBegin(GL_QUADS);
		glColor3ub(rColor(),gColor(),bColor());
		glVertex2d(x()-LARGEUR/2,y()-HAUTEUR/2);
		glVertex2d(x()-LARGEUR/2,y()+HAUTEUR/2);
		glVertex2d(x()+LARGEUR/2,y()-HAUTEUR/2);
		glVertex2d(x()+LARGEUR/2,y()+HAUTEUR/2);
	glEnd();

}

