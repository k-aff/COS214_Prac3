#ifndef OPENFIELD_H
#define OPENFIELD_H

#include <iostream>
#include <vector>

#include "UnitComponent.h"

using namespace std;

class Openfield : public UnitComponent{
    public: 
        void move();
        void attack();
        void add(UnitComponent* component);
        void remove(UnitComponent* component);

    private:
        vector<UnitComponent*> allUnits;

};

#endif