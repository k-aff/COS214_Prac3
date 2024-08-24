#include "TacticalCommand.h"
#include "WarArchives.h"

void TacticalCommand::setStategy(BattleStrategy* s){
    if(strategy!=nullptr)
        delete strategy;
    
    strategy = s;
}

void TacticalCommand::executeStrategy(){
    strategy->engage();

}

void TacticalCommand::chooseBestStrategy(){
    //Figure out later 
}

TacticalCommand::~TacticalCommand(){
    delete strategy;
    strategy = nullptr;
}