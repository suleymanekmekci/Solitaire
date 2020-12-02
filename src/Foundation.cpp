

#include "Foundation.h"

bool Foundation::addCard(Card card) {
    if (head == -1) {
        if (card.getNumber() == 1) {
            head++;
            cards[head] = card;
            return true;
        }

        else {

            return false;
        }
    }

    else {
        if (isInsertionValid(card.getSuit(),card.getNumber())) {
            head++;
            cards[head] = card;
            return true;
        }
        else {
            return false;
        }

    }

}

void Foundation::removeCard() {
    cards[head].setSuit("n");
    head--;
}

Card Foundation::getLastCard() {
    if (head == -1) {
        return Card(false,0,"n");
    }
    return cards[head];
}

bool Foundation::isInsertionValid(string suitToAdd,int numberToAdd) {
    int lastNumber = cards[head].getNumber();
    string lastSuit = cards[head].getSuit();
    if (suitToAdd == lastSuit && lastNumber + 1 == numberToAdd) {
        return true;
    }
    return false;
}
