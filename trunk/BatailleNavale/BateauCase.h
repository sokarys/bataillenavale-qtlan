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
        /**
         * Constructeur du bateau case
         * @param x : position en x sur le plateau de cet objet
         * @param y : position en y sur le plateau de cet objet
         */
        BateauCase(int x, int y);
        
        /**
         * Destructeur
         */
        ~BateauCase(){};
        
        /**
         * Setter de X
         * @param x
         */
        void SetX(int x);
        
        /**
         * Setter de Y
         * @param y
         */
        void SetY(int y);
        
        /**
         * Setter de l'etat de la case
         * @param etat
         */
        void SetEtat(ETAT_BATEAUCASE etat);
        
        /**
         * Getter de X
         * @return 
         */
        int GetX();
        
        /**
         * Getter de Y
         * @return 
         */
        int GetY();
        
        /**
         * Getter de l'etat du bateaucase
         * @return 
         */
        ETAT_BATEAUCASE GetEtat();
        
        /**
         * Fonction virtuel qui doit etre implemente dans les classes qui l'hérite
         * @return la representation de la case vu par le joueur qui la possede
         */
        virtual string GetRepresentation();
        
        /**
         * 
         * @return la représentation de la case vu par l'adversaire
         */
        string GetRepresentationAdversaire();
        
        /**
         * Surcharge de l'operateur << 
         * @param bonus
         */
        friend ostream& operator<< (ostream& out, BateauCase& b);
        
        /**
         * Permet de set un bonus a la case.
         * @param bonus
         */
        void SetBonus(Bonus* bonus);
        
        /**
         * Getter du bonus de la case
         * @return 
         */
        Bonus* GetBonus();
        
    protected:

    private:
        int x;
        int y;
        ETAT_BATEAUCASE etat;
        Bonus* bonus;
};

#endif // BATEAUCASE_H
