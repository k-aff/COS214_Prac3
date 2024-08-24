// CONCRETE PRODUCT C1 - PART OF ABSTRACT FACTORY

#ifndef WOODLAND_ARTILLERY_H
#define WOODLAND_ARTILLERY_H

#include "Infantry.h"

class Woodland_Artillery : public Infantry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif