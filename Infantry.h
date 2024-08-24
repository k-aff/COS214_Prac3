// ABSTRACT PRODUCT A - PART OF ABSTRACT FACTORY 

/* Details: Optimized for close combat and defense operations. */

#ifndef INFANTRY_H
#define INFANTRY_H

#include "LegionUnit.h"

class Infantry : public LegionUnit 
{
    public:
        virtual void move() = 0; 
        virtual void attack() = 0; 
        
};

#endif 