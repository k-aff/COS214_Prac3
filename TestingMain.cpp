#include <iostream>
using namespace std;

#include "Ambush.h"
#include "BattleStrategy.h"
#include "Flanking.h"
#include "Fortification.h"
#include "LegionFactory.h"
#include "OpenFieldFactory.h"
#include "RiverbankFactory.h"
#include "TacticalCommand.h"
#include "TacticalPlanner.h"
#include "TacticalMemento.h"
#include "TacticalCommand.h"
#include "WarArchives.h"
#include "WoodlandFactory.h"
#include "UnitComponent.h"
#include "Legion.h"
#include "Riverbank.h"
#include "OpenField.h"
#include "Woodland.h"

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
        {
            delete factories[i]; 
            factories[i] = nullptr; 
        }
        delete [] factories; 
        factories = nullptr; 

        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                delete legion[i][j];
                legion[i][j] = nullptr; 
            }
            delete [] legion[i];
            legion[i] = nullptr; 
        }
        delete [] legion; 
        legion = nullptr; 

        cout << "----------------------------------------------------------------------------------------------" << endl; 

    //TESTING MEMENTO PATTERN 
        cout << "TESTING MEMENTO DESIGN PATTERN: " << endl << endl; 

        //creating tactical planner
        BattleStrategy *ambush = new Ambush();  
        TacticalPlanner *ambushPlanner = new TacticalPlanner(ambush); 
        cout << "tactical planner for ambush created." << endl; 

        BattleStrategy *flanking = new Flanking();  
        TacticalPlanner *flankingPlanner = new TacticalPlanner(flanking); 
        cout << "tactical planner for flanking created." << endl; 

        BattleStrategy *fortification = new Fortification();  
        TacticalPlanner *fortificationPlanner = new TacticalPlanner(fortification); 
        cout << "tactical planner for fortification created." << endl << endl; 

        //creating mementos 
        TacticalMemento ** mementos = new TacticalMemento*[3]; 
        mementos[0] = ambushPlanner->createMemento(); 
        mementos[1] = flankingPlanner->createMemento(); 
        mementos[2] = fortificationPlanner->createMemento(); 
        cout << endl; 

        //testing get strategy 
        BattleStrategy * s0 = mementos[0]->getStrategy(); 
        s0->engage(); 
        BattleStrategy * s1 = mementos[1]->getStrategy(); 
        s1->engage(); 
        BattleStrategy * s2 = mementos[2]->getStrategy(); 
        s2->engage(); 
        cout << endl; 

        //restoring mementos 
        ambushPlanner->restoreMemento(mementos[0]);
        flankingPlanner->restoreMemento(mementos[1]);
        fortificationPlanner->restoreMemento(mementos[2]); 

        //deletes 

        delete ambush;
        ambush = nullptr; 
        delete ambushPlanner;
        ambushPlanner = nullptr; 

        delete flanking;
        flanking = nullptr;
        delete flankingPlanner;
        flankingPlanner = nullptr; 

        delete fortification; 
        fortification = nullptr; 
        delete fortificationPlanner;
        fortificationPlanner = nullptr; 

        for (int i=0; i<3; i++)
        {
            delete mementos[i];
            mementos[i] = nullptr;
        }
        delete [] mementos;
        mementos = nullptr;

        cout << "----------------------------------------------------------------------------------------------" << endl; 

    //TESTING STRATEGY PATTERN
        cout << "TESTING STRATEGY DESIGN PATTERN: " << endl << endl; 

        //create warArchive 
        WarArchives *archive = new WarArchives();
        cout << "war archive created" << endl; 

        //create strategy
        BattleStrategy *s = new Fortification(); 

        //create tacticalPlanner 
        TacticalPlanner *planner = new TacticalPlanner(s);
        TacticalMemento *mem = planner->createMemento(); 
        cout << endl; 
        
        //add memento to archive 
        string sMem = "first mem"; 
        archive->addTacticalMemento(mem, sMem);
        
        //create tacticalCommand
        TacticalCommand* command = new TacticalCommand(archive);

        //test set strategy for tactical command 
        BattleStrategy *strat = new Ambush();
        command->setStategy(strat);
        command->executeStrategy();
        cout << endl; 

        command->chooseBestStrategy(sMem);
        command->executeStrategy();

        delete s; 
        s = nullptr; 

        delete planner;
        planner = nullptr;

        delete mem;
        mem = nullptr;

        delete command;
        command = nullptr;

        cout << "----------------------------------------------------------------------------------------------" << endl; 

    //TESTING COMPOSITE PATTERN
        cout << "TESTING COMPOSITE DESIGN PATTERN: " << endl << endl;

        // //creat UnitComponents
        // Riverbank *r = new Riverbank();
        // Openfield *o = new Openfield();
        // Woodland *w = new Woodland();
        // Legion *l = new Legion();

        // l->add(r);

        cout << "----------------------------------------------------------------------------------------------" << endl; 

    return 0; 
}