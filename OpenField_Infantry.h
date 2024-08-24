// CONCRETE PRODUCT A3 - PART OF ABSTRACT FACTORY

#ifndef OPENFIELD_INFANTRY_H
#define OPENFIELD_INFANTRY_H

#include "Infantry.h"

class OpenField_Infantry : public Infantry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif