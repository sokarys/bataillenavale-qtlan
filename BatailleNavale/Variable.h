/* 
 * File:   Variable.h
 * Author: Olivier
 *
 * Created on 18 mai 2012, 16:06
 */

#ifndef VARIABLE_H
#define	VARIABLE_H

#define MAX_JOUEUR 2
#define DEBUG 0
#define MIN_TAILLE_BATEAU 2
#define MAX_TAILLE_BATEAU 5
#define REP_SEPARATION "|"
#define REP_EAU "E"
#define REP_PAS_JOUE "_"
#define REP_TOUCHE "T"
#define REP_COULE "C"

enum ETAT_BATEAUCASE {TOUCHE, EAU, PAS_JOUEE, COULE_BC};
enum ALLIGNEMENT {VERTICAL, HORIZONTAL, RIEN};
enum ETAT_BATEAU {COULE, PAS_COULE};


#endif	/* VARIABLE_H */

