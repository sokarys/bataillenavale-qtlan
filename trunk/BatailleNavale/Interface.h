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
    /**
     * Constructeur
     * @param controler, c'est grace au controller que l'on recupere les infos,
     * IL NE FAUT JAMAIS UTILISER LA PARTIE DIRECTEMENT
     */
    Interface(Controller* controler);
    
    /**
     * Destructeur
     */
    virtual ~Interface();
    
    /**
     * Lance l'interface
     */
    virtual void Run();
   
    /**
     * Permet d'afficher le plateau du joueur courant
     */
    virtual void Afficher_PlateauJoueur_JoueurCourant();
    
    /**
     * Permet d'affiche les cout de l'adversaire
     */
    virtual void Afficher_PlateauAdversaire_JoueurCourant();
    
    /**
     * Permet de voir ou son ses bateaux
     */
    virtual void Afficher_PlateauPositionBateau_JoueurCourant();
    
    /**
     * Lance la partie
     */
    void LancerPartie();
    
    /**
     * Permet au joueur suivant de jouer
     */
    void JoueurSuivant();
    
    /**
     * Permet au joueur courant de jouer
     * @param x
     * @param y
     * @return true si il a pu jouer
     */
    bool Jouer_JoueurCourant(int x, int y);
    
    /**
     * Permet au joueur courant de placer un bateau
     * @param taille
     * @param x
     * @param y
     * @param align
     * @return true si le bateau a ete place
     */
    bool PoserBateau_JoueurCourant(int taille, int x, int y, ALLIGNEMENT align);
    
    /**
     * 
     * @return le joueur qui a gagne la partie, NULL sinon
     */
    Joueur* JoueurGagne();
    
protected:
    Controller* controller;

private:
};

#endif	/* INTERFACE_H */

