/* 
 * File:   BonusManager.h
 * Author: Olivier
 *
 * Created on 18 mai 2012, 15:49
 */

#ifndef BONUSMANAGER_H
#define	BONUSMANAGER_H

#include "Bonus.h"
#include "Plateau.h"
#include "Variable.h"
#include <vector>

class Bonus;
class Plateau;

using namespace std;

class BonusManager {
    public:
        BonusManager();
        virtual ~BonusManager();
        /**
         * Rajout un bonus au manager
         * @param b
         */
        void AddBonus(Bonus* b);
        
        /**
         * Joueur le bonus selectioné, puis le supprime de la liste de bonus disponible
         * @param b le bonus que l'on lance
         * @param p le plateau sur lequel on le lance
         * @param x la coordonee en X ou est lance le bonus
         * @param y la cooredonne en Y ou est lance le bonus 
         * @param alig  l'alignemenet du bonus, pas obligatoire
         * @return true si le bonus a pu etre lance, false sinon
         */
        bool LancerBonus(Bonus* b, Plateau* p, int x, int y, ALLIGNEMENT alig);
        
        /**
         * Supprimer le bonus B
         * @param b
         */
        void DelBonus(Bonus* b);
        
    private:
        vector<Bonus*> bonusListe; //Bonus disponible pour le joueur
};

#endif	/* BONUSMANAGER_H */
