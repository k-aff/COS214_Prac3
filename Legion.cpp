#include <algorithm>
#include "Legion.h"

Legion::Legion(){

}

void Legion::move(){
    for (UnitComponent* unit : allUnits) 
        unit->move();

    cout<< "All soldier units moving in their respective terrains" << endl << endl;
}

void Legion::attack(){

    for(UnitComponent* unit : allUnits) 
        unit->attack();

    cout<< "All soldier units attacking in their respective terrains" << endl << endl;
}

void Legion::add(UnitComponent* component){
    allUnits.push_back(component);

    cout<< "Unit added successfully" << endl;
}

void Legion::remove(UnitComponent* component){

    std::vector<UnitComponent*>::iterator it = std::find(allUnits.begin(), allUnits.end(), component);

    if (it != allUnits.end()) {
        allUnits.erase(it);
    }

    cout<< "Unit removed successfully" << endl << endl;

}