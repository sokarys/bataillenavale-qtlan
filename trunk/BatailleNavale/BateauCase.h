#ifndef BATEAUCASE_H
#define BATEAUCASE_H

//#include "Bonus.h"

//#include "Bateau.h"
//#include "Plateau.h"
#include <string>
#include <ostream>
#include "Variable.h"
//#include "Bonus.h"

class Bonus;

using namespace std;

class BateauCase
{
    public:
        BateauCase(int x, int y);
        ~BateauCase(){};
        void SetX(int x);
        void SetY(int y);
        void SetEtat(ETAT_BATEAUCASE etat);
        int GetX();
        int GetY();
        ETAT_BATEAUCASE GetEtat();
        virtual string GetRepresentation();
        string GetRepresentationAdversaire();
        friend ostream& operator<< (ostream& out, BateauCase& b);
        void SetBonus(Bonus* bonus);
        Bonus* GetBonus();
        
    protected:

    private:
        int x;
        int y;
        ETAT_BATEAUCASE etat;
        Bonus* bonus;
//        Bonus* bonus;
};

#endif // BATEAUCASE_H
