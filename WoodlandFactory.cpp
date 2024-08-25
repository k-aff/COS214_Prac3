#include "WoodlandFactory.h"
#include "Woodland_Artillery.h"
#include "Woodland_Cavalry.h"
#include "Woodland_Infantry.h"

#include <iostream>
using namespace std; 

Infantry* WoodlandFactory::createInfantry()
{
    return new Woodland_Infantry(); 
}

Cavalry* WoodlandFactory::createCavalry()
{
    return new Woodland_Cavalry(); 
}

Artillery* WoodlandFactory::createArtillery()
{
    return new Woodland_Artillery(); 
}

void WoodlandFactory::deployArtillery()
{
    cout << "Woodland Artillery unit deployed." << endl; 
}
