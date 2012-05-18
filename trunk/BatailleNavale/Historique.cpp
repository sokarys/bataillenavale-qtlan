/* 
 * File:   Historique.cpp
 * Author: Olivier
 * 
 * Created on 17 mai 2012, 19:05
 */

#include "Historique.h"

Historique::Historique(int victoire, int defaite, int abandon) {
    this->abandon = abandon;
    this->defaite = defaite;
    this->victoire = victoire;
}

Historique::~Historique() {
}

void Historique::AddAbandon(){
    this->abandon++;
}

void Historique::AddDefaite(){
    this->defaite++;
}

void Historique::AddVictoire(){
    this->victoire++;
}

void Historique::SetAbandon(int abandon){
    this->abandon = abandon;
}

void Historique::SetDefaite(int defaite){
    this->defaite = defaite;
}

void Historique::SetVictoire(int victoire){
    this->victoire = victoire;
}

int Historique::GetAbandon(){
    return this->abandon;
}

int Historique::GetDefaite(){
    return this->defaite;
} 

int Historique::GetVictoire(){
    return this->victoire;
}
