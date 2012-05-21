/* 
 * File:   InterfaceConsole.cpp
 * Author: Olivier
 * 
 * Created on 21 mai 2012, 13:10
 */

#include "InterfaceConsole.h"

InterfaceConsole::InterfaceConsole(Controller* controller) : Interface(controller) {
}


InterfaceConsole::~InterfaceConsole() {
}

void InterfaceConsole::Run(){
    Joueur* j1 = new Joueur("Soka","O_o");
    Joueur* j2 = new Joueur("Jessy","-_-");
    cout << "Soka ajouter a la partie : " << this->controller->AddJoueur(j1) << endl;
    cout << "Jessy ajouter a la partie : " << this->controller->AddJoueur(j2) << endl;
    this->controller->InitPartie();
    cout << "Init de la partie" << endl;
    while(this->ChoixMenu()){
        
    }
    
}

void InterfaceConsole::Afficher_PlateauJoueur_JoueurCourant(){
    string** theStringTmp = this->controller->GetPlateauJoueur_JoueurCourant();
    int tailleX = this->controller->GetTaillePlateauX();
    int tailleY = this->controller->GetTaillePlateauY();
    this->AfficherConsole(theStringTmp, tailleX, tailleY );
}

void InterfaceConsole::Afficher_PlateauAdversaire_JoueurCourant(){
    string** theStringTmp = this->controller->GetPlateauAdversaire_JoueurCourant();
    int tailleX = this->controller->GetTaillePlateauX();
    int tailleY = this->controller->GetTaillePlateauY();
    this->AfficherConsole(theStringTmp, tailleX, tailleY );
}

void InterfaceConsole::Afficher_PlateauPositionBateau_JoueurCourant(){
    string** theStringTmp = this->controller->GetPlateauPositionBateau_JoueurCourant();
    int tailleX = this->controller->GetTaillePlateauX();
    int tailleY = this->controller->GetTaillePlateauY();
    this->AfficherConsole(theStringTmp, tailleX, tailleY );
}

void InterfaceConsole::AfficherConsole(string** str, int taillex, int tailley){
    cout << taillex << endl << tailley  << endl << "XXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    if(str != NULL){
        for(int x=0; x<taillex; x++){
            for(int y=0; y<tailley; y++){
                cout << str[x][y] << ".";
            }
            cout << endl;
        }
    }
}

void InterfaceConsole::AfficherMenu(){
    cout << "MENU" << endl;
    cout << "1  - " << "Afficher_PlateauJoueur_JoueurCourant" << endl;
    cout << "2  - " << "Afficher_PlateauAdversaire_JoueurCourant" << endl;
    cout << "3  - " << "Afficher_PlateauPositionBateau_JoueurCourant" << endl;
    cout << "---------------------------------" << endl;
    cout << "4  - " << "Jouer" << endl;
    if(!this->controller->IsPartieLancee()){
        cout << "5  - " << "Placer Bateau" << endl;
    }
    if(this->controller->IsTousBateauxPlace_JoueurCourant() && !this->controller->IsPartieLancee()){
        cout << "---------------------------------" << endl;
        cout << "6  - " << "Joueur Suivant" << endl;
    }else if(this->controller->IsJoueurCourantAJoue() && this->controller->IsPartieLancee()){
        cout << "---------------------------------" << endl;
        cout << "6  - " << "Joueur Suivant" << endl;
    }
    cout << "---------------------------------" << endl;
    cout << "9  - " << "Quitter" << endl;
    cout << "---------------------------------" << endl << endl;
    
}

bool InterfaceConsole::ChoixMenu(){
    this->AfficherMenu();
    int choix = 0;
    int x=0,y=0, al=0, taille;
    ALLIGNEMENT align;
    cin >> choix;
    cin.clear();
    switch(choix){
        case 1:
            this->Afficher_PlateauJoueur_JoueurCourant();
            break;
        case 2:
            this->Afficher_PlateauAdversaire_JoueurCourant();
            break;
        case 3:
            this->Afficher_PlateauPositionBateau_JoueurCourant();
            break;
        case 4:
            cout << "Position X : ";
            cin >> x;
            cin.clear();
            cout << "Position Y : ";
            cin >> y;
            cin.clear();
            //TODO: Check lign colone
            this->controller->Jouer_JoueurCourant(x,y);
            break;
        case 5:
//            cout << "Taille : ";
//            cin >> taille;
//            cin.clear();
            taille = this->controller->GetTaillePlacementBateauSuivant_JoueurCourant();
            if(taille <= 0){
                cout << "Plus de bateau a placer";
                break;
            }else{
                cout << "Bateau de taille " << taille << " a placer" << endl;
            }
            cout << "Position X : ";
            cin >> x;
            cin.clear();
            cout << "Position Y : ";
            cin >> y;
            cin.clear();
            cout << "Allig (-- : 0)( | : 1) : ";
            cin >> al;
            cin.clear();
            align = (al == 0 ? HORIZONTAL : VERTICAL);
            cout << x << " " << y << al;
            bool b = this->controller->PoserBateau_JoueurCourant(taille,x,y,align);
            if(b){
                cout << "Succes : Votre bateau a ete ajoute avec succes" << endl;
            }else{
                cout << "Error : Votre bateau n'a pas ete ajoute" << endl;
            }
            break;
        case 6:
            if(this->controller->IsTousBateauxPlace_JoueurCourant() && !this->controller->IsPartieLancee()){
                this->controller->JoueurSuivant();
            }
            if(this->controller->IsJoueurCourantAJoue() && this->controller->IsPartieLancee()){
                this->controller->JoueurSuivant();
            }
            break;
        case 9:
            return false;
        default:
            if (cin.fail()) 
            {
                cout << "\ncin failed - substituting: i=1;\n\n";
                choix = 0;
            }
            cin.clear(); cin.ignore(INT_MAX,'\n'); 
            this->AfficherMenu();
            break;
    };
    cin.clear();
    return true;
}
