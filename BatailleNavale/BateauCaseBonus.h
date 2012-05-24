/* 
 * File:   BateauCaseVide.h
 * Author: Olivier
 *
 * Created on 13 mai 2012, 18:18
 */

#ifndef BATEAUCASEBONUS_H
#define	BATEAUCASEBONUS_H

#include "BateauCase.h"
using namespace std;

class BateauCaseBonus : public BateauCase {
    public:
        BateauCaseBonus(int x, int y, Bonus* bonus);
        ~BateauCaseBonus();
                
        /**
         * Permet de set un bonus a la case.
         * @param bonus
         */
        void SetBonus(Bonus* bonus);
        
        /**
         * Getter du bonus de la case
         * @return 
         */
        Bonus* GetBonus();
       
        
    private:
        Bonus* bonus;
    
};

#endif	/* BATEAUCASEVIDE_H */

