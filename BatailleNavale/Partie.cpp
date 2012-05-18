#include "Partie.h"

using namespace std;
/**
 * Constructeur
 */
Partie::Partie()
{
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
void Partie::AddJoueur(Joueur& joueur){

    if(this->listeJoueur.size() >= MAX_JOUEUR){
        return;
    }
    //this->listeJoueur.push_back(joueur);
}
/**
 * Supprime un joueur de la partie
 * @param joueur
 */
void Partie::DelJoueur(Joueur* joueur){
    
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

