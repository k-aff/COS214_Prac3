// ABSTRACT PRODUCT B - PART OF ABSTRACT FACTORY 

/* Details: Provides mobility and impact in flanking maneuvers. */

#ifndef CAVALRY_H
#define CAVALRY_H

#include "LegionUnit.h"

class Cavalry : public LegionUnit 
{
    public:
        virtual void move(); 
        virtual void attack(); 
        
};

#endif 