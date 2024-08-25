#include "RiverbankFactory.h"
#include "Riverbank_Artillery.h"
#include "Riverbank_Cavalry.h"
#include "Riverbank_Infantry.h"

#include <iostream>
using namespace std; 

Infantry* RiverbankFactory::createInfantry()
{
    return new Riverbank_Infantry(); 
}

Cavalry* RiverbankFactory::createCavalry()
{
    return new Riverbank_Cavalry(); 
}

Artillery* RiverbankFactory::createArtillery()
{
    return new Riverbank_Artillery(); 
}

void RiverbankFactory::deployArtillery()
{
    cout << "Riverbank Artillery unit deployed." << endl; 
} 
