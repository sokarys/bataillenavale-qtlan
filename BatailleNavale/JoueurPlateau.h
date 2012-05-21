/* 
 * File:   JoueurPlateau.h
 * Author: Olivier
 *
 * Created on 17 mai 2012, 14:23
 */

#ifndef JOUEURPLATEAU_H
#define	JOUEURPLATEAU_H

#include "Plateau.h"
#include "Joueur.h"
using namespace std;

class JoueurPlateau {
    public:
        JoueurPlateau(Joueur* j, Plateau* p);
        virtual ~JoueurPlateau();
        
        Joueur* GetJoueur();
        Plateau* GetPlateau();
        
        bool IsJoueurEqals(Joueur* j);
        
        bool IsTousLesBateauxPlaces();
    private:
        Joueur* joueur;
        Plateau* plateau;

};

#endif	/* JOUEURPLATEAU_H */

