#include "TacticalCommand.h"
#include "WarArchives.h"
#include "TacticalMemento.h"

TacticalCommand::TacticalCommand(WarArchives& archive){
    this->archives = archives;
}
void TacticalCommand::setStategy(BattleStrategy* s){
    if(strategy!=nullptr)
        delete strategy;
    
    strategy = s;
}

void TacticalCommand::executeStrategy(){
    strategy->engage();

}

void TacticalCommand::chooseBestStrategy(string label){
    TacticalMemento* memento = archives->removeTacticalMemento(label);
    this->strategy = memento->getStrategy();
}

TacticalCommand::~TacticalCommand(){

    // if(strategy!=nullptr){
    //     delete strategy;
    //     strategy = nullptr;
    // }

    if(archives!=nullptr){
        delete archives;
        archives = nullptr;
    }

}