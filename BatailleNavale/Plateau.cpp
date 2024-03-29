#include "Plateau.h"
//#include "BateauCaseBonus.h"


using namespace std;

/**
 * 
 * @param tailleX : taille du plateau en X
 * @param tailleY : taille du plateau en Y
 */
Plateau::Plateau(int tailleX, int tailleY,int* TailleBateau, int tailleBateauMax) {
    this->tailleY = tailleY;
    this->tailleX = tailleX;
    this->controlPlacementBateau = new ControlPlacementBateau(TailleBateau,tailleBateauMax);
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


bool Plateau::SetBateau(int taille, int x, int y, ALLIGNEMENT a){
    if(taille <=0){
        return false;
    }
    if(a == HORIZONTAL){
        if(y + taille < this->tailleY){
            Bateau* btmp = new Bateau(x,y,a, taille);
            if(! CheckSetBateau(btmp)){
                return false;
            }
            for(int ytmp = y; ytmp < y + taille; ytmp++){
                delete this->plateau[x][ytmp];
                this->plateau[x][ytmp] = btmp->AddBateauCase(x,ytmp); 
            }
            this->controlPlacementBateau->AddBateauPlace(btmp);
            this->listeBateau.push_back(btmp);
            return true;
        }
    }else if(a == VERTICAL){
        if(x + taille < this->tailleX){
            Bateau* btmp = new Bateau(x,y,a, taille);
            if(! CheckSetBateau(btmp)){
                return false;
            }
            for(int xtmp = x; xtmp < x + taille; xtmp++){
                delete this->plateau[xtmp][y];
                this->plateau[xtmp][y] = btmp->AddBateauCase(xtmp,y); 
            }
            this->controlPlacementBateau->AddBateauPlace(btmp);
            this->listeBateau.push_back(btmp);
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

bool Plateau::IsAllBateauCoule(){
    if(this->listeBateau.size()==0){
         return false;
     }
    for(int unsigned i=0; i<this->listeBateau.size(); i++){
        if(this->listeBateau[i]->GetEtat() == PAS_COULE){
            return false;
        }
    }
    return true;
}
/**
 * 
 * @return taille du plateau en Y
 */
int Plateau::GetTailleY(){
    return this->tailleY;
}
/**
 * permet de recuperer un tab de string montrant les cases jouées par l'adversaire.
 * @return 
 */
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

/**
 * Permet de recupérer une représentation du plateau des bateaux du joueur
 * @return tableau de string
 */
string** Plateau::GetPlateauBateauJoueur(){
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

/**
 * Permet de joueur la case X, y. cette fonction doit etre utilisé par l'adversaire.
 * @param x
 * @param y
 */
bool Plateau::JouerBateauCase(int x, int y, BonusManager* bonusManager){
    BateauCasePleine* bateauCase;
    BateauCaseVide* bateauCaseV;
    BateauCaseBonus* bateauCaseBonus;
    if(x<0 || y<0 || x>=this->GetTailleX() || y>=this->GetTailleY()){
        return false;
    }
    BateauCase* theBC = this->plateau[x][y];
    if(theBC->GetEtat() != PAS_JOUEE){
        return false;
    }
    if(bateauCase = (dynamic_cast<BateauCasePleine*>(theBC))){
       bateauCase->SetEtat(TOUCHE);
    }else if(bateauCaseV = (dynamic_cast<BateauCaseVide*>(theBC))){
       bateauCaseV->SetEtat(EAU);
    }else if(bateauCaseBonus = (dynamic_cast<BateauCaseBonus*>(theBC))){
       bateauCaseBonus->SetEtat(EAU);
       if(bonusManager != NULL){
           bonusManager->AddBonus(bateauCaseBonus->GetBonus());
       }
    }
    return true;
}

bool Plateau::IsBateauCasePleine(int x, int y){
    BateauCasePleine* bateauCase;
    BateauCase* theBC = this->plateau[x][y];
    if(bateauCase = (dynamic_cast<BateauCasePleine*>(theBC))){
        return true;
    }
    return false;
}
/**
 * Permet de verfier si le bateau va etre créer au bonne endroit
 * @param b
 * @return true if the boat is well place, false else.
 */
bool Plateau::CheckSetBateau(Bateau* b){
    
    int x = b->GetX();
    int y = b->GetY();
    int taille = b->GetTaille();
    ALLIGNEMENT align = b->GetAllignement();
    if(x<0 || x>this->GetTailleX() || y<0 || y>this->GetTailleY()){
        return false;
    }
    if(align == VERTICAL){
        if(x + taille >= this->GetTailleX()){
            return false;
        }
        for(int xtmp = x; xtmp < x + taille; xtmp++){
            if(this->IsBateauCasePleine(xtmp,y)){
                return false;
            }
        }
    }else{
        if(y + taille >= this->GetTailleY()){
            return false;
        }
        for(int ytmp = y; ytmp < y + taille; ytmp++){
            if(this->IsBateauCasePleine(x,ytmp)){
                return false;
            }
        }
    }
    
    return true;
}

bool Plateau::IsTousBateauxPlace(){
    return this->controlPlacementBateau->TousLesBateauxPlace();
}

int Plateau::GetTaillePlacementBateauSuivant(){
    return this->controlPlacementBateau->GetTaillePlacementBateauSuivant();
}

int* Plateau::GetBateauRestanAPlacer(){
    return this->controlPlacementBateau->GetBateauRestanAPlacer();
}
