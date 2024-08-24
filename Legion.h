#ifndef LEGION_H
#define LEGION_H

#include <iostream>
#include <vector>

#include "UnitComponent.h"

using namespace std;

class Legion : public UnitComponent{
    public: 
        Legion();
        void move();
        void attack();
        void add(UnitComponent* component);
        void remove(UnitComponent* component);

    private:
        vector<UnitComponent*> allUnits;

};

#endif