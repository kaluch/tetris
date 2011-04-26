#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/Jeu.h"
#include "../include/Piece.h"
#include "../globale.h"
#include "../include/workspace.h"
using namespace std;



int main(int argc, char *argv[]) {

	std::cerr<< "creation Jeu"<<std::endl;
	Jeu jeu(2);
	std::cerr<<"\n\n............AU REVOIR............."<<std::endl;
	return 0;
}

