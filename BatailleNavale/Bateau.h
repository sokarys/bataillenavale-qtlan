#ifndef BATEAU_H
#define BATEAU_H

#include "BateauCase.h"

enum ALLIGNEMENT_BATEAU {VERTICAL, HORIZONTAL};
enum ETAT_BATEAU {COULE, PAS_COULE};

#include <vector>

using namespace std;

class Bateau
{
    public:
        Bateau(int x, int y, ALLIGNEMENT_BATEAU align, int taille);
        ~Bateau();
        BateauCase* AddBateauCase(int x, int y);
        BateauCase* GetBateauCase(int x, int y);
        bool GetEtat();
        int GetX();
        int GetY();
        int GetTaille();

    protected:

    private:
        ALLIGNEMENT_BATEAU alignement;
        int x;
        int y;
        int taille;
        ETAT_BATEAU etat;
        vector<BateauCase*> listeBateauCase;
};

#endif // BATEAU_H
