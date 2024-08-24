// ABSTRACT PRODUCT C - PART OF ABSTRACT FACTORY 

/* Details: Delivers long-range support and bombardment capabilities. */

#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "LegionUnit.h"

class Artillery : public LegionUnit 
{
    public:
        virtual void move(); 
        virtual void attack(); 
        
};

#endif 