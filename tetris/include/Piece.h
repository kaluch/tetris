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

#define LARGEUR 10
#define HAUTEUR 10

class Piece {
public:

	Piece(const int& val, const int& r, const int& g, const int& b) {
		_id_piece = val;
		_id_rot = 1;
		_rColor = r;
		_gColor=g;
		_bColor=b;
		_x = 100;
		_y = 100;
	}

	Piece() {
		srand(time(NULL));
		int alea = (int) round((rand() * 6) + 1);
		_id_piece = alea;
		_id_rot = 1;
		_x = 0;
		_y = 0;
	}

	void tourner() {
		_id_rot++;
		if (_id_rot > NB_ROT)
			_id_rot = 1;
	}

	void afficher();
	void afficherBlocs();
	/*-------GETTERS-----------*/
	int id_piece() {
		return _id_piece;
	}
	int id_rot() {
		return _id_rot;
	}
	int x() {
		return _x;
	}
	int y() {
		return _y;
	}
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
};

#endif // PIECE_H
