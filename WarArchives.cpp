#include "WarArchives.h"

#include <iostream>
using namespace std; 

void WarArchives::addTacticalMemento(TacticalMemento* memento, std::string label)
{
    archive[label] = memento; 
}

TacticalMemento* WarArchives::removeTacticalMemento(std::string label)
{
    if (archive.find(label) == archive.end()) 
    {
        cout << "Memento not in archive" << endl; 
        return nullptr; 
    }
    else
    {
        cout << "Memento retrieved from archive" << endl; 
        TacticalMemento *mem = archive[label];
        archive.erase(label);  
        return mem; 
    }
}