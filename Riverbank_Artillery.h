// CONCRETE PRODUCT C2 - PART OF ABSTRACT FACTORY

#ifndef RIVERBANK_ARTILLERY_H
#define RIVERBANK_ARTILLERY_H

#include "Infantry.h"

class Riverbank_Artillery : public Artillery 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif