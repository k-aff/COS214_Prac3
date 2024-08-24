// CONCRETE PRODUCT A1 - PART OF ABSTRACT FACTORY

#ifndef WOODLAND_INFANTRY_H
#define WOODLAND_INFANTRY_H

#include "Infantry.h"

class Woodland_Infanty : public Infantry 
{
    public:
        virtual void move(); 
        virtual void attack(); 

}; 

#endif