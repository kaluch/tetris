#include "../include/workspace.h"
#include "../globale.h"


void Workspace::afficher(int x,int y)
{
    //std::cerr << "affichage workspace joueur" << std::endl;
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,255,255);
    glVertex2d(x,y);
    glVertex2d(x,y+HAUTEUR_WS);
    glVertex2d(x+LARGEUR_WS,y+HAUTEUR_WS);
    glVertex2d(x+LARGEUR_WS,y);
    glEnd();

}

void Workspace::afficher_tableau()
{
    for(int i=0; i<nb_lignes(); i++)
    {
        for(int j=0; j<nb_col(); j++)
        {
            _tableau[i][j].afficher();
        }
    }
}

void Workspace::switch_piece(Piece *next)
{
    //std::cerr<<"Switch_piece.........x = "<<next->x()<<" y = "<<next->y()<<std::endl;
    next->translateX(-150);
    //std::cerr<<".........x = "<<next->x()<<" y = "<<next->y()<<std::endl;
}


int Workspace::compte_ligne(int ligne)
{
    int cpt = 0;
    for(int i=0; i<nb_col(); i++)
    {
        if(!_tableau[ligne][i].vide())
            cpt++;
    }
    return cpt;
}

void Workspace::detruire_ligne(int ligne)
{
    std::cerr<<".........detruire ligne......... "<<ligne<<std::endl;
    for(int i=ligne; i<nb_lignes()-1; i++)
    {
        for(int j=0; j<nb_col(); j++)
        {
            _tableau[i+1][j].setY(_tableau[i+1][j].y() - 20);
            setTableau(i, j,_tableau[i+1][j]);
        }
    }
}

void Workspace::ajouter_piece(Piece *courante)
{
    for(int i=0; i<4; i++)
    {
        _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()] = courante->blocs()[i];
    }
    //std::cerr<<"...................ajouter piece................."<<std::endl;
    afficher_tab_nonvide();
}
void Workspace::afficher_tab_nonvide()
{
    for(int i=0; i<nb_lignes(); i++)
    {
        for(int j=0; j<nb_col(); j++)
        {
            if(_tableau[i][j].vide())
            {
                std::cerr<<0<<" ";
            }
            else std::cerr<<1<<" ";

        }
        std::cerr<<std::endl;
    }
}
void Workspace::tourner(Piece *courante)
{
    bool move = true;
    for(int i=0;i<4;i++){
        if( ! _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()-1].vide() || ! _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()+1].vide() || courante->blocs()[i].yws()== nb_lignes()-1)
            move = false;
    }
    if(move)
    courante->tourner();
}

void Workspace::descendre(Piece *courante)
{
    //if(courante->y()> 40)
    courante->descendre();
}

void Workspace::moveG(Piece *courante)
{
    bool move = true;
    for(int i=0;i<4;i++){
        if( ! _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()-1].vide())
            move = false;
    }
    if(move)
        courante->moveG();

}

void Workspace::moveD(Piece *courante)
{
    bool move = true;
    for(int i=0;i<4;i++){
        if(! _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()+1].vide())
            move = false;
    }
    if(move)
        courante->moveD();

}
