#ifndef PLATEAU_H
#define PLATEAU_H

//#include "Bonus.h"
#include "Variable.h"
#include "Bateau.h"
#include "BateauCase.h"
#include "BateauCaseVide.h"
#include "BateauCasePleine.h"
#include "ControlPlacementBateau.h"


#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

#define GRILLE_X 7
#define GRILLE_Y 7
#define NB_BATEAU 5

using namespace std;

class Plateau
{
    public:
        /*Constructeur*/
        Plateau(int tailleX, int tailleY, int* TailleBateau, int tailleBateauMax=MAX_TAILLE_BATEAU);
//        virtual ~Plateau(){};

        /*permet de placer un bateau sur le plateau en x,y, avec le bon allignement,
         *  si rajout d'un bateau dell le bateaucasevide avant pour eviter les fuite memoire*/
        bool SetBateau(int taille, int x, int y, ALLIGNEMENT a);
        
        /*renvoie le bateau situee en x,y*/
        Bateau* GetBateau(int x, int y);
        
        /*renvoi le bateaucase en x, y, NULL sinon*/
        BateauCase* GetBateauCase(int x, int y); 
        
        /*retourn un tableau de string representant le plateau vu pour l'adversaire*/
        string** GetPlateauAdversaire();
        
        /*retourn un tableau de string representant le plateau des bateau que le joueur a pose*/
        string** GetPlateauBateauJoueur();
        
        /*Permet de jouer sur la case x,y*/
        bool JouerBateauCase(int x, int y);
        
        bool IsBateauCasePleine(int x, int y);
        
        /*renvoie true si tous les bateaux du plateau sont coule*/
        bool IsAllBateauCoule();

        /*Getter and Setter*/
        vector<Bateau*> GetListeBateau();
        
        int GetTaillePlacementBateauSuivant();
        
        int GetTailleX();
        int GetTailleY();
        
        bool IsTousBateauxPlace();
        
        int* GetBateauRestanAPlacer();
        
    protected:
        bool CheckSetBateau(Bateau* b);
        
    private:
        
        BateauCase*** plateau;
        int tailleY;
        int tailleX;
        vector<Bateau*> listeBateau;
        ControlPlacementBateau* controlPlacementBateau;
};

#endif // PLATEAU_H
