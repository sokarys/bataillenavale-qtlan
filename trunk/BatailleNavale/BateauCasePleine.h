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
        BateauCasePleine(int x, int y, Bateau* bateau);
        ~BateauCasePleine();
        Bateau* GetBateau();
        void SetBateau(Bateau* bateau);
        void SetEtat(ETAT_BATEAUCASE etat);
    
        string GetRepresentation();
        
    private:
        Bateau* bateau;

};

#endif	/* BATEAUCASEPLEINE_H */

