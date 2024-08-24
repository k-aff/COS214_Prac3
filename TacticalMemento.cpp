#include "TacticalMemento.h"

#include <iostream>
using namespace std; 

void TacticalMemento::storeStrategy(BattleStrategy* s)
{
    currentStrategy = s; 
}

BattleStrategy* TacticalMemento::getStrategy()
{
    return currentStrategy; 
}

