#ifndef FLANKING_H
#define FLANKING_H

using namespace std;

#include <iostream>
#include "BattleStrategy.h"

class Flanking{
    public:
        virtual void engage();
};


void Flanking::engage(){
    cout<<"Engaging in battle by flanking the enemy from the sides." << endl;
}

#endif

