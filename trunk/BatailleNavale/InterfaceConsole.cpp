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
        Joueur* winner = this->controller->JoueurGagne();
        if(winner != NULL){
            winner->GetHistorique()->AddVictoire();
            //TODO:Add loose to looser
            cout << "Le joueur gagnant est " << winner->GetName();
            break;
        }
    }
    
}

void InterfaceConsole::Afficher_PlateauJoueur_JoueurCourant(){
    string** theStringTmp = this->controller->GetPlateauJoueur_JoueurCourant();
    int tailleX = this->controller->GetTaillePlateauX();
    int tailleY = this->controller->GetTaillePlateauY();
    this->AfficherConsole(theStringTmp, tailleX, tailleY );
    for(int i=0 ; i < this->controller->GetTaillePlateauX() ; i++){
        delete[] theStringTmp[i];   
    }
    delete[] theStringTmp;
}

void InterfaceConsole::Afficher_PlateauAdversaire_JoueurCourant(){
    string** theStringTmp = this->controller->GetPlateauAdversaire_JoueurCourant();
    int tailleX = this->controller->GetTaillePlateauX();
    int tailleY = this->controller->GetTaillePlateauY();
    this->AfficherConsole(theStringTmp, tailleX, tailleY );
    for(int i=0 ; i < this->controller->GetTaillePlateauX() ; i++){
        delete[] theStringTmp[i];   
    }
    delete[] theStringTmp;
}

void InterfaceConsole::Afficher_PlateauPositionBateau_JoueurCourant(){
    string** theStringTmp = this->controller->GetPlateauPositionBateau_JoueurCourant();
    int tailleX = this->controller->GetTaillePlateauX();
    int tailleY = this->controller->GetTaillePlateauY();
    this->AfficherConsole(theStringTmp, tailleX, tailleY );
    for(int i=0 ; i < this->controller->GetTaillePlateauX() ; i++){
        delete[] theStringTmp[i];   
    }
    delete[] theStringTmp;
}

void InterfaceConsole::AfficherConsole(string** str, int taillex, int tailley){
    if(str != NULL){
        cout << "X\\Y\t" ;
        for(int y=0; y<tailley; y++){
            cout << y << REP_SEPARATION;
        }
        cout << endl;
        for(int x=0; x<taillex; x++){
            cout << x << '\t';
            for(int y=0; y<tailley; y++){
                cout << str[x][y] << REP_SEPARATION;
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
    cout << "0  - " << "Aficher tous les plateaux" << endl;
    cout << "---------------------------------" << endl;
    if(!this->controller->IsJoueurCourantAJoue() && this->controller->IsPartieLancee()){
        cout << "4  - " << "Jouer" << endl;
    }
    if(!this->controller->IsPartieLancee() && !this->controller->IsTousBateauxPlace_JoueurCourant()){
        cout << "5  - " << "Voir Bateau restant a placer" << endl;
        cout << "6  - " << "Placer Bateau" << endl;
    }
    if(this->controller->IsTousBateauxPlace_JoueurCourant() && !this->controller->IsPartieLancee()){
        cout << "---------------------------------" << endl;
        cout << "7  - " << "Joueur Suivant" << endl;
    }else if(this->controller->IsJoueurCourantAJoue() && this->controller->IsPartieLancee()){
        cout << "---------------------------------" << endl;
        cout << "7  - " << "Joueur Suivant" << endl;
    }
    if(!this->controller->IsPartieLancee()){
        cout << "8  - " << "Lancer Partie" << endl;
    }
    cout << "---------------------------------" << endl;
    cout << "9  - " << "Quitter" << endl;
    cout << "---------------------------------" << endl << endl;
    
}

void InterfaceConsole::AfficherTout(){
    string** platJ = this->controller->GetPlateauJoueur_JoueurCourant();
    string** postBJ = this->controller->GetPlateauPositionBateau_JoueurCourant();
    string** advJ = this->controller->GetPlateauAdversaire_JoueurCourant();
    cout << "X\\Y\t";
    for(int y=0; y<this->controller->GetTaillePlateauY(); y++){
        cout << y << " " ;
    }
    cout << "\t";
    for(int y=0; y<this->controller->GetTaillePlateauY(); y++){
        cout << y << " " ;
    }
    cout << "\t";
    for(int y=0; y<this->controller->GetTaillePlateauY(); y++){
        cout << y << " " ;
    }
    cout << " " << endl;
    for(int x=0; x<this->controller->GetTaillePlateauX(); x++){
        cout << x << "\t";
        for(int y=0; y<this->controller->GetTaillePlateauY(); y++){
            cout << platJ[x][y] << REP_SEPARATION;
        }
        cout << "\t";
        for(int y=0; y<this->controller->GetTaillePlateauY(); y++){
            cout << postBJ[x][y] << REP_SEPARATION;    
        }
        cout << "\t";
        for(int y=0; y<this->controller->GetTaillePlateauY(); y++){
            cout << advJ[x][y] << REP_SEPARATION;    
        }
        cout << "\n";
    }
    for(int i=0 ; i < this->controller->GetTaillePlateauX() ; i++){
        delete[] platJ[i];    
        delete[] postBJ[i];
        delete[] advJ[i];
    }
        
    delete[] platJ;
    delete[] postBJ;
    delete[] advJ;
}

bool InterfaceConsole::ChoixMenu(){
    this->AfficherMenu();
    int choix = 0;
    int x=0,y=0, al=0, taille;
    bool b;
    int* bateauRestant;
    int tailleMax;
    ALLIGNEMENT align;
    cin >> choix;
    cin.clear();
    this->Clear_screen();
    switch(choix){
        case 0:
            this->AfficherTout();
            break;
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
            if(!this->controller->IsTousBateauxPlace_JoueurCourant() && !this->controller->IsPartieLancee()){
                bateauRestant = this->controller->GetJoueurCourant()->GetPlateau()->GetBateauRestanAPlacer();
                tailleMax = this->controller->GetTailleBateauMax();
                for(int i=0; i<=tailleMax; i++){
                    if(bateauRestant[i]>0){
                        cout << bateauRestant[i] << " bateau(x)" << " de taille " << i << endl;
                    }
                }
            }else if(!this->controller->IsPartieLancee()){
                cout << "Tous les bateaux sont places" << endl;
            }
            break;
        case 6:
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
            cout << "Position X (|) : ";
            cin >> x;
            cin.clear(); 
            cout << "Position Y (--): ";
            cin >> y;
            cin.clear();
            cout << "Align (-- : 0)( | : 1) : ";
            cin >> al;
            cin.clear();
            align = (al == 0 ? HORIZONTAL : VERTICAL);
            cout << x << " " << y << al;
            b = this->controller->PoserBateau_JoueurCourant(taille,x,y,align);
            if(b){
                cout << "Succes : Votre bateau a ete ajoute avec succes" << endl;
            }else{
                cout << "Error : Votre bateau n'a pas ete ajoute" << endl;
            }
            break;
        case 7:
            if(this->controller->IsTousBateauxPlace_JoueurCourant() && !this->controller->IsPartieLancee()){
                this->JoueurSuivant();
            }
            if(this->controller->IsJoueurCourantAJoue() && this->controller->IsPartieLancee()){
                this->JoueurSuivant();
            }
            break;
        case 8:
            if(this->controller->LancerPartie()){
                cout << "C est a " << this->controller->GetJoueurCourant()->GetJoueur()->GetName() << " de jouer" << endl;
                cout << "Partie lancee" << endl;
            }else{
                cout << "il faut placer tous les bateaux" << endl;
            }
            break;
        case 9:
            return false;
        default:
            this->AfficherMenu();
            break;
    };
    cin.clear(); cin.ignore(INT_MAX,'\n');
    return true;
}

void InterfaceConsole::JoueurSuivant(){
    Interface::JoueurSuivant();
    cout << "C est a " << this->controller->GetJoueurCourant()->GetJoueur()->GetName() << " de jouer" << endl;
}

void InterfaceConsole::Clear_screen(){
#ifdef __unix__ 
  system("clear");
#else
  cout << "\033[H\033[2J";
#endif
}

