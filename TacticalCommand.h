#ifndef TACTICALCOMMAND_H
#define TACTICALCOMMAND_H

#include "BattleStrategy.h"
#include "WarArchives.h"

#include <iostream>

using namespace std;

class TacticalCommand{

    protected:
        BattleStrategy* strategy;
        WarArchives* archive;

    public:
        TacticalCommand(WarArchives&);
        void setStategy(BattleStrategy* s);
        void executeStrategy();
        void chooseBestStrategy(string);
        ~TacticalCommand();

};

#endif 