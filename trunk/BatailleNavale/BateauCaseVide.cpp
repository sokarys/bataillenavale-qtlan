/* 
 * File:   BateauCaseVide.cpp
 * Author: Olivier
 * 
 * Created on 13 mai 2012, 18:18
 */

#include "BateauCaseVide.h"

using namespace std;

BateauCaseVide::BateauCaseVide(int x, int y) : BateauCase(x,y){
    
}

string BateauCaseVide::GetRepresentation(){
    return "0";
}


