// CONCRETE FACTORY 3 - PART OF ABSTRACT FACTORY

#ifndef OPENFIELDFACTORY_H
#define OPENFIELDFACTORY_H

#include "LegionFactory.h"

class OpenFieldFactory : public LegionFactory
{
    public:
        virtual Infantry* createInfantry(); 
        virtual Cavalry* createCavalry();
        virtual Artillery* createArtillery(); 

        void deployArtillery(); // ?? unknown return type

};

#endif