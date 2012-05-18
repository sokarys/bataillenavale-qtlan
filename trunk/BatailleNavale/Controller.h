/* 
 * File:   Controller.h
 * Author: Olivier
 *
 * Created on 14 mai 2012, 08:47
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include <iostream>
#include <string>

#include "Plateau.h"
#include "BateauCase.h"


using namespace std;

class Controller {
    public:
        Controller();
        virtual ~Controller();
        
//        string** GetPlateauJoue(Joueur* j);
//        string** GetPlateauAdversaire(Joueur* j);
//        string** GetPlateauPositionBateau(Joueur* j);
        
        void AfficherPlateau(Plateau* p);
        void AfficherPlateauAdversaire(Plateau* p);
    private:

};

#endif	/* CONTROLLER_H */

