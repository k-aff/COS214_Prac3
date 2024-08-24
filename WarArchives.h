#ifndef WARARCHIVES_H
#define WARARCHIVES_H

#include "TacticalMemento.h"

#include <unordered_map>

class WarArchives
{
    private:
        std::unordered_map<std::string, TacticalMemento*> archive;

    public:
        void addTacticalMemento(TacticalMemento* memento, std::string label); 
        TacticalMemento* removeTacticalMemento(std::string label); 
    
};

#endif