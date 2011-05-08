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
GLuint fondm;

void Menu::lancer_menu(){
    std::cerr<<"\n\n.........................Debut du menu.........................\n\n"<<std::endl;
    jouer = loadTexture("image/ENTREE.png");
    nbjoueur = loadTexture("image/nb_humains.png");
    com = loadTexture("image/nb_cpu.png");
    flechegauche = loadTexture("image/flechegauche.png");
    flechedroite = loadTexture("image/flechedroite.png");
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
    fondm = loadTexture("image/fond2.png");
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
            if(_nb_joueur<9)
            _nb_joueur=_nb_joueur+1;
            break;
        case SDLK_LEFT:
            std::cerr<<"Left"<<std::endl;
            if(_nb_joueur>0)
            _nb_joueur=_nb_joueur-1;
            break;
        default:
            break;
        }
    }
}
void Menu::afficher(){
    //afficherFond(0,0);
    afficherEntree();
    afficherNbjoueur();
}
void Menu::afficherNbjoueur(){
    // nombre de joueur
    glBindTexture(GL_TEXTURE_2D, nbjoueur);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,1);  glVertex2d(200,300+128);
    glTexCoord2d(0,0);  glVertex2d(200,300);
    glTexCoord2d(1,0);  glVertex2d(200+256,300);
    glTexCoord2d(1,1);  glVertex2d(200+256,300+128);
    glEnd();
    // afficher le nombre
    afficherChiffre(_nb_joueur,310,250);
    // afficher les fleches
    glBindTexture(GL_TEXTURE_2D, flechegauche);
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glTexCoord2d(0,1);  glVertex2d(165,240+64);
    glTexCoord2d(0,0);  glVertex2d(165,240);
    glTexCoord2d(1,0);  glVertex2d(165+128,240);
    glTexCoord2d(1,1);  glVertex2d(165+128,240+64);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, flechedroite);
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glTexCoord2d(0,1);  glVertex2d(365,235+64);
    glTexCoord2d(0,0);  glVertex2d(365,235);
    glTexCoord2d(1,0);  glVertex2d(365+128,235);
    glTexCoord2d(1,1);  glVertex2d(365+128,235+64);
    glEnd();
    // afficher le COM
    glBindTexture(GL_TEXTURE_2D, com);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,1);  glVertex2d(600,300+128);
    glTexCoord2d(0,0);  glVertex2d(600,300);
    glTexCoord2d(1,0);  glVertex2d(600+256,300);
    glTexCoord2d(1,1);  glVertex2d(600+256,300+128);
    glEnd();
    // afficher le nombre de com
    afficherChiffre(1,725,250);
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
    glColor3ub(255,0,50);
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
    glColor3ub(255,0,50);
    glTexCoord2d(0,1);  glVertex2d(400,50+128);
    glTexCoord2d(0,0);  glVertex2d(400,50);
    glTexCoord2d(1,0);  glVertex2d(400+256,50);
    glTexCoord2d(1,1);  glVertex2d(400+256,50+128);
    glEnd();
}

void Menu::afficherFond(int x,int y)
{
    glBindTexture(GL_TEXTURE_2D, fondm);
    glBegin(GL_QUADS);
    glColor3ub(45,45,45);
    glTexCoord2d(0,1);  glVertex2d(x,y+HAUTEUR_ECRAN);
    glTexCoord2d(0,0);  glVertex2d(x,y);
    glTexCoord2d(1,0);  glVertex2d(x+LARGEUR_ECRAN,y);
    glTexCoord2d(1,1);  glVertex2d(x+LARGEUR_ECRAN,y+HAUTEUR_ECRAN);
    glEnd();
}

