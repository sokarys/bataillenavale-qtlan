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
    /**
     * Constructeur
     * @param BateauAPlacer : tableau contenant un tableau avec le nombre
     *  de bateau a placer. L'indice correspond a la taille du bateau
     * @param tailleBateauMax taille max de la taille des bateaux
     */
    ControlPlacementBateau(int* BateauAPlacer=NULL, int tailleBateauMax=MAX_TAILLE_BATEAU);
    
    /**
     * Destrucuteur
     */
    virtual ~ControlPlacementBateau();
    
    /**
     * Fonction pour dire que le joueur a place le bateau de taille b
     * @param b
     */
    void AddBateauPlace(Bateau* b);
    
    /**
     * 
     * @return true si tous les bateaux sont placés
     */
    bool TousLesBateauxPlace();
    
    /**
     * 
     * @return la taille du bateau suivant a placer sur le jeux
     */
    int GetTaillePlacementBateauSuivant();
    
    int* GetBateauRestanAPlacer();
    
private:
    int* BateauAPlacer;
    int* BateauPlace;
    int tailleBateauMax;
};

#endif	/* CONTROLPLACEMENTBATEAU_H */

