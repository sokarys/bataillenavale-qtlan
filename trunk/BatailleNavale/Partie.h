#ifndef PARTIE_H
#define PARTIE_H

#include "Variable.h"
#include <vector>
#include <string>
#include <cmath>
#include "Joueur.h"
//#include "Plateau.h"
#include "JoueurPlateau.h"
#include "ControlPlacementBateau.h"

using namespace std;

class Partie
{
    public:
        Partie(int tailleX=10, int tailleY=10, int tailleBateauMax=MAX_TAILLE_BATEAU);
        virtual ~Partie();
        /**
         * Permet de rajouter un joueur a la partie
         * @param joueur
         * @return true si le joueur a ete ajoute
         */
        bool AddJoueur(Joueur* joueur);
        
        /**
         * Del un joueur de la partie
         * @param joueur
         */
        void DelJoueur(Joueur* joueur);
        
        /**
         * Del un joueur de la partie
         * @param indexJoueur
         */
        void DelJoueur(int indexJoueur);
        
        /**
         * Initialise la partie (mise en place des bonus)
         */
        void InitPartie();
        
        /**
         * Permet au joueur suivant de jouer
         */
        void JoueurSuivant();
        
        /**
         * Permet au joueur conrant de jouer
         * @param x
         * @param y
         * @return true si le joueur courant a pu jouer
         */
        bool JoueurCourantJoue(int x, int y);
        
        /**
         * 
         * @param j
         * @return un tab contenant la représentation du tableau de placement des bateaux
         */
        string** JoueurPlateauPlacementBateau(JoueurPlateau* j); /*renvoie le plateau ou il y a ses bateaux*/
        string** JoueurPlateauAdversaire(JoueurPlateau* j); /*renvoie le plateau ou son adversaire a joue*/
        string** JoueurPlateauJoue(JoueurPlateau* j); /*renvoie le plateau du joueur ou il a joue (sur le plateau de l'adversaire)*/
        
        /**
         * 
         * @return le gagnant de la partie, NULL sinon
         */
        Joueur* GetGagnant();
        
        /**
         * 
         * @return le nombre de joueur de la partie
         */
        int GetNbJoueurs();
        
        /**
         * 
         * @return le joueur plateau de l'adversaire
         */
        JoueurPlateau* GetAdversaire_JoueurCourant();
        
        /**
         * 
         * @return la taille en X du plateau (ligne)
         */
        int GetTaillePlateauX();
        
        /**
         * 
         * @return la taille en Y du plateau (colonne)
         */
        int GetTaillePlateauY();
        
        /**
         * 
         * @return le joueurplateau du joueur courant
         */
        JoueurPlateau* GetJoueurCourant();
        
        /**
         * 
         * @param jp
         * @return l'adversaire du joueurplateau place en parametre
         */
        JoueurPlateau* GetAdversaire(JoueurPlateau* jp);
        
        /**
         * 
         * @return true si la partie est lancee
         */
        bool IsPartieLancee();
        
        /**
         * 
         * @return true si le joueur courant a joue
         */
        bool IsJoueurCourantAJoue();
        
        /**
         * Permet de lance la partie
         * @return true si la partie a ete correctement lancee
         */
        bool LancerPartie();
        
        /**
         * 
         * @return la taille maximum des bateaux sur le plateau (5 par default)
         */
        int GetTailleBateauMax();
        
        /**
         * Permet de genere les bateaux qui seront sur le plateau en fonction 
         * de la taille du plateau
         * @param tailleX
         * @param tailleY
         */
        void GenererNbBateau(int tailleX, int tailleY);
        
        /**
         * Permet de generer les bonus qui seront sur le plateau
         *  en fonction de la taille du plateau
         * @param tailleX
         * @param tailleY
         */
        void GenererBonus(int tailleX, int tailleY);
        
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
