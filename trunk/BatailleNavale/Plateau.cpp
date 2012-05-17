#include "Plateau.h"

#include <string>

using namespace std;

/**
 * 
 * @param tailleX : taille du plateau en X
 * @param tailleY : taille du plateau en Y
 */
Plateau::Plateau(int tailleX, int tailleY) {
    this->tailleY = tailleY;
    this->tailleX = tailleX;
    //init la grille avec des bateaucasevide.
    this->plateau = new BateauCase** [tailleX];
    for(int x=0; x<tailleX; x++){
        this->plateau[x] = new BateauCase*[tailleY];
        for(int y=0; y<tailleY; y++){
            this->plateau[x][y] = new BateauCaseVide(x,y);
        }
    }
}

/**
 * 
 * @param x
 * @param y
 * @return the bateau case from the bateau case
 */
BateauCase* Plateau::GetBateauCase(int x, int y){
    return this->plateau[x][y];
}


bool Plateau::SetBateau(int taille, int x, int y, ALLIGNEMENT_BATEAU a){
    if(a == HORIZONTAL){
        if(y + taille < this->tailleY){
            Bateau* btmp = new Bateau(x,y,a, taille);
//TODO:ADD check if we add a boat on another boat
//            for(int ytmp = y; ytmp < y + taille; ytmp++){
//                
//                if(bateauCase = (dynamic_cast<BateauCasePleine*>(theBC))){
//                    return bateauCase->GetBateau();
//                    }
//              
//            }
            for(int ytmp = y; ytmp < y + taille; ytmp++){
                free(this->plateau[x][ytmp]);
                this->plateau[x][ytmp] = btmp->AddBateauCase(x,ytmp); 
            }
            return true;
        }
    }else if(a == VERTICAL){
        if(x + taille < this->tailleX){
            Bateau* btmp = new Bateau(x,y,a, taille);
//TODO:ADD check if we add a boat on another boat
            for(int xtmp = x; xtmp < x + taille; xtmp++){
                free(this->plateau[xtmp][y]);
                this->plateau[xtmp][y] = btmp->AddBateauCase(xtmp,y); 
            }
            return true;
        }
    }
    return false;
}
/**
 * 
 * @param x : position en X du bateau
 * @param y : position en Y du bateau
 * @return : le bateau qui contient le bateaucase correspondant a la case X,Y
 */
Bateau* Plateau::GetBateau(int x, int y){
    BateauCasePleine* bateauCase;
    BateauCase* theBC = this->plateau[x][y];
   
    if(bateauCase = (dynamic_cast<BateauCasePleine*>(theBC))){
       return bateauCase->GetBateau();
    }
    return NULL;
}

/**
 * 
 * @return taille du plateau en X
 */
int Plateau::GetTailleX(){
    return this->tailleX;
}

/**
 * 
 * @return taille du plateau en Y
 */
int Plateau::GetTailleY(){
    return this->tailleY;
}

string** Plateau::GetPlateauAdversaire(){
    Plateau* p = this;
    if(p != NULL){
        int taillex = p->GetTailleX();
        int tailley = p->GetTailleY();
        string** rpr = new string* [tailleX];
        for(int x=0; x<taillex; x++){
            rpr[x] = new string [tailleY];
        }
        for(int x=0; x<taillex; x++){
            for(int y=0; y<tailley; y++){
                BateauCase *b = p->GetBateauCase(x,y);
                rpr[x][y] = b->GetRepresentationAdversaire();
            }
        }
        return rpr;
    }
    return NULL;
}

string** Plateau::GetPlateauJoueur(){
    Plateau* p = this;
    if(p != NULL){
        int taillex = p->GetTailleX();
        int tailley = p->GetTailleY();
        string** rpr = new string* [tailleX];
        for(int x=0; x<taillex; x++){
            rpr[x] = new string [tailleY];
        }
        for(int x=0; x<taillex; x++){
            for(int y=0; y<tailley; y++){
                BateauCase *b = p->GetBateauCase(x,y);
                rpr[x][y] = b->GetRepresentation();
            }
        }
        return rpr;
    }
    return NULL;
}
