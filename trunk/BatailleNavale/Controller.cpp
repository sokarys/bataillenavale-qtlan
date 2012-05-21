/* 
 * File:   Controller.cpp
 * Author: Olivier
 * 
 * Created on 14 mai 2012, 08:47
 */

#include "Controller.h"

using namespace std;

Controller::Controller(Partie* partie) {
    this->interface = new InterfaceConsole(this);
    this->partie = partie;
}


Controller::~Controller() {
    delete interface;
    delete partie;
}

void Controller::Run(){
    this->interface->Run();
}

void Controller::InitPartie(){
    this->partie->InitPartie();
}

string** Controller::GetPlateauJoueur_JoueurCourant(){
    return this->partie->JoueurPlateauJoue(this->partie->GetJoueurCourant());
}

string** Controller::GetPlateauAdversaire_JoueurCourant(){
    return this->partie->JoueurPlateauAdversaire(this->partie->GetJoueurCourant());
}

string** Controller::GetPlateauPositionBateau_JoueurCourant(){
    return this->partie->JoueurPlateauPlacementBateau(this->partie->GetJoueurCourant());
}

void Controller::JoueurSuivant(){
    this->partie->JoueurSuivant();
}

bool Controller::Jouer_JoueurCourant(int x, int y){
    if(this->partie->GetJoueurCourant() == NULL){
        throw new string("Joueur NULL PoserBateau_JoueurCourant");
        return false;
    }
    return this->partie->JoueurCourantJoue(x,y);
}

bool Controller::PoserBateau_JoueurCourant(int taille, int x, int y, ALLIGNEMENT align){
    if(this->partie->GetJoueurCourant() == NULL){
        throw new string("Joueur NULL PoserBateau_JoueurCourant");
        return false;
    }
    return this->partie->GetJoueurCourant()->GetPlateau()->SetBateau(taille,x,y,align);
}

Joueur* Controller::JoueurGagne(){
    return this->partie->GetGagnant();
}

int Controller::GetTaillePlateauX(){
    return this->partie->GetTaillePlateauX();
}

int Controller::GetTaillePlateauY(){
    return this->partie->GetTaillePlateauY();
}
        
bool Controller::AddJoueur(Joueur* j){
    return this->partie->AddJoueur(j);
}

bool Controller::IsPartieLancee(){
    return this->partie->IsPartieLancee();
}

bool Controller::IsTousBateauxPlace_JoueurCourant(){
    if(this->partie->GetJoueurCourant() == NULL){
        throw new string("Joueur NULL PoserBateau_JoueurCourant");
        return false;
    }
    return this->partie->GetJoueurCourant()->IsTousLesBateauxPlaces();
}

bool Controller::IsJoueurCourantAJoue(){
    return this->partie->IsJoueurCourantAJoue();
}

int Controller::GetTaillePlacementBateauSuivant_JoueurCourant(){
    return this->partie->GetJoueurCourant()->GetPlateau()->GetTaillePlacementBateauSuivant();
}

bool Controller::LancerPartie(){
    this->partie->LancerPartie();
}

JoueurPlateau* Controller::GetJoueurCourant(){
#if DEBUG
    cout << "Cour " << this->partie->GetJoueurCourant()->GetJoueur()->GetName() << endl;
    cout << "adv " << this->partie->GetAdversaire(this->partie->GetJoueurCourant())->GetJoueur()->GetName() << endl;
#endif
    return this->partie->GetJoueurCourant();
}
