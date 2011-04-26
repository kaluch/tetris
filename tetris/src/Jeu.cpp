/*
 * Jeu.cpp
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */

#include "../include/Jeu.h"


void Jeu::init_SDL(SDL_Surface *screen)
{
    std::cerr << "init SDL";
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL );
    SDL_WM_SetCaption("TETRIS SOUCHET DIGNOIRE 2011", NULL);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0,LARGEUR_ECRAN,0,HAUTEUR_ECRAN);
    std::cerr << ".................OK"<<std::endl;
}

void Jeu::afficher()
{
    for (unsigned int i = 0; i < _joueurs.size(); i++)
        _joueurs[i].afficher();
}

void Jeu::lancer_jeu()
{
    std::cerr<<"\n\n.........................Debut de la partie.........................\n\n"<<std::endl;
    std::cerr<<"....Nbre de joueurs = "<<_joueurs.size()<<std::endl;

    //SDL_Event event;
    bool continuer = true;

    while(continuer)
    {
        /*SDL_WaitEvent(&event);
        	switch (event.type) {
        	case SDL_QUIT:
        		continuer = false;
        	}*/
        tester_fin();
        gestion_event(_event,&continuer);

        glClear(GL_COLOR_BUFFER_BIT);
        for(unsigned int i = 0; i< _joueurs.size(); i++)
        {
            if(_joueurs[i].play())
            {
                _joueurs[i].gestion_piece_courante();
                _joueurs[i].traitement_workspace();

                if(_joueurs[i].cmp()>_joueurs[i].speed())
                {
                    _joueurs[i].move();
                    _joueurs[i].setCmp(0);
                }
                _joueurs[i].setCmp(_joueurs[i].cmp()+1);
            }
        }
        afficher();
        glFlush();
        SDL_GL_SwapBuffers();
    }
    for(unsigned int i = 0; i< _joueurs.size(); i++)
        {
            std::cerr<<"....... SCORE.......\n joueur "<< _joueurs[i].id_joueur()<<" score: "<< _joueurs[i].score()<<std::endl;
        }
    SDL_Quit();
}

void Jeu::tester_fin()
{
    for(unsigned int i = 0; i< _joueurs.size(); i++)
    {
        if( ! _joueurs[i].workspace().tableau()[NBLIGNE-4][NBCOL/2].vide() ||
                ! _joueurs[i].workspace().tableau()[NBLIGNE-4][NBCOL/2 -1].vide() ||
                ! _joueurs[i].workspace().tableau()[NBLIGNE-4][NBCOL/2 +1].vide())
        {
            _joueurs[i].setPlay(false);
            //std::cerr<<" tester fin......... play = "<<_joueurs[i].play()<<std::endl;
        }
    }
}

void Jeu::gestion_event(SDL_Event event,bool *continuer)
{
    //  SDL_EnableKeyRepeat(300,50);
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        *continuer = false;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            // JOUEUR 1
        case SDLK_UP:
            std::cerr<<"Tourner"<<std::endl;
            _joueurs[1].workspace().tourner(_joueurs[1].piece_courante());
            break;
        case SDLK_DOWN:
            std::cerr<<"Descendre"<<std::endl;
            _joueurs[1].workspace().descendre(_joueurs[1].piece_courante());
            break;
        case SDLK_LEFT:
            std::cerr<<"Left"<<std::endl;
            _joueurs[1].workspace().moveG(_joueurs[1].piece_courante());
            break;
        case SDLK_RIGHT:
            std::cerr<<"Right"<<std::endl;
            _joueurs[1].workspace().moveD(_joueurs[1].piece_courante());
            break;
        case SDLK_ESCAPE:
            std::cerr<<"Escape"<<std::endl;
            *continuer = false;
            break;
        default:
            break;

            // JOUEUR 0
        case SDLK_w:
            std::cerr<<"Tourner"<<std::endl;
            _joueurs[0].workspace().tourner(_joueurs[0].piece_courante());
            break;
        case SDLK_s:
            std::cerr<<"Descendre"<<std::endl;
            _joueurs[0].workspace().descendre(_joueurs[0].piece_courante());
            break;
        case SDLK_a:
            std::cerr<<"Left"<<std::endl;
            _joueurs[0].workspace().moveG(_joueurs[0].piece_courante());
            break;
        case SDLK_d:
            std::cerr<<"Right"<<std::endl;
            _joueurs[0].workspace().moveD(_joueurs[0].piece_courante());
            break;

        }
    default:
        break;
    }
}
