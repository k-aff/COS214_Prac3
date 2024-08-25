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
    cout << "Memento created, current stratedgy has been saved." << endl; 
    return mem; 
}

void TacticalPlanner::restoreMemento(TacticalMemento* memento)
{
    currentStrategy = memento->currentStrategy; 
    cout << "Memento restored, current strategy has been changed." << endl; 
} 