#include "Bateau.h"
#include "BateauCasePleine.h"

using namespace std;

/** @brief GetY
  *
  * return the y of the bateau
  */
int Bateau::GetY()
{
    return this->y;
}

/** @brief GetX
  *
  * return the x of the boat
  */
int Bateau::GetX()
{
    return this->x;
}

/** @brief GetEtat
  *
  * return the etat of the boat : coule or not coule
  */
ETAT_BATEAU Bateau::GetEtat()
{
    return this->etat;
}

void Bateau::SetEtat(ETAT_BATEAU etat){
    this->etat = etat;
    if(etat == COULE){
        for(int unsigned i=0;i<this->listeBateauCase.size();i++){
         this->listeBateauCase[i]->SetEtat(COULE_BC);
     } 
    }
}

/** @brief GetBateauCase
  *
  * return the BateauCase which is in x, y. NULL else
  */
BateauCase* Bateau::GetBateauCase(int x, int y)
{
    return NULL;
}

/** @brief AddBateauCase
  *
  * create and add a new bateaucase to this boat.
  */
BateauCase* Bateau::AddBateauCase(int x, int y)
{      
    if((int)this->listeBateauCase.size() >= this->taille){
        return NULL;
    }
    BateauCasePleine* bc = new BateauCasePleine(x, y, this);
    this->listeBateauCase.push_back(bc);
    return bc;
}

/** @brief Bateau
  *
  * construcutor
  */
 Bateau::Bateau(int x, int y, ALLIGNEMENT_BATEAU align, int taille, string name)
{
    this->x = x;
    this->y = y;
    this->etat = PAS_COULE;
    this->alignement = align;
    this->taille = taille;
    this->listeBateauCase = vector<BateauCase*>();
    this->name = name;
}
 int Bateau::GetTaille(){
     return this->taille;
 }
 /**
  * Destructor
  */
 Bateau::~Bateau(){
     
 }
 /**
  * 
  * @return 
  */
 string Bateau::GetName(){
     return this->name;
 }
 
 /**
  * 
  */
 void Bateau::CheckEtat(){
     
     for(int unsigned i=0;i<this->listeBateauCase.size();i++){
         if(this->listeBateauCase[i]->GetEtat() == PAS_JOUEE){
             return;
         }
     } 
     this->SetEtat(COULE);
 }
