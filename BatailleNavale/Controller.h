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
         * @return 
         */
        string** GetPlateauJoueur_JoueurCourant();
        
        /**
         * 
         * @return 
         */
        string** GetPlateauAdversaire_JoueurCourant();
        
        /**
         * 
         * @return 
         */
        string** GetPlateauPositionBateau_JoueurCourant();
        
        /**
         * 
         */
        void JoueurSuivant();
        
        /**
         * 
         * @param x
         * @param y
         * @return 
         */
        bool Jouer_JoueurCourant(int x, int y);
        
        /**
         * 
         * @param taille
         * @param x
         * @param y
         * @param align
         * @return 
         */
        bool PoserBateau_JoueurCourant(int taille, int x, int y, ALLIGNEMENT align);
        
        /**
         * 
         * @return 
         */
        int GetTaillePlacementBateauSuivant_JoueurCourant();
        
        /**
         * 
         * @return 
         */
        Joueur* JoueurGagne();
        
        /**
         * 
         */
        void InitPartie();
        
        /**
         * 
         * @return 
         */
        int GetTaillePlateauX();
        
        /**
         * 
         * @return 
         */
        int GetTaillePlateauY();
        
        /**
         * 
         * @param j
         * @return 
         */
        bool AddJoueur(Joueur* j);
        
        /**
         * 
         * @return 
         */
        bool IsPartieLancee();
        
        /**
         * 
         * @return 
         */
        bool IsTousBateauxPlace_JoueurCourant();
        
        /**
         * 
         * @return 
         */
        bool IsJoueurCourantAJoue();
        
        /**
         * 
         * @return 
         */
        bool LancerPartie();
        
        /**
         * 
         * @return 
         */
        JoueurPlateau* GetJoueurCourant();
        
        /**
         */
        int GetTailleBateauMax();
        //void AfficherPlateau(Plateau* p);
        //void AfficherPlateauAdversaire(Plateau* p);
    private:
        Interface* interface;
        Partie* partie;
};

#endif	/* CONTROLLER_H */

