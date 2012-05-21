/* 
 * File:   Interface.h
 * Author: Olivier
 *
 * Created on 21 mai 2012, 13:11
 */

#ifndef INTERFACE_H
#define	INTERFACE_H

//#include "Controller.h"
#include "Joueur.h"
#include "Variable.h"
#include <string>

class Controller;

using namespace std;

class Interface {
public:
    Interface(Controller* controler);
    virtual ~Interface();
    virtual void Run();
    
   
    virtual void Afficher_PlateauJoueur_JoueurCourant();
    virtual void Afficher_PlateauAdversaire_JoueurCourant();
    virtual void Afficher_PlateauPositionBateau_JoueurCourant();
    
    void LancerPartie();
    void JoueurSuivant();
    bool Jouer_JoueurCourant(int x, int y);
    bool PoserBateau_JoueurCourant(int taille, int x, int y, ALLIGNEMENT align);
    Joueur* JoueurGagne();
    
protected:
    Controller* controller;

private:
};

#endif	/* INTERFACE_H */

