
#ifndef ASSIGNMENT1_OPERATIONS_H
#define ASSIGNMENT1_OPERATIONS_H


#include "TableauArea.h"
#include "Stock.h"
#include "Waste.h"
#include "FoundationArea.h"

class Operations {
private:

    void setGameBoard(string deckName);

public:
    TableauArea table;
    Stock stock;
    Waste waste;
    FoundationArea foundationArea;


    void startGame(string commandsName,string deckName);

};


#endif //ASSIGNMENT1_OPERATIONS_H
