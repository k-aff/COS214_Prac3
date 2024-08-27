#include "OpenField.h"
#include "OpenField.h"

OpenField::OpenField(LegionUnit** openfielders, int size){
    
    openfieldUnits = openfielders;
    this->size = size;
}
void OpenField::move(){

    for(int i=0; i<size; i++)
        openfieldUnits[i]->move();

    cout<< "Openfield units are moving" << endl << endl;
}

void OpenField::attack(){

    for(int i=0; i<size; i++)
        openfieldUnits[i]->attack();
    
    cout<< "Openfield units are attacking" << endl << endl;
}

void OpenField::add(UnitComponent* component){
    
}

void OpenField::remove(UnitComponent* component){

}