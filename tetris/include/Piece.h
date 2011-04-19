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

class Piece {
public:

	Piece(int val, int r, int g,int b){
	    std::vector<Bloc> _blocs;
		_id_piece = val;
		_id_rot = 1;
		_rColor = r;
		_gColor = g;
		_bColor = b;
		_x = NB_COL/2;
		_y = NB_LIGNES +3;
		int k=0;
		for(int i=0;i<4;i++){
		    for(int j=0;j<4;j++){
                if(LISTE_PIECES[val][1][i][j] == 1){

                int x = (i-2)*LARGEUR_BLOC + _x;
                int y = (j-2)*HAUTEUR_BLOC + _y;
                _blocs.push_back(Bloc(x,y,rColor(),gColor(),bColor()));
                k++;
                }
		    }
		}
	}

    void changerPiece(int id_piece,int id_rot,int r, int g, int b)
    {
		_blocs.clear();
		_id_piece = id_piece;
		_id_rot = id_rot;
		_rColor = r;
		_gColor = g;
		_bColor = b;
		int k=0;
		for(int i=0;i<4;i++){
		    for(int j=0;j<4;j++){
                if(LISTE_PIECES[id_piece][id_rot][i][j] == 1){

                    int x = (i-2);
                    int y = (j-2);
                    _blocs.push_back(Bloc(x,y,rColor(),gColor(),bColor()));
                    k++;
                }
		    }
		}
    }
	Piece() {
		std::cerr<<"constr piece()"<<std::endl;
		srand(time(NULL));
		_x = NB_COL/2;
		_y = NB_LIGNES+3;
		_rColor=0;
		_gColor=0;
		_bColor=0;
		int alea = (rand()%6) + 1;
		int k=0;
		for(int i=0;i<4;i++){
		    for(int j=0;j<4;j++){
                if(LISTE_PIECES[alea][1][i][j] == 1){

                int x = (i-2);
                int y = (j-2);
                _blocs.push_back(Bloc(x,y,rColor(),gColor(),bColor()));
                k++;
                }
		    }
		}
		_id_piece = alea;
		_id_rot = 1;
		std::cerr<<"PIECE("<<_x<<","<<_y<<","<<_id_piece<<") OK"<<std::endl;
	}
    ~Piece(){}
	void tourner();
	void descendre(){
		setY(y()-1);
	}
	void moveG(){
		setX(x()-1);
	}
	void moveD(){
		setX(x()+1);
	}

    Bloc downest();
	void afficher();
	void charger_blocs(int id_piece,int id_rot);
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
	std::vector<Bloc> blocs() {
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
