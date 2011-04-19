#include "../include/workspace.h"
#include "../globale.h"


void Workspace::afficher(int x,int y)
{
	std::cerr << "affichage workspace joueur" << std::endl;

	glBegin(GL_LINE_LOOP);
    glColor3ub(0,255,255);
    glVertex2d(x,y);
    glVertex2d(x,y+NB_LIGNES*HAUTEUR_BLOC);
    glVertex2d(x+NB_COL*LARGEUR_BLOC,y+NB_LIGNES*HAUTEUR_BLOC);
    glVertex2d(x+NB_COL*LARGEUR_BLOC,y);
    glEnd();

    //glTranslated(x,y,0);
    /*glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluOrtho2D(x,LARGEUR_WS,y,HAUTEUR_WS);*/
}

void Workspace::switch_piece(Piece *next){
	next->setX(NB_COL/2);
	next->setY(NB_LIGNES+1);
}


int Workspace::compte_ligne(int ligne){
    int cpt = 0;
    for(int i=0;i<NB_COL;i++){
        if(!tableau()[ligne][i].vide())
            cpt++;
    }
    return cpt;
}

void Workspace::detruire_ligne(int ligne){
    for(int i=ligne;i<NB_LIGNES-1;i++)
        for(int j=0;j<NB_COL;j++)
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
        std::cerr<<"index tab : "<<courante.blocs()[i].y()<<" "<<courante.blocs()[i].x()+1<<std::endl;
        if(courante.blocs()[i].x() >= NB_COL || !tableau()[courante.blocs()[i].y()][courante.blocs()[i].x()+1].vide())
            move = false;
    }
    if(move)
        courante.moveD();

}
