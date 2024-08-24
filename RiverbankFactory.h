// CONCRETE FACTORY 1 - PART OF ABSTRACT FACTORY

#ifndef RIVERBANKFACTORY_H
#define RIVERBANKFACTORY_H

#include "LegionFactory.h"

class RiverbankFactory : public LegionFactory
{
    public:
        virtual Infantry* createInfantry(); 
        virtual Cavalry* createCavalry();
        virtual Artillery* createArtillery(); 

        void deployArtillery(); // ?? unknown return type

};

#endif
