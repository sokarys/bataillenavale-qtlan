#ifndef PARTIE_H
#define PARTIE_H

#include "Variable.h"
#include <vector>
#include "Joueur.h"
#include "JoueurPlateau.h"

using namespace std;

class Partie
{
    public:
        Partie();
        virtual ~Partie();
        void AddJoueur(Joueur& joueur);
        void DelJoueur(Joueur* joueur);
        void DelJoueur(int indexJoueur);
        void InitPartie();
        void JoueurSuivant();
        void JoueurCourantJoue(int x, int y);
        string** JoueurPlateauPlacementBateau(Joueur* j); /*renvoie le plateau ou il y a ses bateaux*/
        string** JoueurPlateauAdversaire(Joueur* j); /*renvoie le plateau ou son adversaire a joue*/
        string** JoueurPlateauJoue(Joueur* j); /*renvoie le plateau du joueur ou il a joue (sur le plateau de l'adversaire)*/
        Joueur* GetGagnant();
    
    protected:
        
    private:
        bool partieLance;
        int NbBateauMax;
        vector<JoueurPlateau*> listeJoueur;
        JoueurPlateau* joueurCourant;
};

#endif // PARTIE_H
