// MEMENTO CLASS 

#ifndef TACTICALMEMENTO_H
#define TACTICALMEMENTO_H

#include "BattleStrategy.h"

class TacticalMemento
{
    private:
        BattleStrategy* currentStrategy; 
        void storeStrategy(BattleStrategy* s); 

    public:
        friend class TacticalPlanner; 
        BattleStrategy* getStrategy(); 
        
}; 

#endif