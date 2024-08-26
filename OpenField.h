#ifndef OPENFIELD_H
#define OPENFIELD_H

#include <iostream>
#include <vector>

#include "UnitComponent.h"
#include "LegionUnit.h"

using namespace std;

class Openfield : public UnitComponent{
    public: 
        Openfield(LegionUnit** openfield, int size);
        void move();
        void attack();
        void add(UnitComponent* component);
        void remove(UnitComponent* component);
    
    private:
        LegionUnit** openfieldUnits;
        int size;
};

#endif