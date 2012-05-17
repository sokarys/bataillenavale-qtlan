#ifndef JOUEUR_H
#define JOUEUR_H

//#include "Partie.h"
#include "Plateau.h"

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
        Plateau* plateau;
//        Partie* partie;
        
};

#endif // JOUEUR_H
