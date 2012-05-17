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
        void AfficherPlateau(Plateau* p);
        void AfficherPlateauAdversaire(Plateau* p);
    private:

};

#endif	/* CONTROLLER_H */

