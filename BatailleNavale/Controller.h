/* 
 * File:   Controller.h
 * Author: Olivier
 *
 * Created on 14 mai 2012, 08:47
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H



#include "Partie.h"

#include "Plateau.h"
#include "BateauCase.h"
#include "Interface.h"
#include "InterfaceConsole.h"
#include <iostream>
#include <string>

using namespace std;

//class Interface;
//class InterfaceConsole;

class Controller {
    public:
        /**
         * Constructeur, Cette classe permet de faire le lien
         *  entre le model de donnees et les vues
         * @param partie
         */
        Controller(Partie* partie);
        virtual ~Controller();
        
        /**
         * fonction pour lancer la vue
         * @return 
         */
        void Run();
        
        /**
         *  
         * @return un tableau de string montrant le plateau du joueur courant
         * (entrain de deviner ou sont les bateau adverse)
         */
        string** GetPlateauJoueur_JoueurCourant();
        
        /**
         * 
         * @return un tableau de string montrant ce que l'adveraise du joueur
         *  courant a découvert de son plateau
         */
        string** GetPlateauAdversaire_JoueurCourant();
        
        /**
         * 
         * @return la position des bateaux du joueur courant
         */
        string** GetPlateauPositionBateau_JoueurCourant();
        
        /**
         * Permet de donner la main a l'adversaire du joueur courant
         */
        void JoueurSuivant();
        
        /**
         * permet au joueur courant de jouer en X, Y sur le plateau de l'adversaire
         * @param x
         * @param y
         * @return 
         */
        bool Jouer_JoueurCourant(int x, int y);
        
        /**
         * Permet au joueur courant de poser un bateau
         * @param taille
         * @param x
         * @param y
         * @param align
         * @return 
         */
        bool PoserBateau_JoueurCourant(int taille, int x, int y, ALLIGNEMENT align);
        
        /**
         * 
         * @return la taille du bateau suivant a placer pour le joueur courant
         */
        int GetTaillePlacementBateauSuivant_JoueurCourant();
        
        /**
         * 
         * @return le joueur gagnant ou NULL si il y en a pas
         */
        Joueur* JoueurGagne();
        
        /**
         * Permet d'initialiser la partie (encore vide)
         */
        void InitPartie();
        
        /**
         * 
         * @return la taille X du plateau (nb de ligne)
         */
        int GetTaillePlateauX();
        
        /**
         * 
         * @return lma taille Y du plateau (nb de colone)
         */
        int GetTaillePlateauY();
        
        /**
         * 
         * @param j
         * @return true si le joueur a ete ajoute a la partie
         */
        bool AddJoueur(Joueur* j);
        
        /**
         * 
         * @return true si la partie est lancee
         */
        bool IsPartieLancee();
        
        /**
         * 
         * @return true si tous less bateaux du joueur courant sont places
         */
        bool IsTousBateauxPlace_JoueurCourant();
        
        /**
         * 
         * @return true si le joueur courant a jouer sa case ou son bonus qui finit le tour
         */
        bool IsJoueurCourantAJoue();
        
        /**
         * 
         * @return true si la partie a pu etre lance, permet 
         * d'init certain param de la partie
         */
        bool LancerPartie();
        
        /**
         * 
         * @return le joueurplateau du joueur courant
         */
        JoueurPlateau* GetJoueurCourant();
        
        /**
         * 
         * @return la taille des bateaux maximum sur le plateau
         */
        int GetTailleBateauMax();
        //void AfficherPlateau(Plateau* p);
        //void AfficherPlateauAdversaire(Plateau* p);
    private:
        Interface* interface; //Vue
        Partie* partie; //Donnees
};

#endif	/* CONTROLLER_H */

