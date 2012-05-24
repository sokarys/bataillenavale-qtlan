/* 
 * File:   BateauCaseVide.cpp
 * Author: Olivier
 * 
 * Created on 13 mai 2012, 18:18
 */

#include "BateauCaseBonus.h"

using namespace std;

BateauCaseBonus::BateauCaseBonus(int x, int y, Bonus* bonus) : BateauCase(x,y){
    this->bonus = bonus;
}

/**
 * Set un bonus a la bateauCase
 * @param bonus
 */
void BateauCaseBonus::SetBonus(Bonus* bonus){
    this->bonus = bonus;
}

/**
 * 
 * @return le bonus de la case associé
 */
Bonus* BateauCaseBonus::GetBonus(){
    return this->bonus;
}

//string BateauCaseVide::GetRepresentation(){
//    return REP_EAU;
//}


