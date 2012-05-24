/* 
 * File:   Bonus.cpp
 * Author: Olivier
 * 
 * Created on 18 mai 2012, 15:07
 */

#include "Bonus.h"

Bonus::Bonus(string name, bool finDuTour, int nbTourEffet){
    this->name = name;
    this->finDuTour = finDuTour;
    this->nbTourEffet = nbTourEffet;
}

Bonus::~Bonus() {
}
//virtual bool lancerBonus(Plateau* p, int cibleX, int cibleY, ALLIGNEMENT align = RIEN){return false;};
bool Bonus::lancerBonus(Plateau* plateau, int cibleX, int cibleY, ALLIGNEMENT align){
    return false;
}
