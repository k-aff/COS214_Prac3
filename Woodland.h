#ifndef WOODLAND_H
#define WOODLAND_H

#include <iostream>
#include <vector>

#include "UnitComponent.h"

using namespace std;

class Woodland : public UnitComponent{
    public: 
        void move();
        void attack();
        void add(UnitComponent* component);
        void remove(UnitComponent* component);

};

#endif