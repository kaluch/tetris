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
	Bloc(int x,int y,int r,int g,int b) : _x(x), _y(y), _yws((y-20)/20), _rColor(r), _gColor(g), _bColor(b){
	    //std::cerr<<"constr bloc "<<x<<" "<<y<<" "<<r<<" "<<g<<" "<<b;

        if( x<100+LARGEUR_BLOC * NB_COL){
            _xws=(x-20)/LARGEUR_BLOC;
            //std::cerr<<"setXws.........."<<_xws<<std::endl;
            }

        else if(120+LARGEUR_BLOC * NB_COL<_x && _x<(120+2*LARGEUR_BLOC * NB_COL))
            _xws=(x-20-(100+LARGEUR_BLOC * NB_COL))/20;
        else if(2*(100+LARGEUR_BLOC * NB_COL)<_x && _x<3*(100+LARGEUR_BLOC * NB_COL))
            _xws=(x-20-2*(100+LARGEUR_BLOC * NB_COL))/20;
        else if(3*(100+LARGEUR_BLOC * NB_COL)<_x && _x<4*(100+LARGEUR_BLOC * NB_COL))
            _xws=(x-20-3*(100+LARGEUR_BLOC * NB_COL))/20;
        else {
        _xws=0;}
	}
	Bloc(int x,int y,bool boolean) : _x(x), _y(y), _xws((x-20)/20), _yws((y-20)/20), _rColor(125), _gColor(0), _bColor(0), _vide(true){}
	~Bloc(){}

    int x(){return _x;}
    int xws(){return _xws;}

	void setX(int val){
	    _x=val;
	    //std::cerr<<"setX.........."<<_x<<std::endl;
        if( _x<100+LARGEUR_BLOC * NB_COL){
            _xws=(_x-20)/LARGEUR_BLOC;
            //std::cerr<<"setXws.........."<<_xws<<std::endl;
            }

        else if(120+LARGEUR_BLOC * NB_COL<_x && _x<(120+2*LARGEUR_BLOC * NB_COL))
            _xws=(_x-20-(100+LARGEUR_BLOC * NB_COL))/20;
        else if(2*(100+LARGEUR_BLOC * NB_COL)<_x && _x<3*(100+LARGEUR_BLOC * NB_COL))
            _xws=(_x-20-2*(100+LARGEUR_BLOC * NB_COL))/20;
        else if(3*(100+LARGEUR_BLOC * NB_COL)<_x && _x<4*(100+LARGEUR_BLOC * NB_COL))
            _xws=(_x-20-3*(100+LARGEUR_BLOC * NB_COL))/20;
        else {
        _xws=0;}
	}


	int y(){return _y;}
	int yws(){return _yws;}
	void setY(int val){_y=val;_yws=(_y-20)/HAUTEUR_BLOC;}
	int rColor() {return _rColor;}
	int gColor() {return _gColor;}
	int bColor() {return _bColor;}
	void setBloc(int x,int y,int r,int g,int b){
	    _x = x;
        _y = y;
        _rColor = r;
        _gColor = g;
        _bColor = b;
	}
	bool vide(){return _vide;}
	void afficher();
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
