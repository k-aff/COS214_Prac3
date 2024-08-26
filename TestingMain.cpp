#include <iostream>
using namespace std;

#include "Ambush.h"
#include "BattleStrategy.h"
#include "Flanking.h"
#include "Fortification.h"
#include "LegionFactory.h"
#include "OpenFieldFactory.h"
#include "RiverbankFactory.h"
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
        LegionUnit *** legionUnit = new LegionUnit**[3];
        legionUnit[0] = artilleryUnits; 
        legionUnit[1] = cavalryUnits; 
        legionUnit[2] = infantryUnits;
        cout << "legion units created with artillery, cavalry & infantry units" << endl << endl; 

        //testing attack and move
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                legionUnit[i][j]->attack(); 
                legionUnit[i][j]->move(); 
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
                delete legionUnit[i][j];
                legionUnit[i][j] = nullptr; 
            }
            delete [] legionUnit[i];
            legionUnit[i] = nullptr; 
        }
        delete [] legionUnit; 
        legionUnit = nullptr; 

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

        //create strategy
        BattleStrategy *s = new Fortification();  

        //create tacticalPlanner 
        TacticalPlanner *planner = new TacticalPlanner(s);
        TacticalMemento *mem = planner->createMemento(); 
        string sMem = "first mem"; 
        archive->addTacticalMemento(mem, sMem); 

        //create tacticalCommand
        TacticalCommand* command = new TacticalCommand(*archive);
        BattleStrategy *strat = new Ambush();
        cout <<"Setting command strategy." << endl << endl;
        command->setStategy(strat);

        cout <<"Executing strategy using command"<< endl;
        command->executeStrategy();

        cout << "Choosing best strategy" << endl;
        command->chooseBestStrategy("first mem");

        cout << "Executing best strategy using command" << endl;
        command->executeStrategy();

        cout << "Attempting to choose best strategy using unknown memento label" << endl;
        command->chooseBestStrategy("other mem");

        //deletes
        delete planner;
        planner = nullptr;

        delete mem;
        mem = nullptr;

        delete command;
        command = nullptr;

        cout << "----------------------------------------------------------------------------------------------" << endl; 

    //TESTING COMPOSITE PATTERN
        cout << "TESTING COMPOSITE DESIGN PATTERN: " << endl << endl;

        //create LegionUnits

        factories = new LegionFactory*[3]; 
        factories[0] = new OpenFieldFactory(); 
        factories[1] = new RiverbankFactory(); 
        factories[2] = new WoodlandFactory(); 
        // cout << "all factories created" << endl << endl; 

        //create a unit of each soldier type for the riverbank
        LegionUnit ** openfieldUnits = new LegionUnit*[3]; 
        openfieldUnits[0] = factories[0]->createArtillery(); 
        openfieldUnits[1] = factories[0]->createCavalry(); 
        openfieldUnits[2] = factories[0]->createInfantry(); 
        cout << "Created units of each soldier type for the openfield using Openfield factory." << endl << endl; 

        //create a unit of each soldier type for the openfield
        LegionUnit ** riverbankUnits = new LegionUnit*[3]; 
        riverbankUnits[0] = factories[1]->createArtillery(); 
        riverbankUnits[1] = factories[1]->createCavalry(); 
        riverbankUnits[2] = factories[1]->createInfantry(); 
        cout << "Created units of each soldier type for the riverbank using Riverbank factory." << endl << endl; 

        //create a unit of each soldier type for the woodland
        LegionUnit ** woodlandUnits = new LegionUnit*[3]; 
        woodlandUnits[0] = factories[2]->createArtillery(); 
        woodlandUnits[1] = factories[2]->createCavalry(); 
        woodlandUnits[2] = factories[2]->createInfantry(); 
        cout << "Created units of each soldier type for the woodland using Woodland factory." << endl << endl; 

        //instantiate the terrains
        OpenField *o = new OpenField(openfieldUnits, 3);
        Riverbank *r = new Riverbank(riverbankUnits,3);
        Woodland *w = new Woodland(woodlandUnits,3);

        cout<< "Creating a Legion consisting of Artillary, Infantry and Cavalry soldiers in the open fields, river bank and wood lands." << endl << endl;
        //instantiate a legion
        Legion *legion = new Legion();
        //create a legion of all soldier types for all kinds of terrains
        legion->add(o);
        legion->add(r);
        legion->add(w);

        cout << endl;
        cout<< "Entire legion consisting of Artillary, Infantry and Cavalry soldiers is moving in the open fields, river bank and wood lands." << endl << endl;
        legion->move();

        //testing remove
        cout<< "Removing Wood land soldiers from Legion" << endl;
        legion->remove(w);
    
        cout<< "Legion attacking without woodland" << endl << endl;
        legion->attack();

        //deletes
        delete legion;
        legion = nullptr;

        delete o;
        o = nullptr;

        delete r;
        r = nullptr;

        delete w;
        w = nullptr;


        for (int i=0; i<3; i++)
        {
            delete factories[i]; 
            factories[i] = nullptr; 
        }
        delete [] factories; 
        factories = nullptr; 

        for (int i=0; i<3; i++)
        {
            delete openfieldUnits[i]; 
            openfieldUnits[i] = nullptr; 
        }
        delete [] openfieldUnits; 
        openfieldUnits = nullptr; 

        for (int i=0; i<3; i++)
        {
            delete riverbankUnits[i]; 
            riverbankUnits[i] = nullptr; 
        }
        delete [] riverbankUnits; 
        riverbankUnits = nullptr; 

        for (int i=0; i<3; i++)
        {
            delete woodlandUnits[i]; 
            woodlandUnits[i] = nullptr; 
        }

        delete [] woodlandUnits; 
        woodlandUnits = nullptr; 
         
        cout << "END OF DEMO!" << endl << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl; 

    return 0; 
}