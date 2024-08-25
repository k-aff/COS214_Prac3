#include "Legion.h"

Legion::Legion(){
}
void Legion::move(){
    for (UnitComponent* unit : allUnits) 
        unit->move();
}
void Legion::attack(){
    for(UnitComponent* unit : allUnits) 
        unit->attack();

}
void Legion::add(UnitComponent* component){
    allUnits.push_back(component);
}
void Legion::remove(UnitComponent* component){
    vector<UnitComponent*>::iterator it = std::remove(allUnits.begin(), allUnits.end(), component);
        
    allUnits.erase(it, allUnits.end());
}