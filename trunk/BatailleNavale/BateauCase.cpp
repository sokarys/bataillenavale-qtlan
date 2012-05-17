#include "BateauCase.h"

using namespace std;
/**
*Constructeur
*/
BateauCase::BateauCase(int x, int y)
{
    this->x = x;
    this->y = y;
    this->etat = PAS_JOUEE;
}

string BateauCase::GetRepresentation(){
    return "P";
}

string BateauCase::GetRepresentationAdversaire(){
    if(this->GetEtat() == PAS_JOUEE){
        return "_";
    }else if(this->GetEtat() == TOUCHE){
        return "T";
    }else if(this->GetEtat() == COULE_BC){
        return "C";
    }
    return "E";
}

/** @brief GetEtat
  *
  * return the etat of the bateaucase touche or not
  */
ETAT_BATEAUCASE BateauCase::GetEtat()
{
    return this->etat;
}

/** @brief GetY
  *
  * return the y of the bateaucase
  */
int BateauCase::GetY()
{
    return this->y;
}

/** @brief GetX
  *
  *return the x of the bateaucase
  */
int BateauCase::GetX()
{
    return this->x;
}

/** @brief SetEtat
  *
  * the the etat in the bateaucase
  */
void BateauCase::SetEtat(ETAT_BATEAUCASE etat)
{
    this->etat = etat;
}

/** @brief SetY
  *
  * Set the value y to the bateaucase
  */
void BateauCase::SetY(int y)
{
    this->y = y;
}

/** @brief SetX
  *
  * Set th value x
  */
void BateauCase::SetX(int x)
{
    this->x = x;
}

/**
 * 
 * @param out 
 * @param b
 * @return surcharge de l'operateur '<<'
 * qui permet d'afficher un objet sur le stream
 */
ostream& operator<< (ostream& out, BateauCase& b){
    out << b.GetRepresentation();
    return out;
}
