#ifndef JOUEUR_H
#define JOUEUR_H

#include "Bateau.h"
#include "Historique.h"

#include <string>

using namespace std;

class Joueur
{
    public:
        Joueur(string name, string password, Historique* historique=NULL);
        virtual ~Joueur();
        
        Historique* GetHistorique();
        
        string GetName();
        string GetPassword();
        
        bool IsEgal(Joueur const& j) const;
        
    protected:
        
    private:
        string name;
        string password;
        Historique* historique;
        
};

#endif // JOUEUR_H
