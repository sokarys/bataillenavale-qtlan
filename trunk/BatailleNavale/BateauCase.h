#ifndef BATEAUCASE_H
#define BATEAUCASE_H

#include <string>
#include <ostream>

using namespace std;

enum ETAT_BATEAUCASE {TOUCHE, EAU, PAS_JOUEE};

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
        
    protected:

    private:
        int x;
        int y;
        ETAT_BATEAUCASE etat;
};

#endif // BATEAUCASE_H
