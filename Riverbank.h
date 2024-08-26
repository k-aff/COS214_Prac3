#ifndef RIVERBANK_H
#define RIVERBANK_H

#include <iostream>
#include <vector>

#include "UnitComponent.h"
#include "LegionUnit.h"

using namespace std;

class Riverbank : public UnitComponent{
    public: 
        Riverbank(LegionUnit** riverbankers, int size);
        void move();
        void attack();
        void add(UnitComponent* component);
        void remove(UnitComponent* component);

    private:
        LegionUnit** riverbankUnits;
        int size;

};

#endif