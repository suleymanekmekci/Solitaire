

#ifndef ASSIGNMENT1_WASTE_H
#define ASSIGNMENT1_WASTE_H


#include "Card.h"

class Waste {
private:
    int head{-1};
    int currentNumberOfCardsOnWaste = 0;
    Card cards[24] = {Card(false,00,"n"),
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
    int getCurrentNumberOfCardsOnWaste() const;

    void setCurrentNumberOfCardsOnWaste(int currentNumberOfCardsOnWaste);

    int getHead() const;

    void setHead(int head);

    void display();
    void remove();
    void add(Card cards);
    Card getLastCard();
};


#endif //ASSIGNMENT1_WASTE_H
