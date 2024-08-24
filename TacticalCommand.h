#ifndef TACTICALCOMMAND_H
#define TACTICALCOMMAND_H

#include "BattleStrategy.h"

#include <iostream>

using namespace std;

class TacticalCommand{

    protected:
        BattleStrategy* strategy;

    public:
        void setStategy(BattleStrategy* s);
        void executeStrategy();
        void chooseBestStrategy();
        ~TacticalCommand();

};

#endif 