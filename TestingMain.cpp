#include <iostream>
using namespace std;

#include "BattleStrategy.h"
#include "Fortification.h"
#include "TacticalPlanner.h"
#include "TacticalMemento.h"
#include "WarArchives.h"

int main()
{
    //create warArchive 
    WarArchives *archive = new WarArchives();
    //create strategy
    BattleStrategy *s = new Fortification();  
    //create tacticalPlanner 
    TacticalPlanner *planner = new TacticalPlanner(s); //don't have battleStrategy yet
    TacticalMemento *mem = planner->createMemento(); 
    string sMem = "first mem"; 
    archive->addTacticalMemento(mem, sMem); 


    return 0; 
}