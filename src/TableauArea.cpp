
#include "TableauArea.h"




void TableauArea::displayTableau() {
    int maximumLengthOfPile = -1;
    for (int i = 0; i < 7;i++) {
        maximumLengthOfPile = max(getPiles()[i].getHead(),maximumLengthOfPile);
    }
    if (maximumLengthOfPile == -1) {
        gameOver = true;
        return;
    }

    for (int i = 0; i <= maximumLengthOfPile ; i++) {

        for (int j = 0; j < 7; j++) {
            Card currentCard = getPiles()[j].getCards()[i];
            cout << currentCard.toString() << "   ";

        }

        cout << endl;


    }


}

void TableauArea::generatePiles(string *lines,int length) {
    int pileIndex = 0;
    int pileCounter = 0;


    for(int i {length - 1} ; i >=24; i--) {
        string suit = lines[i].substr(0,1);
        int number = stoi(lines[i].substr(1,2));

        Card card;
        if (i == 51 || i == 44 || i == 38 || i == 33 || i == 29 || i == 26 || i == 24){
            card = Card(true,number,suit);
        }
        else {

            card = Card(false,number,suit);



        }
        this->getPiles()[pileIndex].addCard(card);
        pileIndex++;
        if (pileIndex == 7) {
            pileCounter++;
            pileIndex = pileCounter;
        }





    }



}

 Pile *TableauArea::getPiles() {
    return piles;
}

void TableauArea::moveFromPileToPile(int fromPile, int howManyCards, int toPile) {

    int headOfFromPile = piles[fromPile].getHead() - howManyCards;
    int headOfToPile = piles[toPile].getHead();

    if (howManyCards > piles[fromPile].getHead()) {
        cout << "Invalid Move!" << endl << endl;
        return;
    }

    if (piles[fromPile].getHead() == -1) {
        cout << "Invalid Move!" << endl << endl;
        return;
    }

    Card cardToMove = piles[fromPile].getCards()[headOfFromPile];

    if (!(cardToMove.isOpened())) {
        cout << "Invalid Move!" << endl << endl;
        return;
    }


    // if pile is empty
    if (piles[toPile].getHead() == -1 && howManyCards == 0) {
        if (cardToMove.getNumber() == 13) {
            piles[fromPile].removeCard();

            piles[toPile].addCard(cardToMove);

            return;
        }
        else {
            cout << "Invalid Move!" << endl << endl;
            return;
        }
    }

    Card cardToCheck = piles[toPile].getCards()[headOfToPile];

    if (!(cardToMove.isOpened()) || !(cardToCheck.isOpened())){
        cout << "Invalid Move!" << endl << endl;
        return;
    }



    if (isMoveOperationValid(cardToMove.getSuit(),
                             cardToCheck.getSuit(),
                             cardToMove.getNumber(),
                             cardToCheck.getNumber())) {

        // if only 1 transfer
        if (howManyCards == 0) {


            piles[toPile].addCard(cardToMove);


            piles[fromPile].removeCard();
            return;
        }

        else {
            while (howManyCards >= 0) {



                // if target pile is empty
                if (headOfToPile == -1) {
                    // if cardToMove is King, then move
                    if (cardToMove.getNumber() == 13) {

                        piles[toPile].addCard(cardToMove);

                        piles[fromPile].removeCardByIndex(headOfFromPile);

                        howManyCards--;
                        continue;
                    }
                    else {
                        cout << "Invalid Move!" << endl << endl;
                        break;
                    }

                }

                Card tempCard = piles[fromPile].getCards()[headOfFromPile];

                if (!(tempCard.isOpened())) {
                    cout << "Invalid Move!" << endl << endl;
                    return;
                }

                piles[fromPile].removeCardByIndex(headOfFromPile);
                piles[toPile].addCard(tempCard);
                headOfFromPile++;
                howManyCards--;
            }
        }

    }
    else {
        cout << "Invalid Move!" << endl << endl;
    }

//    while (howManyCards >= 0) {
//
//        Card cardToMove = piles[fromPile].getCards()[headOfFromPile];
//
//        // check if move is valid
//        Card cardToCheck = piles[toPile].getCards()[headOfToPile];
//        if (isMoveOperationValid(cardToMove.getSuit(),
//             cardToCheck.getSuit(),
//             cardToMove.getNumber(),
//             cardToCheck.getNumber())) {
//            piles[fromPile].removeCard();
//
//            piles[toPile].addCard(cardToMove);
//
//            howManyCards--;
//
//        }
//        else {
//            cout << "Invalid move" << endl;
//            break;
//        }
//
//    }

}

bool TableauArea::isMoveOperationValid(string fromSuit,string toSuit,int fromNumber, int toNumber) {
    if ((fromSuit == "S" && toSuit == "D" ||
        fromSuit == "H" && toSuit == "C" ||
        fromSuit == "H" && toSuit == "S" ||
        fromSuit == "C" && toSuit == "D" ||

        fromSuit == "D" && toSuit == "S" ||
        fromSuit == "C" && toSuit == "H" ||
        fromSuit == "S" && toSuit == "H" ||
        fromSuit == "D" && toSuit == "C" ) &&
        toNumber - fromNumber == 1) {
        return true;


    }
    return false;
}

bool TableauArea::openLastCard(int pileNumber) {

    if (piles[pileNumber].getCards()[piles[pileNumber].getHead()].isOpened()) {
        return false;
    }
    piles[pileNumber].getCards()[piles[pileNumber].getHead()].setOpened(true);
    return true;
}

bool TableauArea::addToPile(Card card,int pileNumber) {

    string fromSuit = card.getSuit();
    if (piles[pileNumber].getHead() == -1 && card.getNumber() == 13) {
        piles[pileNumber].addCard(card);
        return true;
    }
    else if (piles[pileNumber].getHead() == -1 && card.getNumber() != 13) {
        cout << "Invalid Move!" << endl << endl;
        return false;
    }

    string toSuit = piles[pileNumber].getCards()[piles[pileNumber].getHead()].getSuit();
    int fromNumber = card.getNumber();
    int toNumber = piles[pileNumber].getCards()[piles[pileNumber].getHead()].getNumber();
    if ( isMoveOperationValid(fromSuit,toSuit,fromNumber,toNumber) ) {
        piles[pileNumber].addCard(card);
        return true;
    }
    else {
        cout << "Invalid Move!" << endl << endl;
        return false;
    }

}

bool TableauArea::isGameOver() const {
    return gameOver;
}

void TableauArea::setGameOver(bool gameOver) {
    TableauArea::gameOver = gameOver;
}





