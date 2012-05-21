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
        Controller(Partie* partie);
        virtual ~Controller();
        void Run();
        
        string** GetPlateauJoueur_JoueurCourant();
        string** GetPlateauAdversaire_JoueurCourant();
        string** GetPlateauPositionBateau_JoueurCourant();
        void JoueurSuivant();
        bool Jouer_JoueurCourant(int x, int y);
        bool PoserBateau_JoueurCourant(int taille, int x, int y, ALLIGNEMENT align);
        int GetTaillePlacementBateauSuivant_JoueurCourant();
        Joueur* JoueurGagne();
        void InitPartie();
        
        int GetTaillePlateauX();
        int GetTaillePlateauY();
        bool AddJoueur(Joueur* j);
        bool IsPartieLancee();
        bool IsTousBateauxPlace_JoueurCourant();
        bool IsJoueurCourantAJoue();
        
        //void AfficherPlateau(Plateau* p);
        //void AfficherPlateauAdversaire(Plateau* p);
    private:
        Interface* interface;
        Partie* partie;
};

#endif	/* CONTROLLER_H */

