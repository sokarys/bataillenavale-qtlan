/* 
 * File:   Interface.cpp
 * Author: Olivier
 * 
 * Created on 21 mai 2012, 13:11
 */

#include "Interface.h"
#include "Controller.h"

using namespace std;

Interface::Interface(Controller* controller) {
    this->controller = controller;
}

Interface::~Interface() {
}

void Interface::Run(){
    throw new string("Run must be implemented");

}

void Interface::Afficher_PlateauJoueur_JoueurCourant(){
    throw new string("Afficher_PlateauJoueur_JoueurCourant must be implemented");
}

void Interface::Afficher_PlateauAdversaire_JoueurCourant(){
    throw new string("Afficher_PlateauAdversaire_JoueurCourant must be implemented");
}

void Interface::Afficher_PlateauPositionBateau_JoueurCourant(){
    throw new string("Afficher_PlateauPositionBateau_JoueurCourant must be implemented");
}

void Interface::JoueurSuivant(){
    this->controller->JoueurSuivant();   
}

bool Interface::Jouer_JoueurCourant(int x, int y){
    return this->controller->Jouer_JoueurCourant(x, y);
}

bool Interface::PoserBateau_JoueurCourant(int taille, int x, int y, ALLIGNEMENT align){
    return this->controller->PoserBateau_JoueurCourant(taille, x, y, align);
}

Joueur* Interface::JoueurGagne(){
    return this->controller->JoueurGagne();
}
