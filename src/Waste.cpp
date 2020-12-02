

#include "Waste.h"





void Waste::add(Card card) {
    head++;
    cards[head] = card;
}

void Waste::remove() {
    if (head < 0) {
        cout << "Invalid Move!" << endl << endl;
        return;
    }
    cards[head].setSuit("n");
    head--;
    currentNumberOfCardsOnWaste--;
    if (currentNumberOfCardsOnWaste == 0) {
        currentNumberOfCardsOnWaste = 1;
    }


}

void Waste::display() {
    int temp = currentNumberOfCardsOnWaste;
    int tempHead = head - temp + 1;

    if (head < 0) {
        cout << "___ ___ ___";
        return;
    }


    while (temp > 0) {
        if (currentNumberOfCardsOnWaste == 3 && temp == 1) {
            cout << cards[tempHead].toString();

        }
        else {
            cout << cards[tempHead].toString() << " ";

        }
        tempHead++;
        temp--;
    }
    if (currentNumberOfCardsOnWaste == 2) {
        cout << "___";
    }
    else if (currentNumberOfCardsOnWaste == 1) {
        cout << "___ ___";
    }
    else if (currentNumberOfCardsOnWaste == 0){
        cout << "___ ___ ___";
    }

}

int Waste::getCurrentNumberOfCardsOnWaste() const {
    return currentNumberOfCardsOnWaste;
}

void Waste::setCurrentNumberOfCardsOnWaste(int currentNumberOfCardsOnWaste) {
    Waste::currentNumberOfCardsOnWaste = currentNumberOfCardsOnWaste;
}

Card Waste::getLastCard() {
    if (head < 0) {

        return Card(false,0,"n");
    }
    return cards[head];
}

int Waste::getHead() const {
    return head;
}

void Waste::setHead(int head) {
    Waste::head = head;
}
