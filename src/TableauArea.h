

#ifndef ASSIGNMENT1_TABLEAUAREA_H
#define ASSIGNMENT1_TABLEAUAREA_H

#include <iostream>

#include "Pile.h"

using namespace std;
class TableauArea {
private:
    bool gameOver = false;
    Pile piles[7] {Pile(),
                   Pile(),
                   Pile(),
                   Pile(),
                   Pile(),
                   Pile(),
                   Pile()};

public:
    void generatePiles(string lines[],int length);
    void displayTableau();

    bool isGameOver() const;

    void setGameOver(bool gameOver);

    Pile *getPiles();
    void moveFromPileToPile(int fromPile, int howManyCards, int toPile);
    bool isMoveOperationValid(string fromSuit, string toSuit,int fromNumber, int toNumber);
    bool openLastCard(int pileNumber);
    bool addToPile(Card card,int pileNumber);

};



#endif //ASSIGNMENT1_TABLEAUAREA_H
