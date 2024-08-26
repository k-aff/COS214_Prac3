#include "Woodland.h"

Woodland::Woodland(LegionUnit** woodlanders, int size){
    
    woodlandUnits = woodlanders;
    this->size = size;
}
void Woodland::move(){

    for(int i=0; i<size; i++)
        woodlandUnits[i]->move();

    cout<< "Woodland units are moving" << endl << endl;
}

void Woodland::attack(){

   for(int i=0; i<size; i++)
        woodlandUnits[i]->attack();

    cout<< "Woodland units are attacking" << endl << endl;
}

void Woodland::add(UnitComponent* component){
    
}

void Woodland::remove(UnitComponent* component){

}