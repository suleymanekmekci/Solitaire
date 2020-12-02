

#include "Stock.h"

Card *Stock::getCards() {
    return cards;
}

void Stock::addCard(Card card) {
    head++;
    cards[head] = card;
}

void Stock::removeCard() {
    if (head < 0) {
        cout << "There is no card in stock" << endl;
        return;
    }
    cards[head].setSuit("n");
    head--;
}

void Stock::generateStock(string *lines, int length) {

        for(int i {0} ; i <= 23; i++) {
            string suit = lines[i].substr(0,1);
            int number = stoi(lines[i].substr(1,2));

            Card card = Card(false,number,suit);

            this->addCard(card);
        }
}

Card Stock::getLastCard() {
    if (head < 0) {
        cout << "There is no card in stock" << endl;
        return Card(false,0,"n");
    }
    return cards[head];
}

int Stock::getHead() const {
    return head;
}

void Stock::setHead(int head) {
    Stock::head = head;
}
