/*
 * Bloc.h
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */

#ifndef BLOC_H_
#define BLOC_H_

#include <iostream>
#include "stdio.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "../globale.h"

class Bloc {
public:
    //Bloc(){}
	Bloc(int x,int y,int r,int g,int b){
	    std::cerr<<"constr bloc "<<x<<" "<<y<<" "<<r<<" "<<g<<" "<<b;
        _x = x;
        _y = y;
        _rColor = r;
        _gColor = g;
        _bColor = b;
        _vide = false;
        std::cerr<<"....OK"<<std::endl;
	}
	Bloc(int& x,int& y,bool boolean){
        _x=x;
        _y=y;
        _rColor = 0;
        _gColor = 0;
        _bColor = 0;
        _vide = true;
	}
	//~Bloc();

	void afficher();
    int x() const {return _x;}
	void setX(int val){_x=val;}
	int y() const {return _y;}
	void setY(int val){_y = val;}
	int rColor() {return _rColor;}
	int gColor() {return _gColor;}
	int bColor() {return _bColor;}
	void setBloc(const int& x,const int& y,const int& r,const int& g,const int& b){
	    _x = x;
        _y = y;
        _rColor = r;
        _gColor = g;
        _bColor = b;
	}
	bool vide()const{return _vide;}
protected:
	int _x;
	int _y;
	int _rColor;
	int _gColor;
	int _bColor;
	bool _vide;
};
#endif /* BLOC_H_ */
