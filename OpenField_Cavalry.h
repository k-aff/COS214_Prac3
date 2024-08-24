// CONCRETE PRODUCT B3 - PART OF ABSTRACT FACTORY

#ifndef OPENFIELD_CAVALRY_H
#define OPENFIELD_CAVALRY_H

#include "Infantry.h"

class OpenField_Cavalry : public Infantry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif