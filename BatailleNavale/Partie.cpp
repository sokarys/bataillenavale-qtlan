#include "Partie.h"
#include <iostream>
using namespace std;
/**
 * Constructeur
 */
Partie::Partie(int tailleX, int tailleY, int* nombreTailleBateau, int tailleBateauMax)
{
    this->tailleX = tailleX;
    this->tailleY = tailleY;
    this->joueurCourantAjoue = false;
    this->tailleBateauMax = tailleBateauMax;
    if(nombreTailleBateau == NULL){
        this->tailleBateauMax = 5;
        this->nombreTailleBateau = new int[6];
        this->nombreTailleBateau[0] = 0;
        this->nombreTailleBateau[1] = 0;
        this->nombreTailleBateau[2] = 1;
        this->nombreTailleBateau[3] = 2;
        this->nombreTailleBateau[4] = 1;
        this->nombreTailleBateau[5] = 1;
    }else{
        this->nombreTailleBateau = nombreTailleBateau;
    }
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
bool Partie::AddJoueur(Joueur* joueur){

    if(this->listeJoueur.size() >= MAX_JOUEUR){
        return false;
    }
    Plateau* plateau = new Plateau(this->tailleX, this->tailleY, this->nombreTailleBateau, this->tailleBateauMax);
    JoueurPlateau* jp = new JoueurPlateau(joueur,plateau);
    this->joueurCourant = jp;
    this->listeJoueur.push_back(jp);
    return true;
    
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
 * Crés les plateaux, met l'état des joueurs en partie, mise en place des bonus..
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
            this->joueurCourantAjoue = false;
            break;
        }
        ++it;
    }
}
/**
 * Permet au joueur courant de jouer une case
 * @param x
 * @param y
 * @return bool : return true si le joueur joue dans une case valide
 */
bool Partie::JoueurCourantJoue(int x, int y){
    bool joue = this->GetAdversaire(this->GetJoueurCourant())->GetPlateau()->JouerBateauCase(x,y);
    this->joueurCourantAjoue = joue;
    return joue;
    
}
/**
 * Permet de renvoyer un tab de string pour le joueur j
 * @param j
 * @return 
 */
string** Partie::JoueurPlateauPlacementBateau(JoueurPlateau* j){
    if(j == NULL){
        return NULL;
    }
    return j->GetPlateau()->GetPlateauBateauJoueur();
}
/**
 * Permet de renvoyer un tab de string pour le joueur j
 * @param j
 * @return 
 */
string** Partie::JoueurPlateauAdversaire(JoueurPlateau* j){
    if(j == NULL){
        return NULL;
    }
    return j->GetPlateau()->GetPlateauAdversaire();
}
/**
 * Permet de renvoyer un tab de string pour le joueur j 
 * @param j
 * @return 
 */
string** Partie::JoueurPlateauJoue(JoueurPlateau* j){
    if(j == NULL){
        return NULL;
    }
#if DEBUG
    cout << j->GetJoueur()->GetName() << endl;
    cout << this->GetAdversaire(j)->GetJoueur()->GetName() << endl;
#endif
    return this->GetAdversaire(j)->GetPlateau()->GetPlateauAdversaire();
}
/**
 * permet de connaitre le joueur gagnant
 * @return le joueur gagnant, Null si il y en a pas
 */
Joueur* Partie::GetGagnant(){
#if DEBUG
    cout << "PARTIE LANCEE" << this->partieLance << endl;
#endif
    if(!this->partieLance){
        return NULL;
    }
    vector<JoueurPlateau*>::iterator it;
    it = this->listeJoueur.begin();
    while(it != this->listeJoueur.end()){
        JoueurPlateau* jp = *it;
#if DEBUG
        cout << "bateau coule : "<<jp->GetJoueur()->GetName() << " " << jp->GetPlateau()->IsAllBateauCoule() << endl;
#endif
        if(jp->GetPlateau()->IsAllBateauCoule()){
            return this->GetAdversaire(jp)->GetJoueur();
        }
        ++it;
    }
    return NULL;
}

int Partie::GetNbJoueurs(){
    return this->listeJoueur.size();
}

JoueurPlateau* Partie::GetAdversaire_JoueurCourant(){
    vector<JoueurPlateau*>::iterator it;
    it = this->listeJoueur.begin();
    while(it != this->listeJoueur.end()){
        JoueurPlateau* jp = *it;
        if(! jp->IsJoueurEqals(this->joueurCourant->GetJoueur())){
            return jp;
        }
        ++it;
    }
    return NULL;
}

JoueurPlateau* Partie::GetAdversaire(JoueurPlateau* joueurplateau){
    vector<JoueurPlateau*>::iterator it;
    it = this->listeJoueur.begin();
    while(it != this->listeJoueur.end()){
        JoueurPlateau* jp = *it;
        if(! jp->IsJoueurEqals(joueurplateau->GetJoueur())){
            return jp;
        }
        ++it;
    }
    return NULL;
}

int Partie::GetTaillePlateauX(){
    return this->tailleX;
}

int Partie::GetTaillePlateauY(){
    return this->tailleY;
}

JoueurPlateau* Partie::GetJoueurCourant(){
    return this->joueurCourant;
}

bool Partie::IsPartieLancee(){
    return this->partieLance;
}

bool Partie::IsJoueurCourantAJoue(){
    return this->joueurCourantAjoue;
}

bool Partie::LancerPartie(){
    vector<JoueurPlateau*>::iterator it;
    it = this->listeJoueur.begin();
    while(it != this->listeJoueur.end()){
        JoueurPlateau* jp = *it;
        if(!jp->IsTousLesBateauxPlaces()){
            return false;
        }
        ++it;
    }
    this->partieLance = true;
    return true;
}

int Partie::GetTailleBateauMax(){
    return this->tailleBateauMax;
}

