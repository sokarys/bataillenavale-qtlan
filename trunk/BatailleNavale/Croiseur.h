/* 
 * File:   Croiseur.h
 * Author: Olivier
 *
 * Created on 18 mai 2012, 14:58
 */

#ifndef CROISEUR_H
#define	CROISEUR_H

#include "Bateau.h"


class Croiseur : public Bateau{
public:
    Croiseur(int x, int y, ALLIGNEMENT align);
    virtual ~Croiseur();
};

#endif	/* CROISEUR_H */

