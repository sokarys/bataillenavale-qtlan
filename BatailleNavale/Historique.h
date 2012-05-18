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
    Historique(int victoire=0, int defaite=0, int abandon=0);
    virtual ~Historique();
    void AddVictoire();
    void AddDefaite();
    void AddAbandon();
    
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

