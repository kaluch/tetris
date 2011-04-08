/*
 * Bloc.h
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */

#ifndef BLOC_H_
#define BLOC_H_

class Bloc {
public:
	Bloc();
	virtual ~Bloc();
};
protected:
	int _x;
	int _y;
	int _r;
	int _g;
	int _b;

#endif /* BLOC_H_ */
