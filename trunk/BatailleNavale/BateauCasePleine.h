/* 
 * File:   BateauCasePleine.h
 * Author: Olivier
 *
 * Created on 13 mai 2012, 18:18
 */

#ifndef BATEAUCASEPLEINE_H
#define	BATEAUCASEPLEINE_H

#include "Bateau.h"
#include "BateauCase.h"


class BateauCasePleine : public BateauCase {
    
    public:
        BateauCasePleine(int x, int y, Bateau* bateau);
        ~BateauCasePleine();
        Bateau* GetBateau();
        void SetBateau(Bateau* bateau);
    
        string GetRepresentation();
        
    private:
        Bateau* bateau;

};

#endif	/* BATEAUCASEPLEINE_H */

