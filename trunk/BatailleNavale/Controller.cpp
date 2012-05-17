/* 
 * File:   Controller.cpp
 * Author: Olivier
 * 
 * Created on 14 mai 2012, 08:47
 */

#include "Controller.h"

using namespace std;

Controller::Controller() {
}


Controller::~Controller() {
}

void Controller::AfficherPlateauAdversaire(Plateau* p){
    if(p != NULL){
        int taillex = p->GetTailleX();
        int tailley = p->GetTailleY();
        for(int x=0; x<taillex; x++){
            for(int y=0; y<tailley; y++){
                BateauCase *b = p->GetBateauCase(x,y);
                cout << b->GetRepresentationAdversaire();
            }
            cout << endl;
        }
    }
}

void Controller::AfficherPlateau(Plateau* p){
    if(p != NULL){
        int taillex = p->GetTailleX();
        int tailley = p->GetTailleY();
        for(int x=0; x<taillex; x++){
            for(int y=0; y<tailley; y++){
                BateauCase *b = p->GetBateauCase(x,y);
                cout << *b;
            }
            cout << endl;
        }
    }
}
