#include "../include/Piece.h"

using namespace std;

void Piece::afficher()
{
    for(int i=0; i<4; i++)
    {
        blocs()[i].afficher();
    }
}


Bloc Piece::downest()
{
    Bloc mind=blocs()[0];
    for(int i=1; i<4; i++)
    {
        if(blocs()[i].y()<mind.y())
            mind = blocs()[i];
    }
    return mind;
}

Bloc Piece::leftest()
{
    Bloc minl=blocs()[0];
    for(int i=1; i<4; i++)
    {
        if(blocs()[i].x()<minl.x())
            minl = blocs()[i];
    }
    return minl;
}

Bloc Piece::rightest()
{
    Bloc max=blocs()[0];
    for(int i=1; i<4; i++)
    {
        if(blocs()[i].x()>max.x())
            max = blocs()[i];
    }
    return max;
}
void Piece::descendre()
    {
        if(downest().yws()>0){
            translateY(-20);
        }

    }
    void Piece::moveG()
    {
        if(leftest().xws()>0){
            translateX(-20);
        }
    }
    void Piece::moveD()
    {
        if(rightest().xws()<9){
        translateX(20);
        }
    }
void Piece::translateX(int val)
{
    setX(x()+val);
}
void Piece::translateY(int val)
{
    setY(y()+val);
}

void Piece::tourner()
{
    if(downest().yws()>0)
    {
        _id_rot++;
        if (_id_rot >= NB_ROT)
            _id_rot = 0;
        charger_blocs(id_piece(),id_rot());
    }
}
void Piece::detourner()
{
        _id_rot--;
        if (_id_rot < 1)
            _id_rot = NB_ROT-1;
        charger_blocs(id_piece(),id_rot());
}

void Piece::charger_blocs(int id_piece, int id_rot)
{
    changerPiece(id_piece,id_rot,rColor(),gColor(),bColor());
}

void Piece::changerPiece(int id_piece,int id_rot,int r, int g, int b)
    {
        _blocs.clear();
        _id_piece = id_piece;
        _id_rot = id_rot;
        _rColor = r;
        _gColor = g;
        _bColor = b;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(LISTE_PIECES[id_piece][id_rot][i][j] == 1)
                {
                    int x = (i-2)*LARGEUR_BLOC + _x;
                    int y = (j-2)*HAUTEUR_BLOC + _y;
                    _blocs.push_back(Bloc(x,y,rColor(),gColor(),bColor()));
                }
            }
        }
    }

void Piece::colorBlocs(int alea)
{
    switch(alea)
    {
    case 0:
        _rColor=255;
        _gColor=0;
        _bColor=0;
        break;
    case 1:
        _rColor=0;
        _gColor=255;
        _bColor=0;
        break;
    case 2:
        _rColor=0;
        _gColor=0;
        _bColor=255;
        break;
    case 3:
        _rColor=255;
        _gColor=255;
        _bColor=0;
        break;
    case 4:
        _rColor=0;
        _gColor=255;
        _bColor=255;
        break;
    case 5:
        _rColor=255;
        _gColor=0;
        _bColor=255;
        break;
    case 6:
        _rColor=255;
        _gColor=255;
        _bColor=255;
        break;
    default:
        break;

    }
}
