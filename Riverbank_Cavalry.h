// CONCRETE PRODUCT C2 - PART OF ABSTRACT FACTORY

#ifndef RIVERBANK_CAVALRY_H
#define RIVERBANK_CAVALRY_H

#include "Infantry.h"

class Riverbank_Cavalry : public Infantry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif