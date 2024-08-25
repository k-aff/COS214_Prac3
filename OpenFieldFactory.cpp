#include "OpenFieldFactory.h"
#include "OpenField_Artillery.h"
#include "OpenField_Cavalry.h"
#include "OpenField_Infantry.h"

#include <iostream>
using namespace std; 

Infantry* OpenFieldFactory::createInfantry()
{
    return new OpenField_Infantry(); 
}

Cavalry* OpenFieldFactory::createCavalry()
{
    return new OpenField_Cavalry(); 
}

Artillery* OpenFieldFactory::createArtillery()
{
    return new OpenField_Artillery(); 
} 

void OpenFieldFactory::deployArtillery()
{
    cout << "OpenField Artillery unit deployed." << endl; 
} 
