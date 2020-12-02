

#ifndef ASSIGNMENT1_STOCK_H
#define ASSIGNMENT1_STOCK_H


#include "Card.h"

class Stock {
private:

    int head{-1};
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
    Card *getCards();
    void generateStock(string lines[],int length);
    void addCard(Card card);
    void removeCard();
    Card getLastCard();

    int getHead() const;

    void setHead(int head);

};


#endif //ASSIGNMENT1_STOCK_H
