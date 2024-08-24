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
        return nullptr; 
    }
    else
    {
        TacticalMemento *mem = archive[label];
        archive.erase(label);  
        return mem; 
    }
}