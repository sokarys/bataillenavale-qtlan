#include "Joueur.h"

using namespace std;

Joueur::Joueur(string name, string password, Historique* historique)
{
    this->name = name;
    this->password = password;
    if(historique==NULL){
        this->historique = new Historique();
    }else{
        this->historique = historique;
    }
}

Joueur::~Joueur(){}

bool Joueur::IsEgal(Joueur const& j) const{
    return (this->name.compare(j.name)==0 && this->password.compare(j.password)==0);
}

bool operator==(Joueur const& j1, Joueur const& j2){
    return j1.IsEgal(j2);
}
