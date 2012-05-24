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
#include "BonusManager.h"
using namespace std;

class JoueurPlateau {
    public:
        JoueurPlateau(Joueur* j, Plateau* p);
        virtual ~JoueurPlateau();
        /**
         * 
         * @return le joueur associe a cet objet
         */
        Joueur* GetJoueur();
        
        /**
         * 
         * @return le plateau associe a cet objet
         */
        Plateau* GetPlateau();
        
        /**
         * 
         * @return le bonus manager associe au joueur et au plateau
         */
        BonusManager* GetBonusManager();
        
        /**
         * 
         * @param j
         * @return true si les joueurs sont egal (meme nom, meme password)
         */
        bool IsJoueurEqals(Joueur* j);
        
        /**
         * 
         * @return true si tous les bateau du joueurs sont places
         */
        bool IsTousLesBateauxPlaces();
    private:
        Joueur* joueur;
        Plateau* plateau;
        BonusManager* bonusManager;

};

#endif	/* JOUEURPLATEAU_H */

