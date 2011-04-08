
#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>

class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();
    protected:
        std::string _nom;
        int score;
    private:
};

#endif // JOUEUR_H
