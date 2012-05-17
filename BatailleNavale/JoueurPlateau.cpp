/* 
 * File:   JoueurPlateau.cpp
 * Author: Olivier
 * 
 * Created on 17 mai 2012, 14:23
 */

#include "JoueurPlateau.h"
using namespace std;

JoueurPlateau::JoueurPlateau(Joueur* j, Plateau* p){
    this->joueur = j;
    this->plateau = p;
}

JoueurPlateau::~JoueurPlateau() {
}

