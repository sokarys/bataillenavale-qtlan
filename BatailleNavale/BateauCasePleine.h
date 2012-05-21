/* 
 * File:   BateauCasePleine.h
 * Author: Olivier
 *
 * Created on 13 mai 2012, 18:18
 */

#ifndef BATEAUCASEPLEINE_H
#define	BATEAUCASEPLEINE_H

#include "BateauCase.h"
#include "Bateau.h"

#include <string>
#include <sstream>

using namespace std;

class BateauCasePleine : public BateauCase {
    
    public:
        /**
         * Constructeur
         * @param x
         * @param y
         * @param bateau : le bateau au quel la case est ratachee
         */
        BateauCasePleine(int x, int y, Bateau* bateau);
        
        /**
         * Destrucuteur
         */
        ~BateauCasePleine();
        
        /**
         * Getter
         * @return le bateay attache a la case
         */
        Bateau* GetBateau();
        
        /**
         * Setter du bateau
         * @param bateau
         */
        void SetBateau(Bateau* bateau);
        
        /**
         * Setteur etat
         * @param etat
         */
        void SetEtat(ETAT_BATEAUCASE etat);
        
        /**
         * Surcharge de la representation si la case est une partie d'un bateau
         * @return 
         */
        string GetRepresentation();
        
    private:
        Bateau* bateau;

};

#endif	/* BATEAUCASEPLEINE_H */

