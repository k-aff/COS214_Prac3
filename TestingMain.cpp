#include <iostream>
using namespace std;

#include "BattleStrategy.h"
#include "Fortification.h"
#include "LegionFactory.h"
#include "OpenFieldFactory.h"
#include "RiverbankFactory.h"
#include "TacticalPlanner.h"
#include "TacticalMemento.h"
#include "WarArchives.h"
#include "WoodlandFactory.h"

int main()
{
    cout << "----------------------------------------------------------------------------------------------" << endl; 

    //TESTING ABSTRACT FACTORY PATTERN 
        cout << "TESTING ABSTRACT FACTORY DESIGN PATTERN: " << endl << endl; 
        //create factories 
        LegionFactory ** factories = new LegionFactory*[3]; 
        factories[0] = new OpenFieldFactory(); 
        factories[1] = new RiverbankFactory(); 
        factories[2] = new WoodlandFactory(); 
        cout << "all factories created" << endl << endl; 

        //testing deploy artillery in the factories
        factories[0]->deployArtillery(); 
        factories[1]->deployArtillery(); 
        factories[2]->deployArtillery(); 
        cout << endl; 

        //create artillery unit per factory
        LegionUnit ** artilleryUnits = new LegionUnit*[3]; 
        artilleryUnits[0] = factories[0]->createArtillery(); 
        artilleryUnits[1] = factories[1]->createArtillery(); 
        artilleryUnits[2] = factories[2]->createArtillery(); 
        cout << "created artillery units using each factory" << endl << endl; 

        //create cavalry unit per factory
        LegionUnit ** cavalryUnits = new LegionUnit*[3]; 
        cavalryUnits[0] = factories[0]->createCavalry(); 
        cavalryUnits[1] = factories[1]->createCavalry(); 
        cavalryUnits[2] = factories[2]->createCavalry(); 
        cout << "created cavalry units using each factory" << endl << endl; 

        //create infantry unit per factory
        LegionUnit ** infantryUnits = new LegionUnit*[3]; 
        infantryUnits[0] = factories[0]->createInfantry(); 
        infantryUnits[1] = factories[1]->createInfantry(); 
        infantryUnits[2] = factories[2]->createInfantry(); 
        cout << "created infantry units using each factory" << endl << endl; 

        //join all units in an array of legion units
        LegionUnit *** legion = new LegionUnit**[3];
        legion[0] = artilleryUnits; 
        legion[1] = cavalryUnits; 
        legion[2] = infantryUnits;
        cout << "legion created with artillery, cavalry & infantry units" << endl << endl; 

        //testing attack and move
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                legion[i][j]->attack(); 
                legion[i][j]->move(); 
            }
        }

        //deletes
        for (int i=0; i<3; i++)
            delete factories[i]; 
        delete [] factories; 

        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
                delete legion[i][j];
            delete [] legion[i];
        }
        delete [] legion; 

        cout << "----------------------------------------------------------------------------------------------" << endl; 

    // //create warArchive 
    // WarArchives *archive = new WarArchives();
    // //create strategy
    // BattleStrategy *s = new Fortification();  
    // //create tacticalPlanner 
    // TacticalPlanner *planner = new TacticalPlanner(s); //don't have battleStrategy yet
    // TacticalMemento *mem = planner->createMemento(); 
    // string sMem = "first mem"; 
    // archive->addTacticalMemento(mem, sMem); 


    return 0; 
}