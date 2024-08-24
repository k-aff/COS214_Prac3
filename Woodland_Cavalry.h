// CONCRETE PRODUCT B1 - PART OF ABSTRACT FACTORY

#ifndef WOODLAND_CAVALRY_H
#define WOODLAND_CAVALRY_H

#include "Infantry.h"

class Woodland_Cavalry : public Infantry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif