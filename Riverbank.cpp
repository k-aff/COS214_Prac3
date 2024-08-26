#include "Riverbank.h"

Riverbank::Riverbank(LegionUnit** riverbankers, int size){

    riverbankUnits = riverbankers;
    this->size = size;
}
void Riverbank::move(){

    for(int i=0; i<size; i++)
        riverbankUnits[i]->move();

    cout<< "Riverbank units are moving" << endl << endl;
}

void Riverbank::attack(){

  for(int i=0; i<size; i++)
        riverbankUnits[i]->attack();

    cout<< "Riverbank units are attacking" << endl << endl;
}

void Riverbank::add(UnitComponent* component){
    
}

void Riverbank::remove(UnitComponent* component){

}