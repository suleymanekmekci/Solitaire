

#include "Pile.h"

 Card *Pile::getCards()  {
    return cards;
}

Pile::Pile() {

}

void Pile::addCard(Card card) {
    head++;
    cards[head] = card;

}

void Pile::removeCard() {
    cards[head].setSuit("n");
    head--;

}

int Pile::getHead() const {
    return head;
}

void Pile::removeCardByIndex(int i) {
    head = head - 1;
    cards[i].setSuit("n");
}
