/* 
 * File:   Historique.h
 * Author: Olivier
 *
 * Created on 17 mai 2012, 19:05
 */

#ifndef HISTORIQUE_H
#define	HISTORIQUE_H

class Historique {
public:
    /**
     * Construteur
     * @param victoire
     * @param defaite
     * @param abandon
     */
    Historique(int victoire=0, int defaite=0, int abandon=0);
    virtual ~Historique();
    
    /**
     * Rajouter une victoire a l'historique
     * @return 
     */
    void AddVictoire();
    
    /**
     * Permet de rajouter une defaite a l'historique
     */
    void AddDefaite();
    
    /**
     * Permet de rajouter un abandon a historique
     */
    void AddAbandon();
    
    /**Getters and Setters*/
    int GetVictoire();
    int GetDefaite();
    int GetAbandon();
    void SetVictoire(int victoire);
    void SetDefaite(int defaite);
    void SetAbandon(int abandon);
    
private:
    int victoire;
    int defaite;
    int abandon;

};

#endif	/* HISTORIQUE_H */

