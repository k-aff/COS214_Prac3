// CONCRETE FACTORY 2 - PART OF ABSTRACT FACTORY

#ifndef WOODLANDFACTORY_H
#define WOODLANDFACTORY_H

#include "LegionFactory.h"

class WoodlandFactory : public LegionFactory
{
    public:
        virtual Infantry* createInfantry(); 
        virtual Cavalry* createCavalry();
        virtual Artillery* createArtillery(); 

        virtual void deployArtillery(); 

};

#endif