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
       void AfficherConsole(string** str, int taillex, int tailley);
       void AfficherMenu();
       bool ChoixMenu();
       void AfficherTout();
       void Clear_screen();
};

#endif	/* INTERFACECONSOLE_H */

