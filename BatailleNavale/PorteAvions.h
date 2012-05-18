/* 
 * File:   PorteAvions.h
 * Author: Olivier
 *
 * Created on 18 mai 2012, 14:55
 */

#ifndef PORTEAVIONS_H
#define	PORTEAVIONS_H

#include "Bateau.h"


class PorteAvions : public Bateau{
public:
    PorteAvions(int x, int y, ALLIGNEMENT align);
    virtual ~PorteAvions();
};

#endif	/* PORTEAVIONS_H */

