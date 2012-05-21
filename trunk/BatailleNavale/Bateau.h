#ifndef BATEAU_H
#define BATEAU_H

#include "Variable.h"
#include "BateauCase.h"
#include <vector>


using namespace std;

class Bateau
{
    public:
        /**
         * Construcuteur
         * @param x : position en X sur le plateau de la case la plus en haut a gauche
         * @param y : position en Y sur le plateau de la case la plus en haut a gauche
         * @param align : alignement du bateau VERTICAL ou Horizontal
         * @param taille : taille du bateau en nombre de case
         * @param name : nom du bateau
         */
        Bateau(int x, int y, ALLIGNEMENT align, int taille, string name="NoName");
        
        /**
         * Destructeur
         */
        ~Bateau();
        
        /**
         * Rajouter une case au bateau
         * @param x : position de la case sur le plateau en X
         * @param y : position de la case sur le plateau en Y
         * @return le bateau case rajoute
         */
        BateauCase* AddBateauCase(int x, int y);
        
        /**
         * Permet de mettre l'etat du bateau a jour si toutes ses 
         * parties sont touche, le bateau passe a coule
         */
        void CheckEtat();
        
        /**
         * 
         * @return l'etat du bateau : coule ou pas coule
         */
        ETAT_BATEAU GetEtat();
        
        /**
         * Permet de modifier l'etat du bateau
         * @param etat
         */
        void SetEtat(ETAT_BATEAU etat);
        
        /**
         * 
         * @return la position X du bateau sur le plateau de la case en haut a gauche
         */
        int GetX();
        
        /**
         * 
         * @return la position Y du bateau sur le plateau de la case en haut a gauche
         */
        int GetY();
        
        /**
         * 
         * @return la taille du bateau en nombre de case
         */
        int GetTaille();
        
        /**
         * 
         * @return l'alignement du bateau VERTICAL ou HORIZONTAL
         */
        ALLIGNEMENT GetAllignement();
        
        /**
         * 
         * @return le nom du bateau, NoName par defaut
         */
        string GetName();
        
    protected:

    private:
        ALLIGNEMENT alignement;
        int x;
        int y;
        int taille;
        ETAT_BATEAU etat;
        string name;
        vector<BateauCase*> listeBateauCase; //liste des cases que contient le bateau
};

#endif // BATEAU_H
