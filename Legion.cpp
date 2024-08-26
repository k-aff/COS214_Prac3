#include "Legion.h"

Legion::Legion(){

}

void Legion::move(){
    for (UnitComponent* unit : allUnits) 
        unit->move();

    cout<< "Units moving" << endl;
}

void Legion::attack(){

    for(UnitComponent* unit : allUnits) 
        unit->attack();

    cout<< "Units attacking" << endl;
}

void Legion::add(UnitComponent* component){
    allUnits.push_back(component);

    cout<< "Unit added successfully" << endl;
}

void Legion::remove(UnitComponent* component){

    vector<UnitComponent*>::iterator it = allUnits.;
    allUnits.erase(it);
}