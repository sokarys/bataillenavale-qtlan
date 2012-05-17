/* 
 * File:   main.cpp
 * Author: Olivier
 *
 * Created on 13 mai 2012, 22:44
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "Plateau.h"
#include "Controller.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Plateau* p = new Plateau(7,7);
    Controller c = Controller();
    cout << p->SetBateau(3,3,2,HORIZONTAL) << endl;
    cout << p->SetBateau(2,0,0,VERTICAL) << endl;
    
    string** rpr;
    string** rpr2 = p->GetPlateauAdversaire();
    rpr = p->GetPlateauJoueur();
    
    for(int x=0; x<7; x++){
        for(int y=0; y<7; y++){
            cout << rpr[x][y] << '.';
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    for(int x=0; x<7; x++){
        for(int y=0; y<7; y++){
            cout << rpr2[x][y] << '.';
        }
        cout << endl;
    }
    
    //c.AfficherPlateau(p);
    //cout << endl;
    //c.AfficherPlateauAdversaire(p);
    cout << "Test" << endl;
    return 0;
}

