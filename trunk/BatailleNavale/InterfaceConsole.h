/* 
 * File:   InterfaceConsole.h
 * Author: Olivier
 *
 * Created on 21 mai 2012, 13:10
 */

#ifndef INTERFACECONSOLE_H
#define	INTERFACECONSOLE_H

#include "Variable.h"
//#include "Interface.h"
#include "Joueur.h"
#include "Controller.h"

#include <cstdlib>
#include <iostream>
#include <string>

//class Interface;

using namespace std;
class InterfaceConsole : public Interface{
    public:
        InterfaceConsole(Controller* controller);
        virtual ~InterfaceConsole();
        virtual void Run();
   
        virtual void Afficher_PlateauJoueur_JoueurCourant();
        virtual void Afficher_PlateauAdversaire_JoueurCourant();
        virtual void Afficher_PlateauPositionBateau_JoueurCourant();

        void JoueurSuivant();
        bool Jouer_JoueurCourant(int x, int y);
        bool PoserBateau_JoueurCourant(int taille, int x, int y, ALLIGNEMENT align);
        Joueur* JoueurGagne();
        
    private:
        /**
         * Permet d'affiche un plateau
         * @param str
         * @param taillex
         * @param tailley
         */
       void AfficherConsole(string** str, int taillex, int tailley);
       
       /**
        * ¨permet d'afficher le menu
        */
       void AfficherMenu();
       
       /**
        * Permet au joueur courant de choisir une action du menu
        * @return 
        */
       bool ChoixMenu();
       
       /**
        * Permet d'afficher tous les plateaux
        */
       void AfficherTout();
       
       /**
        * Vide la console
        */
       void Clear_screen();
};

#endif	/* INTERFACECONSOLE_H */

