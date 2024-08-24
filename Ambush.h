#ifndef AMBUSH_H
#define AMBUSH_H

#include <iostream>
#include "BattleStrategy.h"

using namespace std;


class Ambush{
    public:
        virtual void engage();
};

void Ambush::engage(){
    cout<<"Engaging in battle by ambushing opposing army" << endl;
}

#endif
