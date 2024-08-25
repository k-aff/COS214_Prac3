#ifndef RIVERBANK_H
#define RIVERBANK_H

#include <iostream>
#include <vector>

#include "UnitComponent.h"

using namespace std;

class Riverbank : public UnitComponent{
    public: 
        void move();
        void attack();
        void add(UnitComponent* component);
        void remove(UnitComponent* component);

    private:
        vector<UnitComponent*> allUnits;

};

#endif