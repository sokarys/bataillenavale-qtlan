#ifndef JOUEUR_H
#define JOUEUR_H

#include "Bateau.h"

#include <string>

using namespace std;

class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();
        
        string Jouer(int x, int y);
        string PlacerBateau(int x, int y, int taille, ALLIGNEMENT_BATEAU a);
        string** GetPlateauJoueur();
        string** GetPlateauAdversaire();
        
    protected:
        
    private:
        string name;
        
};

#endif // JOUEUR_H
