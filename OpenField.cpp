#include "Openfield.h"

Openfield::Openfield(LegionUnit** openfielders, int size){
    
    openfieldUnits = openfielders;
    this->size = size;
}
void Openfield::move(){

    for(int i=0; i<size; i++)
        openfieldUnits[i]->move();

    cout<< "Openfield units are moving" << endl << endl;
}

void Openfield::attack(){

    for(int i=0; i<size; i++)
        openfieldUnits[i]->attack();
    
    cout<< "Openfield units are attacking" << endl << endl;
}

void Openfield::add(UnitComponent* component){
    
}

void Openfield::remove(UnitComponent* component){

}