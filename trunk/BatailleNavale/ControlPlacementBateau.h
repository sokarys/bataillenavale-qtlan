/* 
 * File:   ControlPlacementBateau.h
 * Author: Olivier
 *
 * Created on 21 mai 2012, 15:21
 */

#ifndef CONTROLPLACEMENTBATEAU_H
#define	CONTROLPLACEMENTBATEAU_H

#include "Bateau.h"
#include "Variable.h"

class ControlPlacementBateau {
public:
    ControlPlacementBateau(int* BateauAPlacer=NULL, int tailleBateauMax=MAX_TAILLE_BATEAU);
    void AddBateauPlace(Bateau* b);
    bool TousLesBateauxPlace();
    int GetTaillePlacementBateauSuivant();
    virtual ~ControlPlacementBateau();
private:
    int* BateauAPlacer;
    int* BateauPlace;
    int tailleBateauMax;
};

#endif	/* CONTROLPLACEMENTBATEAU_H */

