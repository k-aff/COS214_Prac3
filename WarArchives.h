#ifndef WARARCHIVES_H
#define WARARCHIVES_H

#include <iostream>
#include "TacticalMemento.h"


using namespace std;

class WarArchives{
    
    public:
        void addTacticalMememento(TacticalMemento* memento, string label);
        TacticalMemento* removeTacticalMemento(string label);
};

#endif