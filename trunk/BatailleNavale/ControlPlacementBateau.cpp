/* 
 * File:   ControlPlacementBateau.cpp
 * Author: Olivier
 * 
 * Created on 21 mai 2012, 15:21
 */

#include "ControlPlacementBateau.h"
#include <iostream>
using namespace std;

ControlPlacementBateau::ControlPlacementBateau(int* bateauAPlacer, int tailleBateauMax) {
    this->tailleBateauMax=tailleBateauMax;
    this->BateauAPlacer = new int[tailleBateauMax+1];
    this->BateauPlace = new int[tailleBateauMax+1];
    for(int i = 0; i<=tailleBateauMax; i++){
        this->BateauAPlacer[i] = bateauAPlacer[i];
        this->BateauPlace[i] = bateauAPlacer[i];
    }
}

bool ControlPlacementBateau::TousLesBateauxPlace(){
    for(int i = 0; i<=tailleBateauMax; i++){
        if(this->BateauPlace[i] != 0){
            return false;
        }
    }
    return true;
}

void ControlPlacementBateau::AddBateauPlace(Bateau* b){
    int tailleB =  b->GetTaille();
    if(this->tailleBateauMax >= tailleB){
        if(this->BateauPlace[tailleB]>0){
            this->BateauPlace[tailleB]--;
        }
    }
}

int ControlPlacementBateau::GetTaillePlacementBateauSuivant(){
     for(int i = 0; i<=this->tailleBateauMax; i++){
        if(this->BateauPlace[i] > 0){
            return i;
        }
    }
     return -1;
}

ControlPlacementBateau::~ControlPlacementBateau() {
}

