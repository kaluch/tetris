#include "../include/workspace.h"
#include "../globale.h"

void Workspace::afficher(int x,int y)
{
    //std::cerr << "affichage workspace joueur" << std::endl;

    /*glBindTexture(GL_TEXTURE_2D,texture);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,1);  glVertex2d(x,y+HAUTEUR_BLOC * NB_LIGNES);
    glTexCoord2d(0,0);  glVertex2d(x,y);
    glTexCoord2d(1,0);  glVertex2d(x+LARGEUR_BLOC * NB_COL,y);
    glTexCoord2d(1,1);  glVertex2d(x+LARGEUR_BLOC * NB_COL,y+HAUTEUR_BLOC * NB_LIGNES);
    glEnd();*/

    glBegin(GL_LINE_LOOP);
    glColor3ub(255,5,5);
    glVertex2d(x,y);
    glVertex2d(x,y+HAUTEUR_BLOC * NB_LIGNES);
    glVertex2d(x+LARGEUR_BLOC * NB_COL,y+HAUTEUR_BLOC * NB_LIGNES);
    glVertex2d(x+LARGEUR_BLOC * NB_COL,y);
    glEnd();

}

void Workspace::afficher_tableau()
{
    for(int i=0; i<nb_lignes()-3; i++)
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
    Piece piece_sim(courante->id_piece(),courante->id_rot(),courante->x(),courante->y());
    piece_sim.tourner();
    std::cerr<<" xws piece sim = "<<piece_sim.rightest().xws()<<std::endl;
    if(piece_sim.leftest().xws() <0 || piece_sim.rightest().xws()>10)
        move = false;
    std::cerr<<move<<std::endl;
    if(move)
        courante->tourner();

    for(int i=0; i<4; i++)
    {
        std::cerr<<" xws = "<< courante->blocs()[i].xws()<<std::endl;
        if(!  _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()].vide() ||
            ! _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()].vide() ||
             courante->blocs()[i].yws()== nb_lignes()-1)
            courante->detourner();
            //move = false;
    }
    std::cerr<<".....................\n"<<std::endl;
    //if(move)
        //courante->tourner();
        //if(_tableau[courante->leftest().yws()][courante->leftest().xws()-1].)

}

void Workspace::descendre(Piece *courante)
{
    //if(courante->y()> 40)
    courante->descendre();
}

void Workspace::moveG(Piece *courante)
{
    bool move = true;
    for(int i=0; i<4; i++)
    {
        if( ! _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()-1].vide())
            move = false;
    }
    if(move)
        courante->moveG();

}

void Workspace::moveD(Piece *courante)
{
    bool move = true;
    for(int i=0; i<4; i++)
    {
        if(! _tableau[courante->blocs()[i].yws()][courante->blocs()[i].xws()+1].vide())
            move = false;
    }
    if(move)
        courante->moveD();

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
void Workspace::ajouterHandicap(int id,int nbHandi)
{

    for(int i=_nb_lignes; i> 0; i--)
    {
        for(int j=0; j<nb_col(); j++)
        {
            _tableau[i-1][j].setY(_tableau[i-1][j].y() + 20);
            _tableau[i][j] = _tableau[i-1][j];
        }
    }

    for(int i=0; i<(nb_col()-1)/2; i++)
    {
        int a=nbHandi%2;
        if(a==0){
        int p =i*2;
        int imp =i*2+1;
        _tableau[0][p] = Bloc(30+(100+LARGEUR_BLOC * NB_COL)*id+(p*LARGEUR_BLOC),30,150,150,150);
        _tableau[0][imp] = Bloc(30+(100+LARGEUR_BLOC * NB_COL)*id+(imp*LARGEUR_BLOC),30,false);}
        else{
        int p =i*2;
        int imp =i*2+1;
        _tableau[0][imp] = Bloc(30+(100+LARGEUR_BLOC * NB_COL)*id+(imp*LARGEUR_BLOC),30,150,150,150);
        _tableau[0][p] = Bloc(30+(100+LARGEUR_BLOC * NB_COL)*id+(p*LARGEUR_BLOC),30,false);
        }
    }
}

void Workspace::retirerHandicap()
{
    detruire_ligne(0);
}
