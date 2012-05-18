#include "Partie.h"

using namespace std;
/**
 * Constructeur
 */
Partie::Partie(int tailleX, int tailleY)
{
    this->tailleX = tailleX;
    this->tailleY = tailleY;
}
/**
 * Destructeur
 */
Partie::~Partie()
{
}
/**
 * Rajoute un joueur à la partie
 * @param joueur
 */
void Partie::AddJoueur(Joueur* joueur){

    if(this->listeJoueur.size() >= MAX_JOUEUR){
        return;
    }
    Plateau* plateau = new Plateau(this->tailleX, this->tailleY);
    JoueurPlateau* jp = new JoueurPlateau(joueur,plateau);
    this->listeJoueur.push_back(jp);
    
}
/**
 * Supprime un joueur de la partie
 * @param joueur
 */
void Partie::DelJoueur(Joueur* joueur){
    vector<JoueurPlateau*>::iterator it;
    it = this->listeJoueur.begin();
    while(it != this->listeJoueur.end()){
        JoueurPlateau* jp = *it;
        if(jp->IsJoueurEqals(joueur)){
            this->listeJoueur.erase(it);
            break;
        }
        ++it;
    }
}
/**
 * Initialise la partie :
 * Crés les plateaux, met l'état des joueurs en partie, etc..
 */
void Partie::InitPartie(){
    
}
/**
 * Permet de passer au joueur suivant, change le joueur courant
 */
void Partie::JoueurSuivant(){
     vector<JoueurPlateau*>::iterator it;
    it = this->listeJoueur.begin();
    while(it != this->listeJoueur.end()){
        JoueurPlateau* jp = *it;
        if(! jp->IsJoueurEqals(this->joueurCourant->GetJoueur())){
            this->joueurCourant = jp;
            break;
        }
        ++it;
    }
}
/**
 * Permet au joueur courant de jouer une case
 * @param x
 * @param y
 */
void Partie::JoueurCourantJoue(int x, int y){
    
}
/**
 * Permet de renvoyer un tab de string pour le joueur j
 * @param j
 * @return 
 */
string** Partie::JoueurPlateauPlacementBateau(Joueur* j){

}
/**
 * Permet de renvoyer un tab de string pour le joueur j
 * @param j
 * @return 
 */
string** Partie::JoueurPlateauAdversaire(Joueur* j){
    
}
/**
 * Permet de renvoyer un tab de string pour le joueur j 
 * @param j
 * @return 
 */
string** Partie::JoueurPlateauJoue(Joueur* j){
    
}
/**
 * permet de connaitre le joueur gagnant
 * @return le joueur gagnant, Null si il y en a pas
 */
Joueur* Partie::GetGagnant(){
    
}

