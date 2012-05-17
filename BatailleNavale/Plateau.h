#ifndef PLATEAU_H
#define PLATEAU_H

#include "BateauCaseVide.h"
#include "BateauCasePleine.h"
#include "BateauCase.h"
#include "Bateau.h"

#include <typeinfo>
#include <vector>

#define GRILLE_X 7
#define GRILLE_Y 7
#define NB_BATEAU 5

using namespace std;

class Plateau
{
    public:
        /*Constructeur*/
        Plateau(int tailleX, int tailleY);

        /*permet de placer un bateau sur le plateau en x,y, avec le bon allignement,
         *  si rajout d'un bateau dell le bateaucasevide avant pour eviter les fuite memoire*/
        bool SetBateau(int taille, int x, int y, ALLIGNEMENT_BATEAU a);
        /*renvoie le bateau situee en x,y*/
        Bateau* GetBateau(int x, int y);
        /*renvoi le bateaucase en x, y, NULL sinon*/
        BateauCase* GetBateauCase(int x, int y); 
        /**/
        string** GetPlateauAdversaire();
        string** GetPlateauJoueur();

        /*Getter and Setter*/
        vector<Bateau*> GetListeBateau();
        int GetTailleX();
        int GetTailleY();

    private:
        
        //BateauCase* plateau[GRILLE_X][GRILLE_Y];
        BateauCase*** plateau;
        int tailleY;
        int tailleX;
        vector<Bateau*> listeBateau;
};

#endif // PLATEAU_H