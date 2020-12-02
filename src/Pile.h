

#ifndef ASSIGNMENT1_PILE_H
#define ASSIGNMENT1_PILE_H


#include "Card.h"

class Pile {
private:
    int head {-1};
    Card cards[19] = {Card(false,00,"n"),
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
    Pile();
    Card *getCards();
    void addCard(Card card);
    void removeCard();

    int getHead() const;

    void removeCardByIndex(int i);
};


#endif //ASSIGNMENT1_PILE_H
