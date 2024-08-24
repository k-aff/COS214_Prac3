// CONCRETE PRODUCT A2 - PART OF ABSTRACT FACTORY

#ifndef RIVERBANK_INFANTRY_H
#define RIVERBANK_INFANTRY_H

#include "Infantry.h"

class Riverbank_Infanty : public Infantry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif