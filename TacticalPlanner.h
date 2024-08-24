// ORIGINATOR - PART OF MEMENTO

#ifndef TACTICALPLANNER_H
#define TACTICALPLANNER_H

#include "BattleStrategy.h"
#include "TacticalMemento.h"

class TacticalPlanner
{
    private:
        BattleStrategy* currentStrategy; 
    
    public: 
        TacticalPlanner(BattleStrategy* s); 
        TacticalMemento* createMemento(); 
        void restoreMemento(TacticalMemento* memento); 

}; 

#endif