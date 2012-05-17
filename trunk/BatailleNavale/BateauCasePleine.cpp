/* 
 * File:   BateauCasePleine.cpp
 * Author: Olivier
 * 
 * Created on 13 mai 2012, 18:18
 */

#include "BateauCasePleine.h"


using namespace std;

BateauCasePleine::BateauCasePleine(int x, int y, Bateau* bateau) : BateauCase(x,y) {
    this->bateau = bateau;
}

BateauCasePleine::~BateauCasePleine(){
    
}

void BateauCasePleine::SetEtat(ETAT_BATEAUCASE etat){
    BateauCase::SetEtat(etat);
    this->bateau->CheckEtat();
}

Bateau* BateauCasePleine::GetBateau(){
    return this->bateau;
}

void BateauCasePleine::SetBateau(Bateau* bateau){
    this->bateau = bateau;
}

string BateauCasePleine::GetRepresentation(){
    stringstream ss;
    ss << this->GetBateau()->GetTaille();
    return ss.str();
}

