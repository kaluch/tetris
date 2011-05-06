/*
 * Jeu.cpp
 *
 *  Created on: 8 avr. 2011
 *      Author: souchet
 */

#include "../include/Jeu.h"
GLuint fondWs;
GLuint fondScore;
GLuint zero;
GLuint un;
GLuint deux;
GLuint trois;
GLuint quatre;
GLuint cinq;
GLuint six;
GLuint sept;
GLuint huit;
GLuint neuf;
GLuint fond1;
void Jeu::init_SDL(SDL_Surface *screen)
{
    std::cerr << "init SDL";
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL);
    srand(time(NULL));
    SDL_WM_SetCaption("TETRIS SOUCHET DIGNOIRE 2011", NULL);
    SDL_EnableKeyRepeat(300,50);

    fondWs = loadTexture("fondWs.png");
    std::cerr<< "fond  ws = "<<fondWs<<std::endl;

    zero = loadTexture("zero.png");
    un = loadTexture("un.png");
    deux = loadTexture("deux.png");
    trois = loadTexture("trois.png");
    quatre = loadTexture("quatre.png");
    cinq = loadTexture("cinq.png");
    six = loadTexture("six.png");
    sept = loadTexture("sept.png");
    huit = loadTexture("huit.png");
    neuf = loadTexture("neuf.png");

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0,LARGEUR_ECRAN,0,HAUTEUR_ECRAN);
    glEnd();

    if(screen == NULL)
        std::cerr<<" ERREUR SCREEN SDL "<<SDL_GetError()<<std::endl;
    else
        std::cerr << ".................OK"<<std::endl;
}

void Jeu::afficher()
{
    for (unsigned int i = 0; i < _humains.size(); i++)
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        afficherScore(_humains[i].id_joueur(),_humains[i].score());
        afficherFond(19+_humains[i].id_joueur()*(100+LARGEUR_BLOC * NB_COL),20);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        _humains[i].afficher();
    }
    for (unsigned int i = 0; i < _computers.size(); i++)
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        afficherScore(_computers[i].id_joueur(),_computers[i].score());
        afficherFond(19+_computers[i].id_joueur()*(100+LARGEUR_BLOC * NB_COL),20);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        _computers[i].afficher();
    }


}

void Jeu::afficherFond(int x,int y)
{
    glBindTexture(GL_TEXTURE_2D, fondWs);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,1);  glVertex2d(x,y+HAUTEUR_BLOC * NB_LIGNES);
    glTexCoord2d(0,0);  glVertex2d(x,y);
    glTexCoord2d(1,0);  glVertex2d(x+LARGEUR_BLOC * NB_COL,y);
    glTexCoord2d(1,1);  glVertex2d(x+LARGEUR_BLOC * NB_COL,y+HAUTEUR_BLOC * NB_LIGNES);
    glEnd();
}

void Jeu::afficherScore(int id,int score)
{
    int xu = 80+LARGEUR_BLOC * NB_COL+id*(100+LARGEUR_BLOC * NB_COL);
    int yu = HAUTEUR_BLOC * NB_LIGNES/4;
    afficherChiffre(xu,yu,score%10);
    int xd = 40+LARGEUR_BLOC * NB_COL+id*(100+LARGEUR_BLOC * NB_COL);
    int yd = HAUTEUR_BLOC * NB_LIGNES/4;
    afficherChiffre(xd,yd,(score-(score%10))/10);
}
void Jeu::afficherChiffre(int x,int y,int chiffre){
    GLuint nb;
    switch(chiffre)
        {
        case 0:
            nb=zero;
            break;
        case 1:
            nb=un;
            break;
        case 2:
            nb=deux;
            break;
        case 3:
            nb=trois;
            break;
        case 4:
            nb=quatre;
            break;
        case 5:
            nb=cinq;
            break;
        case 6:
            nb=six;
            break;
        case 7:
            nb=sept;
            break;
        case 8:
            nb=huit;
            break;
        case 9:
            nb=neuf;
            break;
        }

    glBindTexture(GL_TEXTURE_2D, nb);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    //glColor3ub(0,0,0);
    glTexCoord2d(0,1);
    glVertex2d(x,y+32);
    glTexCoord2d(0,0);
    glVertex2d(x,y);
    glTexCoord2d(1,0);
    glVertex2d(x+32,y);
    glTexCoord2d(1,1);
    glVertex2d(x+32,y+32);
    glEnd();

}


void Jeu::lancer_jeu()
{
    std::cerr<<"\n\n.........................Debut de la partie.........................\n\n"<<std::endl;
    std::cerr<<"....Nbre de joueurs = "<<_humains.size()<<std::endl;

    bool continuer = true;

    while(continuer)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        tester_fin();
        gestion_event(_event,&continuer);

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
        for(unsigned int i = 0; i< _computers.size(); i++)
        {
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
        //glEnable(GL_DEPTH_TEST);
        //glEnable(GL_TEXTURE_2D);
        //afficherFond();
        //afficherScore(0);
        //glDisable(GL_TEXTURE_2D);
        //glDisable(GL_DEPTH_TEST);
        afficher();

        //interfaceX().afficherJeu();
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
    //std::cerr<<touches[humains()[0].toucheLeft()]<<" "<<SDLK_LEFT<<std::endl;
    for(unsigned int i=0; i<humains().size(); i++)
    {
        if(touches[humains()[i].toucheLeft()/*SDLK_LEFT*/])
        {
            if(humains()[i].lastLeft() == 0)
            {
                _humains[i].workspace().moveG(humains()[i].piece_courante());
                _humains[i].setLastLeft(TEMPO);
                //std::cerr<<"Tourner "<<humains()[i].lastLeft()<<std::endl;
            }
            else
            {
                _humains[i].setLastLeft(_humains[i].lastLeft() - 1);
                //std::cerr<<"pas tourner "<<humains()[i].lastLeft()<<std::endl;
            }
        }
        if(touches[humains()[i].toucheRight()/*SDLK_LEFT*/])
        {
            if(humains()[i].lastRight() == 0)
            {
                _humains[i].workspace().moveD(humains()[i].piece_courante());
                _humains[i].setLastRight(TEMPO);
                //std::cerr<<"Tourner "<<humains()[i].lastLeft()<<std::endl;
            }
            else
            {
                _humains[i].setLastRight(_humains[i].lastRight() - 1);
                //std::cerr<<"pas tourner "<<humains()[i].lastLeft()<<std::endl;
            }
        }
        if(touches[humains()[i].toucheDown()/*SDLK_LEFT*/])
        {
            if(humains()[i].lastDown() == 0)
            {
                _humains[i].workspace().descendre(humains()[i].piece_courante());
                _humains[i].setLastDown(TEMPO_BAS);
                //std::cerr<<"Tourner "<<humains()[i].lastLeft()<<std::endl;
            }
            else
            {
                _humains[i].setLastDown(_humains[i].lastDown() - 1);
                //std::cerr<<"pas tourner "<<humains()[i].lastLeft()<<std::endl;
            }
        }
        if(touches[humains()[i].toucheUp()/*SDLK_LEFT*/])
        {
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
}
