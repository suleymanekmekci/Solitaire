

#ifndef ASSIGNMENT1_FOUNDATION_H
#define ASSIGNMENT1_FOUNDATION_H


#include "Card.h"

class Foundation {
private:
    int head {-1};
    Card cards[13] = {Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n"),
                      Card(false,00,"n")};
public:
    bool addCard(Card card);
    void removeCard();
    Card getLastCard();
    bool isInsertionValid(string suitToAdd,int numberToAdd);

};


#endif //ASSIGNMENT1_FOUNDATION_H
