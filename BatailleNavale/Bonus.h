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

class Plateau;
using namespace std;

class Bonus {
    public:
        /**
         * Constructeur
         * @param name du bonus
         * @param finDuTour si l'utilisation du bonus provoque
         *        la fin du tour du joueur
         * @param nbTourEffet  combien de tour dure le bonus
         */
        Bonus(string name, bool finDuTour=false, int nbTourEffet=0);
        /**
         * Destructeur
         */
        virtual ~Bonus();
        
        /**
         * fonction pour lancer le bonus. Doit etre surcharge pour
         *          chaque nouveau type de bonus
         * @param p plateau sur le quel on lance le bonus
         * @param cibleX le x de la case sur lequel s'applique le bonus
         * @param cibleY le y de la case sur lequel s'applique le bonus
         * @param align optionnel en fonction du bonus utilise
         * @return 
         */
        virtual bool lancerBonus(Plateau* p, int cibleX, int cibleY, ALLIGNEMENT align = RIEN);
    private:
        string name;
        bool finDuTour;
        int nbTourEffet;
};

#endif	/* BONUS_H */
