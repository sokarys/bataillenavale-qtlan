#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include "Joueur.h"

using namespace std;

class Partie
{
    public:
        Partie();
        virtual ~Partie();
        void AddJoueur(Joueur* joueur);
        void DelJoueur(Joueur* joueur);
        void DelJoueur(int indexJoueur);
        void InitPartie();
        void JoueurSuivant();
        Joueur* GetGagnant();
    
    protected:
        
    private:
        bool partieLance;
        int NbBateauMax;
        vector<Joueur*> listeJoueur;
        Joueur* joueurCourant;
};

#endif // PARTIE_H
