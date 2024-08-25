// CONCRETE PRODUCT B3 - PART OF ABSTRACT FACTORY

#ifndef OPENFIELD_CAVALRY_H
#define OPENFIELD_CAVALRY_H

#include "Cavalry.h"

class OpenField_Cavalry : public Cavalry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif