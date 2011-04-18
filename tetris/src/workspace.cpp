#include "../include/workspace.h"
#include "../globale.h"


void Workspace::afficher(int x,int y)
{
	std::cerr << "affichage workspace joueur" << std::endl;

	glBegin(GL_LINE_LOOP);
    glColor3ub(0,255,255);
    glVertex2d(x,y);
    glVertex2d(x,y+nb_lignes()*HAUTEUR_BLOC);
    glVertex2d(x+LARGEUR_WS,y+nb_lignes()*HAUTEUR_BLOC);
    glVertex2d(x+nb_col()*LARGEUR_BLOC,y);
    glEnd();

    //glTranslated(x,y,0);
    /*glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluOrtho2D(x,LARGEUR_WS,y,HAUTEUR_WS);*/
}

void Workspace::switch_piece(Piece *next){
	next->setX(nb_col()/2);
	next->setY(nb_lignes()+1);
}


int Workspace::compte_ligne(int ligne){
    int cpt = 0;
    for(int i=0;i<nb_col();i++){
        if(!tableau()[ligne][i].vide())
            cpt++;
    }
    return cpt;
}

void Workspace::detruire_ligne(int ligne){
    for(int i=ligne;i<nb_lignes()-1;i++)
        for(int j=0;j<nb_col();j++)
            setTableau(i, j,tableau()[i+1][j]);

}

void Workspace::tourner(Piece courante){
    courante.tourner();
}

void Workspace::descendre(Piece courante){
    if(courante.y()> 1)
        courante.descendre();
}

void Workspace::moveG(Piece courante){
    bool move = true;
    for(int i=0;i<4;i++){
        if(courante.blocs()[i].x() <= 1 || !tableau()[courante.blocs()[i].y()][courante.blocs()[i].x()-1].vide())
            move = false;
    }
    if(move)
        courante.moveG();

}

void Workspace::moveD(Piece courante){
    bool move = true;
    for(int i=0;i<4;i++){
        if(courante.blocs()[i].x() >= nb_col() || !tableau()[courante.blocs()[i].y()][courante.blocs()[i].x()+1].vide())
            move = false;
    }
    if(move)
        courante.moveD();

}
