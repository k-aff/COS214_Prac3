#include "TacticalMemento.h"

#include <iostream>
using namespace std; 

void TacticalMemento::storeStrategy(BattleStrategy* s)
{
    currentStrategy = s; 
}

BattleStrategy* TacticalMemento::getStrategy()
{
    if (this->currentStrategy != nullptr)
        return currentStrategy; 
    else cout<<"Strategy not set, cannot retrieve strategy form memento." << endl;
}

