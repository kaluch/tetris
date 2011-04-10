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

#define LARGEUR 10
#define HAUTEUR 10

class Piece {
public:

	Piece(int val, int r, int g,int b){
	    _blocs = new Bloc[4];
		_id_piece = val;
		_id_rot = 1;
		_rColor = r;
		_gColor = g;
		_bColor = b;
		_x = 120;
		_y = 420;
		int k=0;
		for(int i=0;i<4;i++){
		    for(int j=0;j<4;j++){
                if(LISTE_PIECES[val][1][i][j] == 1){

                int x = (i-2)*LARGEUR_BLOC + _x;
                int y = (j-2)*HAUTEUR_BLOC + _y;
                _blocs[k].setBloc(x,y,rColor(),gColor(),bColor());
                k++;
                }
		    }
		}
	}

	Piece() {
		srand(time(NULL));
		_x = 120;
		_y = 420;
		int alea = (int) round((rand() * 6) + 1);
		int k=0;
		for(int i=0;i<4;i++){
		    for(int j=0;j<4;j++){
                if(LISTE_PIECES[alea][1][i][j] == 1){

                int x = (i-2)*LARGEUR_BLOC + _x;
                int y = (j-2)*HAUTEUR_BLOC + _y;
                _blocs[k].setBloc(x,y,rColor(),gColor(),bColor());
                k++;
                }
		    }
		}
		_id_piece = alea;
		_id_rot = 1;
	}
    ~Piece(){}
	void tourner() {
		_id_rot++;
		if (_id_rot > NB_ROT)
			_id_rot = 1;
	}
	void descendre(){
		setY(y()-1);
	}
	void moveG(){
		setX(x()-1);
	}
	void moveR(){
		setX(x()+1);
	}

	void afficher();
	/*-------GETTERS-----------*/
	int id_piece() {
		return _id_piece;
	}
	int id_rot() {
		return _id_rot;
	}
	int x() {return _x;}
	void setX(int val){_x=val;}
	int y() {return _y;}
	void setY(int val){_y = val;}
	int rColor() {
			return _rColor;
		}
	int gColor() {
			return _gColor;
		}
	int bColor() {
			return _bColor;
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
	Bloc* _blocs;
};

#endif // PIECE_H
