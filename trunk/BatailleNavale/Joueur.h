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
        /**
         * 
         * @return l'historique du joueur
         */
        Historique* GetHistorique();
        
        /**
         * 
         * @return le nom du joueur
         */
        string GetName();
        
        /**
         * 
         * @return le passowrd en clair du joueur (a modif)
         */
        string GetPassword();
        
        /**
         * 
         * @param j
         * @return true si deux joueur on meme nom et meme passowrd
         */
        bool IsEgal(Joueur const& j) const;
        
    protected:
        
    private:
        string name;
        string password;
        Historique* historique;
        
};

#endif // JOUEUR_H
