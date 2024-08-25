// #include <iostream>
// using namespace std;

// #include "BattleStrategy.h"
// #include "Fortification.h"
// #include "LegionFactory.h"
// #include "OpenFieldFactory.h"
// #include "RiverbankFactory.h"
// #include "TacticalPlanner.h"
// #include "TacticalMemento.h"
// #include "WarArchives.h"
// #include "WoodlandFactory.h"

// int main()
// {
//     //introduction
//     cout << "------------------------------------------------------------------------------------------------------------------" << endl;
//     cout << "WELCOME TO: THE CALL OF DESTINY" << endl; 
//     cout << "created by Gang of Two (GoT)" << endl; 
//     cout << "------------------------------------------------------------------------------------------------------------------" << endl;
//     cout << "Introduction: " << endl; 
//     cout << "It is the year 100 BC, Rome is a republic on the brink of empire." << endl;
//     cout << "To the north, hostile barbarian tribes threaten the borders." << endl; 
//     cout << "To the east, the vast realms of Parthia eye Rome warily." << endl; 
//     cout <<  "As you, a young Roman legionnaire, Titus Flavius rises through the ranks in a time of war and expansion," << endl; 
//     cout << "you are tasked with strategically building and managing the Roman legions using advanced military systems." << endl; 
//     cout << "------------------------------------------------------------------------------------------------------------------" << endl;

//     //creating factories
//     cout << "Creating Factories..." << endl; 
//     LegionFactory ** factories = new LegionFactory*[3]; 
//     factories[0] = new OpenFieldFactory(); 
//     cout << "   Open Field Factory created." << endl; 
//     factories[1] = new RiverbankFactory(); 
//     cout << "   Riverbank Factory created." << endl; 
//     factories[2] = new WoodlandFactory(); 
//     cout << "   Woodland Factory created." << endl; 
//     cout << "3 Factories Created" << endl; 
//     cout << "------------------------------------------------------------------------------------------------------------------" << endl;

//     //deletes
//     for (int i=0; i<3; i++)
//         delete factories[i]; 
//     delete [] factories; 
   
//    return 0; 
// }