#include <iostream>

#include "../include/workspace.h"
#include "../globale.h"


void Workspace::afficher(int x,int y)
{
	std::cerr << "affichage workspace joueur" << std::endl;

	glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex2d(x,y);
    printf("vertice 2 : %d %d ",x,y);
    glVertex2d(x,y+HAUTEUR_WS);
    printf("vertice 1 : %d %d ",x,y+HAUTEUR_WS);
    glVertex2d(x+LARGEUR_WS,y+HAUTEUR_WS);
    printf("vertice 3 : %d %d ",x+LARGEUR_WS,y+HAUTEUR_WS);
    glVertex2d(x+LARGEUR_WS,y);
    printf("vertice 4 : %d %d\n",x+LARGEUR_WS,y);
    glEnd();

    //glTranslated(x,y,0);
    /*glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluOrtho2D(x,LARGEUR_WS,y,HAUTEUR_WS);*/
}
/*
void Workspace::switch_piece(Piece next, Piece courante){
	ajouter_Piece(courante);
}*/
