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
    screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL);
    srand(time(NULL));
    SDL_WM_SetCaption("TETRIS SOUCHET DIGNOIRE 2011", NULL);
    SDL_EnableKeyRepeat(300,50);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0,LARGEUR_ECRAN,0,HAUTEUR_ECRAN);
    if(screen == NULL)
        	std::cerr<<" ERREUR SCREEN SDL "<<SDL_GetError()<<std::endl;
    else
    	std::cerr << ".................OK"<<std::endl;
}

void Jeu::afficher()
{
    for (unsigned int i = 0; i < _humains.size(); i++)
        _humains[i].afficher();
    for( unsigned int i = 0; i < _computers.size(); i++)
        _computers[i].afficher();
}

void Jeu::lancer_jeu()
{
    std::cerr<<"\n\n.........................Debut de la partie.........................\n\n"<<std::endl;
    std::cerr<<"....Nbre de joueurs = "<<_humains.size()<<std::endl;

    bool continuer = true;

    while(continuer)
    {
        tester_fin();
        gestion_event(_event,&continuer);
        glClear(GL_COLOR_BUFFER_BIT);
        for(unsigned int i = 0; i< _humains.size(); i++)
        {
            if(_humains[i].play())
            {
                _humains[i].gestion_piece_courante();
                _humains[i].traitement_workspace();

                if(_humains[i].cmp()>_humains[i].speed())
                {
                    _humains[i].move();
                    _humains[i].setCmp(0);
                }
                _humains[i].setCmp(_humains[i].cmp()+1);
            }
        }
        for(unsigned int i = 0; i< _computers.size(); i++){
            if(_computers[i].play())
            {
            	_computers[i].gestion_piece_courante();
            	_computers[i].traitement_workspace();

                            if(_computers[i].cmp()>_computers[i].speed())
                            {
                            	_computers[i].move();
                            	_computers[i].setCmp(0);
                            }
                            _computers[i].setCmp(_computers[i].cmp()+1);
            }
        }
        afficher();
        glFlush();
        SDL_GL_SwapBuffers();
    }
    for(unsigned int i = 0; i< _humains.size(); i++)
        {
            std::cerr<<"....... SCORE.......\n joueur "<< _humains[i].id_joueur()<<" score: "<< _humains[i].score()<<std::endl;
        }
    SDL_Quit();
}

void Jeu::tester_fin()
{
    for(unsigned int i = 0; i< _humains.size(); i++)
    {
        if( ! _humains[i].workspace().tableau()[NB_LIGNES-4][NB_COL/2].vide() ||
                ! _humains[i].workspace().tableau()[NB_LIGNES-4][NB_COL/2 -1].vide() ||
                ! _humains[i].workspace().tableau()[NB_LIGNES-4][NB_COL/2 +1].vide())
        {
            _humains[i].setPlay(false);
            //std::cerr<<" tester fin......... play = "<<_humains[i].play()<<std::endl;
        }
    }
    for(unsigned int i = 0; i< _computers.size(); i++)
    {
        if( ! _computers[i].workspace().tableau()[NB_LIGNES-4][NB_COL/2].vide() ||
                ! _computers[i].workspace().tableau()[NB_LIGNES-4][NB_COL/2 -1].vide() ||
                ! _computers[i].workspace().tableau()[NB_LIGNES-4][NB_COL/2 +1].vide())
        {
            _computers[i].setPlay(false);
            //std::cerr<<" tester fin......... play = "<<_humains[i].play()<<std::endl;
        }
    }
}

void Jeu::gestion_event(SDL_Event event,bool *continuer)
{
     SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        *continuer = false;
        break;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
          case SDLK_ESCAPE:
            std::cerr<<"Escape"<<std::endl;
            *continuer = false;
            break;
        default:
            break;
      }

    default:
        break;
    }
    Uint8 *touches = SDL_GetKeyState(NULL);
    std::cerr<<touches[humains()[0].toucheLeft()]<<" "<<SDLK_LEFT<<std::endl;
    for(int i=0;i<humains().size();i++)
    {
        if(touches[humains()[i].toucheLeft()/*SDLK_LEFT*/]){
            if(humains()[i].lastLeft() == 0)
            {
                _humains[i].workspace().moveG(humains()[i].piece_courante());
                _humains[i].setLastLeft(TEMPO);
                //std::cerr<<"Tourner "<<humains()[i].lastLeft()<<std::endl;
            }
            else{
            _humains[i].setLastLeft(_humains[i].lastLeft() - 1);
            //std::cerr<<"pas tourner "<<humains()[i].lastLeft()<<std::endl;
            }
        }
        if(touches[humains()[i].toucheRight()/*SDLK_LEFT*/]){
            if(humains()[i].lastRight() == 0)
            {
                _humains[i].workspace().moveD(humains()[i].piece_courante());
                _humains[i].setLastRight(TEMPO);
                //std::cerr<<"Tourner "<<humains()[i].lastLeft()<<std::endl;
            }
            else{
            _humains[i].setLastRight(_humains[i].lastRight() - 1);
            //std::cerr<<"pas tourner "<<humains()[i].lastLeft()<<std::endl;
            }
        }
        if(touches[humains()[i].toucheDown()/*SDLK_LEFT*/]){
            if(humains()[i].lastDown() == 0)
            {
                _humains[i].workspace().descendre(humains()[i].piece_courante());
                _humains[i].setLastDown(TEMPO_BAS);
                //std::cerr<<"Tourner "<<humains()[i].lastLeft()<<std::endl;
            }
            else{
            _humains[i].setLastDown(_humains[i].lastDown() - 1);
            //std::cerr<<"pas tourner "<<humains()[i].lastLeft()<<std::endl;
            }
        }
        if(touches[humains()[i].toucheUp()/*SDLK_LEFT*/]){
            if(humains()[i].lastUp())
            {
                _humains[i].workspace().tourner(humains()[i].piece_courante());
                _humains[i].setLastUp(false);
                //std::cerr<<"Tourner "<<humains()[i].lastLeft()<<std::endl;
            }

        }
         else
        {
            _humains[i].setLastUp(true);
            //std::cerr<<"pas tourner "<<humains()[i].lastLeft()<<std::endl;
        }
    }


//    for(int i=0;i<humains().size();i++)
//    {
//        if(touches[humains()[i].toucheUp()])
//        {
//            if(humains()[i].lastUp())
//            {
//                _humains[i].workspace().tourner(humains()[i].piece_courante());
//                _humains[i].setLastUp(false);
//            }
//            else
//                _humains[i].setLastUp(true);
//        }
//
//
//        if(touches[humains()[i].toucheDown()])
//        {
//            if(humains()[i].lastDown() ==0)
//            {
//                _humains[i].workspace().descendre(humains()[i].piece_courante());
//                _humains[i].setLastDown(TEMPO);
//            }
//            else
//                _humains[i].setLastDown(_humains[i].lastDown() - 1);
//        }
//
//        if(touches[humains()[i].toucheLeft()])
//        {
//            if(humains()[i].lastLeft()>=0)
//            {
//                _humains[i].workspace().moveG(humains()[i].piece_courante());
//                _humains[i].setLastLeft(TEMPO);
//            }
//            else
//                _humains[i].setLastLeft(_humains[i].lastLeft() - 1);
//        }
//
//        if(touches[humains()[i].toucheRight()])
//        {
//            if(humains()[i].lastRight()>=0)
//            {
//                _humains[i].workspace().moveD(humains()[i].piece_courante());
//                _humains[i].setLastRight(TEMPO);
//            }
//            else
//                _humains[i].setLastRight(_humains[i].lastRight() - 1);
//        }

 //   }
////        else
////            humains()[i].workspace().tourner(humains()[i].piece_courante());
////        else if(touches[humains()[i].toucheLeft()])
////            humains()[i].workspace().moveG(humains()[i].piece_courante());
////        else if(touches[humains()[i].toucheRight()])
////            humains()[i].workspace().moveD(humains()[i].piece_courante());
////        else if(touches[humains()[i].toucheDown()])
////            humains()[i].workspace().descendre(humains()[i].piece_courante());
//    //  SDL_EnableKeyRepeat(300,50);s

//
//    SDL_PollEvent(&event);
//    switch (event.type)
//    {
//    case SDL_QUIT:
//        *continuer = false;
//        break;
//    case SDL_KEYDOWN:
//        switch(event.key.keysym.sym)
//        {
//            // JOUEUR 1
//        case SDLK_UP:
//            std::cerr<<"Tourner"<<std::endl;
//            _humains[1].workspace().tourner(_humains[1].piece_courante());
//            break;
//        case SDLK_DOWN:
//            std::cerr<<"Descendre"<<std::endl;
//            _humains[1].workspace().descendre(_humains[1].piece_courante());
//            break;
//        case SDLK_LEFT:
//            std::cerr<<"Left"<<std::endl;
//            _humains[1].workspace().moveG(_humains[1].piece_courante());
//            break;
//        case SDLK_RIGHT:
//            std::cerr<<"Right"<<std::endl;
//            _humains[1].workspace().moveD(_humains[1].piece_courante());
//            break;
//        case SDLK_ESCAPE:
//            std::cerr<<"Escape"<<std::endl;
//            *continuer = false;
//            break;
//        default:
//            break;
//
//            // JOUEUR 0
//        case SDLK_w:
//            std::cerr<<"Tourner"<<std::endl;
//            _humains[0].workspace().tourner(_humains[0].piece_courante());
//            break;
//        case SDLK_s:
//            std::cerr<<"Descendre"<<std::endl;
//            _humains[0].workspace().descendre(_humains[0].piece_courante());
//            break;
//        case SDLK_a:
//            std::cerr<<"Left"<<std::endl;
//            _humains[0].workspace().moveG(_humains[0].piece_courante());
//            break;
//        case SDLK_d:
//            std::cerr<<"Right"<<std::endl;
//            _humains[0].workspace().moveD(_humains[0].piece_courante());

//            break;
//
//        }
//    default:
//        break;
//    }
}
