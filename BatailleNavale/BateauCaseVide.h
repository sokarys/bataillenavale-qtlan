/* 
 * File:   BateauCaseVide.h
 * Author: Olivier
 *
 * Created on 13 mai 2012, 18:18
 */

#ifndef BATEAUCASEVIDE_H
#define	BATEAUCASEVIDE_H

#include "BateauCase.h"
using namespace std;

class BateauCaseVide : public BateauCase {
    public:
        BateauCaseVide(int x, int y);
        ~BateauCaseVide();
        string GetRepresentation();

};

#endif	/* BATEAUCASEVIDE_H */

