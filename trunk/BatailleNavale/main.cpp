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
    Controller* c = new Controller(new Partie());
    c->Run();
    return 0;
}

