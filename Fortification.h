#ifndef FORTIFICATION_H
#define FORTIFICATION_H

#include <iostream>
#include "BattleStrategy.h"

using namespace std;


class Fortification{
    public:
        virtual void engage();
};


void Fortification::engage(){
    cout << "Engaging in battle by fortifying the base and strengthening defenses." << endl; 
}

#endif
