#ifndef TACTICALPLANNER_H
#define TACTICALPLANNER_H

#include <iostream>
#include "TacticalMemento.h"

using namespace std;

class TacticalPlanner{

    public:
        TacticalMemento* createMemento();
        void restoreMemento(TacticalMemento*);

};

#endif