

#include "FoundationArea.h"
/**
 * First foundation (foundations[0]) is for hearts
 * Second foundation (foundations[1]) is for diamonds
 * Third foundation (foundations[2]) is for spades
 * Forth foundation (foundations[3]) is for clubs
 *
 */
Foundation *FoundationArea::getFoundations()  {
    return foundations;
}

bool FoundationArea::addToFoundation(Card card) {
    if (card.getSuit() == "H") {
        if (foundations[0].addCard(card)) {
            return true;
        }
        return false;
    }
    else if (card.getSuit() == "D") {
        if (foundations[1].addCard(card)) {
            return true;
        }
        return false;
    }
    else if (card.getSuit() == "S") {
        if (foundations[2].addCard(card)) {
            return true;
        }
        return false;
    }
    else if (card.getSuit() == "C") {
        if (foundations[3].addCard(card)) {
            return true;
        }
        return false;
    }
    return false;
}

string FoundationArea::toString() {
    string output;
    string firstCardString;
    string secondCardString;
    string thirdCardString;
    string forthCardString;



    if (foundations[0].getLastCard().getSuit() != "n") {
        firstCardString = foundations[0].getLastCard().toString();
    }
    else {
        firstCardString = "___";
    }
    if (foundations[1].getLastCard().getSuit() != "n") {
        secondCardString = foundations[1].getLastCard().toString();
    }
    else {
        secondCardString = "___";
    }
    if (foundations[2].getLastCard().getSuit() != "n") {
        thirdCardString = foundations[2].getLastCard().toString();
    }
    else {
        thirdCardString = "___";
    }
    if (foundations[3].getLastCard().getSuit() != "n") {
        forthCardString = foundations[3].getLastCard().toString();
    }
    else {
        forthCardString = "___";
    }

    output += firstCardString + " " + secondCardString + " " + thirdCardString + " " + forthCardString + " ";

    return output;
}

void FoundationArea::removeFromFoundation(int foundationNumber) {
    if (foundationNumber >= 0 && foundationNumber <= 3) {
        if (foundations[foundationNumber].getLastCard().getSuit() != "n") {
            foundations[foundationNumber].removeCard();

        }
        else {
            cout << "Invalid Move!" << endl << endl;
        }

    }
}
