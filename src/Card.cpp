
#include "Card.h"

#include <utility>




const string &Card::getSuit() const {
    return suit;
}

void Card::setSuit(string suit) {
    Card::suit = suit;
}


int Card::getNumber() const {
    return number;
}

void Card::setNumber(int number) {
    Card::number = number;

}




Card::Card() {

}

Card::Card(bool opened,  int number, string suit) : opened(opened), number(number), suit(suit) {}

bool Card::isOpened() const {
    return opened;
}

void Card::setOpened(bool opened) {
    Card::opened = opened;
}

string Card::toString() {
    string output;
    if (getSuit() != "n") {
        if (isOpened()) {
            if (getNumber() > 9) {
                output += getSuit() + to_string(getNumber());
            }
            else {
                output += getSuit() + "0" + to_string(getNumber());
            }
        }
        else {
            return "@@@";
        }
        return output;
    }
    else {
        return "   ";
    }

}

