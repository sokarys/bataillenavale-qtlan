#ifndef PARTIE_H
#define PARTIE_H

#include "Variable.h"
#include <vector>
#include <string>
#include "Joueur.h"
//#include "Plateau.h"
#include "JoueurPlateau.h"
#include "ControlPlacementBateau.h"

using namespace std;

class Partie
{
    public:
        Partie(int tailleX=10, int tailleY=10,int* nombreTailleBateau=NULL, int tailleBateauMax=MAX_TAILLE_BATEAU);
        virtual ~Partie();
        bool AddJoueur(Joueur* joueur);
        void DelJoueur(Joueur* joueur);
        void DelJoueur(int indexJoueur);
        void InitPartie();
        void JoueurSuivant();
        bool JoueurCourantJoue(int x, int y);
        string** JoueurPlateauPlacementBateau(JoueurPlateau* j); /*renvoie le plateau ou il y a ses bateaux*/
        string** JoueurPlateauAdversaire(JoueurPlateau* j); /*renvoie le plateau ou son adversaire a joue*/
        string** JoueurPlateauJoue(JoueurPlateau* j); /*renvoie le plateau du joueur ou il a joue (sur le plateau de l'adversaire)*/
        Joueur* GetGagnant();
        int GetNbJoueurs();
        JoueurPlateau* GetAdversaire_JoueurCourant();
        int GetTaillePlateauX();
        int GetTaillePlateauY();
        JoueurPlateau* GetJoueurCourant();
        JoueurPlateau* GetAdversaire(JoueurPlateau* jp);
        bool IsPartieLancee();
        bool IsJoueurCourantAJoue();
    protected:
        
    private:
        int tailleX;
        int tailleY;
        bool partieLance;
        bool joueurCourantAjoue;
        int NbBateauMax;
        vector<JoueurPlateau*> listeJoueur;
        JoueurPlateau* joueurCourant;
        int tailleBateauMax;
        int* nombreTailleBateau;
};

#endif // PARTIE_H
