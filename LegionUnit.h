// ABSTRACT CLASS - NOT PART OF ABSTRACT FACTORY 

/* Description: Serves as the common interface for all military units produced \
   by the factories, ensuring standard functionality across different unit types. */

#ifndef LEGIONUNIT_H
#define LEGIONUNIT_H

class LegionUnit
{
    public: 
        virtual void move() = 0; 
        virtual void attack() = 0; 

};

#endif 