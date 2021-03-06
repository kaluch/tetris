/*
 * Bloc.h
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */

#ifndef BLOC_H_
#define BLOC_H_

#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../globale.h"

class Bloc {
public:
    Bloc(){}
	Bloc(int x,int y,int r,int g,int b) : _x(x), _y(y), _yws((y-20)/20), _rColor(r), _gColor(g), _bColor(b), _vide(false){
        int id=(x-20)/(100+LARGEUR_BLOC*NB_COL);
	    if(x<=20 )
            _xws= -1;
        else if(x<20+LARGEUR_BLOC * NB_COL+id*(100+LARGEUR_BLOC * NB_COL))
            _xws=(x-20-id*(100+LARGEUR_BLOC * NB_COL))/LARGEUR_BLOC;
        else if(x<=20+(id+1)*(100+LARGEUR_BLOC * NB_COL))
            _xws= -1;
        else _xws=0;
	}

	Bloc(int x,int y,bool vide) : _x(x), _y(y), _xws((x-20)/20), _yws((y-20)/20), _rColor(125), _gColor(0), _bColor(0), _vide(vide){}
	~Bloc(){}

	void setBloc(int x,int y,int r,int g,int b){
	    _x = x;
        _y = y;
        _rColor = r;
        _gColor = g;
        _bColor = b;
	}

	void afficher();

	//ACCESSEURS
	int x(){return _x;}
    int xws(){return _xws;}

	void setX(int val){
	    _x=val;
	    int id=(_x-20)/(100+LARGEUR_BLOC*NB_COL);
	    if(_x<=20 )
            _xws= -1;
        else if(_x<20+LARGEUR_BLOC * NB_COL+id*(100+LARGEUR_BLOC * NB_COL))
            _xws=(_x-20-id*(100+LARGEUR_BLOC * NB_COL))/LARGEUR_BLOC;
        else if(_x<=20+(id+1)*(100+LARGEUR_BLOC * NB_COL))
            _xws= -1;
        else _xws=0;
	}

	int y(){return _y;}
	int yws(){return _yws;}
	void setY(int val){_y=val;_yws=(_y-20)/HAUTEUR_BLOC;}
	int rColor() {return _rColor;}
	int gColor() {return _gColor;}
	int bColor() {return _bColor;}
	bool vide(){return _vide;}
	void setVide(bool vide){
	    _vide=vide;
	}
protected:
	int _x;
	int _y;
    int _xws;
	int _yws;
	int _rColor;
	int _gColor;
	int _bColor;
	bool _vide;
};
#endif // BLOC_H_
