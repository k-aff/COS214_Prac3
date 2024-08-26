#ifndef WOODLAND_H
#define WOODLAND_H

#include <iostream>
#include <vector>

#include "UnitComponent.h"
#include "LegionUnit.h"

using namespace std;

class Woodland : public UnitComponent{
    public: 
        Woodland(LegionUnit** woodlanders, int size);
        void move();
        void attack();
        void add(UnitComponent* component);
        void remove(UnitComponent* component);

    private:
        LegionUnit** woodlandUnits;
        int size;

};

#endif