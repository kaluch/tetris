#ifndef PIECE_H
#define PIECE_H

#include "Liste_piece.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../globale.h"
#include "Bloc.h"
#include "stdio.h"
#include "Piece.h"
#include <vector>

#define LARGEUR 10
#define HAUTEUR 10

class Piece
{
public:

    Piece(int id,int rot,int x,int y)
    {
        _id_piece = id;
        _id_rot = rot;
        _rColor = 155;
        _gColor = 155;
        _bColor = 155;
        _x = x;
        _y = y;
        int k=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(LISTE_PIECES[id][1][i][j] == 1)
                {
                    int x = (i-2)*LARGEUR_BLOC + _x;
                    int y = (j-2)*HAUTEUR_BLOC + _y;

                    _blocs.push_back(Bloc(x,y,rColor(),gColor(),bColor()));
                    k++;
                }
            }
        }
    }
    Piece()
    {
        _x = 30+LARGEUR_BLOC * NB_COL/2;
        _y = 70+HAUTEUR_BLOC * NB_LIGNES;
        _rColor=0;
        _gColor=0;
        _bColor=0;

        int alea = (rand()%7);
        colorBlocs(alea);

        int k=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(LISTE_PIECES[alea][1][i][j] == 1)
                {
                    int x = (i-2)*LARGEUR_BLOC + _x;
                    int y = (j-2)*HAUTEUR_BLOC + _y;
                    _blocs.push_back(Bloc(x,y,rColor(),gColor(),bColor()));
                    k++;

                }
            }
        }
        _id_piece = alea;
        _id_rot = 1;
    }
    ~Piece() {}

    void afficher();
    void tourner();
    void detourner();
    void charger_blocs(int id_piece,int id_rot);
    void changerPiece(int id_piece,int id_rot,int r, int g, int b);
    void translateX(int val);
    void translateY(int val);
    Bloc downest();
    Bloc leftest();
    Bloc rightest();
    void colorBlocs(int alea);
    void descendre();
    void moveG();
    void moveD();


    /*-------ACCESSEURS----------*/
    int id_piece()
    {
        return _id_piece;
    }
    void setId(int idpiece){
        _id_piece=idpiece;}
    int id_rot()
    {
        return _id_rot;
    }
    int x()
    {
        return _x;
    }
    void setX(int val)
    {
        for(unsigned int i=0;i<blocs().size();i++){
            _blocs[i].setX(val+_blocs[i].x()-x());
	    }
        _x=val;
    }
    int y()
    {
        return _y;
    }
    void setY(int val)
    {
        for(unsigned int i=0;i<blocs().size();i++){
            _blocs[i].setY(val+_blocs[i].y()-y());
	    }
        _y = val;
    }
    int rColor()
    {
        return _rColor;
    }
    int gColor()
    {
        return _gColor;
    }
    int bColor()
    {
        return _bColor;
    }
    std::vector<Bloc> blocs()
    {
        return _blocs;
    }

    /*--------------------------*/
protected:
    int _id_piece;
    int _id_rot;
    int _x;
    int _y;
    int _rColor;
    int _gColor;
    int _bColor;
    std::vector<Bloc> _blocs;
};

#endif // PIECE_H
