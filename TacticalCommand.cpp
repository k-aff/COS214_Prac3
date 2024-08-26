#include "TacticalCommand.h"
#include "WarArchives.h"
#include "TacticalMemento.h"

TacticalCommand::TacticalCommand(WarArchives* archive){
    this->archive = archive;
    this->strategy = nullptr;
}
void TacticalCommand::setStategy(BattleStrategy* s){
    if(strategy!=nullptr)
        delete strategy;
    
    strategy = s;
}

void TacticalCommand::executeStrategy(){

    if(strategy!=nullptr)
        strategy->engage();
    else 
        cout<< "Cannot execute without strategy. Please set a strategy." << endl;
}

void TacticalCommand::chooseBestStrategy(string label){

    TacticalMemento* memento = nullptr;

    if(archive!=nullptr)
        TacticalMemento* memento = archive->removeTacticalMemento(label); //something wrong
    else{
        cout<< "Archive not available :(" << endl;
        return;
    }

    if(strategy!=nullptr|| memento!=nullptr){
        delete strategy;
    }
    else if(memento==nullptr)
        cout<<"Could not retrieve specified strategy from archive" << endl;
    
    this->strategy = memento->getStrategy();
    cout<< "Best strategy has been chosen! Ready to attack" << endl;
}

TacticalCommand::~TacticalCommand(){

    // if(strategy!=nullptr){
    //     delete strategy;
    //     strategy = nullptr;
    // }

    if(archive!=nullptr){
        delete archive;
        archive = nullptr;
    }

}