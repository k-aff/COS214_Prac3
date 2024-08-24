#ifndef UNITCOMPONENT_H
#define UNITCOMPONENT_H

#include <iostream>

using namespace std;

class UnitComponent{
    void move();
    void attack();
    void add(UnitComponent* component);
    void remove(UnitComponent* component);
};

#endif 