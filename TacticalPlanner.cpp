#include "TacticalPlanner.h"

#include <iostream>
using namespace std; 

TacticalPlanner::TacticalPlanner(BattleStrategy* s)
{
    currentStrategy = s; 
}

TacticalMemento* TacticalPlanner::createMemento()
{
    TacticalMemento *mem = new TacticalMemento(); 
    mem->storeStrategy(currentStrategy); 
    return mem; 
}

void TacticalPlanner::restoreMemento(TacticalMemento* memento)
{
    currentStrategy = memento->currentStrategy; 
} 