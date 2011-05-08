#include "../include/Menu.h"
GLuint jouer;
GLuint nbjoueur;
GLuint com;
GLuint flechegauche;
GLuint flechedroite;
GLuint zerom;
GLuint unm;
GLuint deuxm;
GLuint troism;
GLuint quatrem;
GLuint cinqm;
GLuint sixm;
GLuint septm;
GLuint huitm;
GLuint neufm;
GLuint logom;

void Menu::lancer_menu(){
    std::cerr<<"\n\n.........................Debut du menu.........................\n\n"<<std::endl;
    jouer = loadTexture("image/entree_2.png");
    nbjoueur = loadTexture("image/nb_humains2.png");
    com = loadTexture("image/nb_cpu2.png");
    flechegauche = loadTexture("image/moinsgauche.png");
    flechedroite = loadTexture("image/plusdroite.png");
    zerom = loadTexture("image/zero.png");
    unm = loadTexture("image/un.png");
    deuxm = loadTexture("image/deux.png");
    troism = loadTexture("image/trois.png");
    quatrem = loadTexture("image/quatre.png");
    cinqm = loadTexture("image/cinq.png");
    sixm = loadTexture("image/six.png");
    septm = loadTexture("image/sept.png");
    huitm = loadTexture("image/huit.png");
    neufm = loadTexture("image/neuf.png");
    logom = loadTexture("image/logo.png");
    bool continuer = true;
    while(continuer)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gestion_event(_event,&continuer);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        afficher();
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);

        glFlush();
        SDL_GL_SwapBuffers();

        //SDL_Quit();
    }
}
void Menu::gestion_event(SDL_Event event,bool *continuer){
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
        case SDLK_RETURN:
            std::cerr<<"Enter"<<std::endl;
            *continuer = false;
            break;
        case SDLK_RIGHT:
            std::cerr<<"Right"<<std::endl;
            if(!select()){
                if(_nb_joueur<9){
                    setNbJoueur(nb_joueur()+1);
                }
            }
            else
                if(_nb_cpu<9){
                    setNbCpu(nb_cpu()+1);
                }
            break;
        case SDLK_LEFT:
            std::cerr<<"Left"<<std::endl;
            if(!select()){
                if(_nb_joueur>0){
                    setNbJoueur(nb_joueur()-1);
                }
            }
            else
                if(_nb_cpu>0){
                    setNbCpu(nb_cpu()-1);
                }
            break;
        case SDLK_UP:
            std::cerr<<"Switch menu"<<std::endl;
            switch_menu();
        default:
            break;
        }
    }
}

void Menu::switch_menu(){
    if(select())
        setSelect(false);
    else
        setSelect(true);
}
void Menu::afficher(){
    afficherLogo();
    afficherEntree();
    afficherNbjoueur();
}
void Menu::afficherNbjoueur(){
    // nombre de joueur
    glBindTexture(GL_TEXTURE_2D, nbjoueur);
    glBegin(GL_QUADS);
    if(!select())
        glColor3ub(255,255,255);
    else
        glColor3ub(55,55,55);
    glTexCoord2d(0,1);  glVertex2d(50,240+128);
    glTexCoord2d(0,0);  glVertex2d(50,240);
    glTexCoord2d(1,0);  glVertex2d(50+256,240);
    glTexCoord2d(1,1);  glVertex2d(50+256,240+128);
    glEnd();
    // afficher le nombre
    afficherChiffre(_nb_joueur,180,205);
    // afficher les fleches
    glBindTexture(GL_TEXTURE_2D, flechegauche);
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glTexCoord2d(0,1);  glVertex2d(50,160+128);
    glTexCoord2d(0,0);  glVertex2d(50,160);
    glTexCoord2d(1,0);  glVertex2d(50+96,160);
    glTexCoord2d(1,1);  glVertex2d(50+96,160+128);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, flechedroite);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glTexCoord2d(0,1);  glVertex2d(325-89,170+100);
    glTexCoord2d(0,0);  glVertex2d(325-89,170);
    glTexCoord2d(1,0);  glVertex2d(325,170);
    glTexCoord2d(1,1);  glVertex2d(325,170+100);
    glEnd();
    // afficher le COM
    glBindTexture(GL_TEXTURE_2D, com);
    glBegin(GL_QUADS);
    if(select())
        glColor3ub(255,255,255);
    else
        glColor3ub(55,55,55);
    glTexCoord2d(0,1);  glVertex2d(LARGEUR_ECRAN-316,240+128);
    glTexCoord2d(0,0);  glVertex2d(LARGEUR_ECRAN-316,240);
    glTexCoord2d(1,0);  glVertex2d(LARGEUR_ECRAN-60,240);
    glTexCoord2d(1,1);  glVertex2d(LARGEUR_ECRAN-60,240+128);
    glEnd();
    // afficher le nombre de com
    afficherChiffre(nb_cpu(),LARGEUR_ECRAN-200,205);
     // afficher les fleches
    glBindTexture(GL_TEXTURE_2D, flechegauche);
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glTexCoord2d(0,1);  glVertex2d(LARGEUR_ECRAN-316,160+128);
    glTexCoord2d(0,0);  glVertex2d(LARGEUR_ECRAN-316,160);
    glTexCoord2d(1,0);  glVertex2d(LARGEUR_ECRAN-316+96,160);
    glTexCoord2d(1,1);  glVertex2d(LARGEUR_ECRAN-316+96,160+128);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, flechedroite);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glTexCoord2d(0,1);  glVertex2d(LARGEUR_ECRAN-160,170+100);
    glTexCoord2d(0,0);  glVertex2d(LARGEUR_ECRAN-160,170);
    glTexCoord2d(1,0);  glVertex2d(LARGEUR_ECRAN-160+96,170);
    glTexCoord2d(1,1);  glVertex2d(LARGEUR_ECRAN-160+96,170+100);
    glEnd();
}
void Menu::afficherChiffre(int image,int x,int y){
    GLuint nb;
    switch(image)
        {
        case 0:
            nb=zerom;
            break;
        case 1:
            nb=unm;
            break;
        case 2:
            nb=deuxm;
            break;
        case 3:
            nb=troism;
            break;
        case 4:
            nb=quatrem;
            break;
        case 5:
            nb=cinqm;
            break;
        case 6:
            nb=sixm;
            break;
        case 7:
            nb=septm;
            break;
        case 8:
            nb=huitm;
            break;
        case 9:
            nb=neufm;
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
void Menu::afficherEntree(){
    glBindTexture(GL_TEXTURE_2D, jouer);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,1);  glVertex2d(LARGEUR_ECRAN/2-132,50+180);
    glTexCoord2d(0,0);  glVertex2d(LARGEUR_ECRAN/2-132,50);
    glTexCoord2d(1,0);  glVertex2d(LARGEUR_ECRAN/2-132+264,50);
    glTexCoord2d(1,1);  glVertex2d(LARGEUR_ECRAN/2-132+264,50+180);
    glEnd();
}

void Menu::afficherLogo()
{
    glBindTexture(GL_TEXTURE_2D, logom);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,1);  glVertex2d(LARGEUR_ECRAN/2-132,HAUTEUR_ECRAN-20);
    glTexCoord2d(0,0);  glVertex2d(LARGEUR_ECRAN/2-132,HAUTEUR_ECRAN-190);
    glTexCoord2d(1,0);  glVertex2d(LARGEUR_ECRAN/2+132,HAUTEUR_ECRAN-190);
    glTexCoord2d(1,1);  glVertex2d(LARGEUR_ECRAN/2+132,HAUTEUR_ECRAN-20);
    glEnd();
}

