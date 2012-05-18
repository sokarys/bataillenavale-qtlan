/* 
 * File:   BonusManager.h
 * Author: Olivier
 *
 * Created on 18 mai 2012, 15:49
 */

#ifndef BONUSMANAGER_H
#define	BONUSMANAGER_H

#include "Bonus.h"
#include <vector>

using namespace std;

class BonusManager {
    public:
        BonusManager();
        virtual ~BonusManager();
        void AddBonus(Bonus* b);
        void LancerBonus(Bonus* b, Plateau* p, int x, int y, ALLIGNEMENT alig);
        void DelBonus(Bonus* b);
    private:
        vector<Bonus*> bonusListe;
};

#endif	/* BONUSMANAGER_H */
