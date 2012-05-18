#ifndef BATEAU_H
#define BATEAU_H

enum ALLIGNEMENT_BATEAU {VERTICAL, HORIZONTAL};
enum ETAT_BATEAU {COULE, PAS_COULE};

#include "BateauCase.h"
#include <vector>


using namespace std;

class Bateau
{
    public:
        Bateau(int x, int y, ALLIGNEMENT_BATEAU align, int taille, string name="NoName");
        ~Bateau();
        BateauCase* AddBateauCase(int x, int y);
        BateauCase* GetBateauCase(int x, int y);
        void CheckEtat();
        ETAT_BATEAU GetEtat();
        void SetEtat(ETAT_BATEAU etat);
        int GetX();
        int GetY();
        int GetTaille();
        string GetName();
        
    protected:

    private:
        ALLIGNEMENT_BATEAU alignement;
        int x;
        int y;
        int taille;
        ETAT_BATEAU etat;
        string name;
        vector<BateauCase*> listeBateauCase;
};

#endif // BATEAU_H
