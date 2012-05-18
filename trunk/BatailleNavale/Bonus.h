/* 
 * File:   Bonus.h
 * Author: Olivier
 *
 * Created on 18 mai 2012, 15:07
 */

#ifndef BONUS_H
#define	BONUS_H

#include <string>

#include "Plateau.h"
#include "Variable.h"

using namespace std;

class Bonus {
    public:
        Bonus(string name, bool finDuTour=false, int nbTourEffet=0);
        virtual ~Bonus();
        virtual bool lancerBonus(Plateau* p, int cibleX, int cibleY, ALLIGNEMENT align = RIEN){return false;};
    private:
        string name;
        bool finDuTour;
        int nbTourEffet;
};

#endif	/* BONUS_H */
