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
#include "InterfaceConsole.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    int* bateauMax;
//    bateauMax = new int[6];
//    bateauMax[0] = 0;
//    bateauMax[1] = 0;
//    bateauMax[2] = 1;
//    bateauMax[3] = 2;
//    bateauMax[4] = 1;
//    bateauMax[5] = 1;
////    Plateau* p = new Plateau(7,7,bateauMax,5);
    Controller* c = new Controller(new Partie());
    c->Run();
//    
//    cout << p->SetBateau(3,3,2,HORIZONTAL) << endl;
//    cout << p->SetBateau(2,0,0,VERTICAL) << endl;
//    p->JouerBateauCase(0,0);
//    p->JouerBateauCase(1,0);
//    p->JouerBateauCase(1,1);
//    p->JouerBateauCase(3,3);
//    string** rpr;
//    string** rpr2 = p->GetPlateauAdversaire();
//    rpr = p->GetPlateauJoueur();
//    
//    for(int x=0; x<7; x++){
//        for(int y=0; y<7; y++){
//            cout << rpr[x][y] << '.';
//        }
//        cout << endl;
//    }
//    
//    cout << endl;
//    cout << endl;
//    cout << endl;
//    for(int x=0; x<7; x++){
//        for(int y=0; y<7; y++){
//            cout << rpr2[x][y] << '.';
//        }
//        cout << endl;
//    }
//    
//    cout << " pl " << p->IsAllBateauCoule() << endl;
//    
//    //c.AfficherPlateau(p);
//    //cout << endl;
//    //c.AfficherPlateauAdversaire(p);
//    cout << "Test" << endl;
    return 0;
}

