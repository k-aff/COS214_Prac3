// CONCRETE PRODUCT C3 - PART OF ABSTRACT FACTORY

#ifndef OPENFIELD_ARTILLERY_H
#define OPENFIELD_ARTILLERY_H

#include "Infantry.h"

class OpenField_Artillery : public Infantry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif