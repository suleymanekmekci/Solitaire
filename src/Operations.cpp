
#include <sstream>
#include "Operations.h"
#include "ReadFromFile.h"




void Operations::startGame(string commandsName,string deckName) {
    setGameBoard(deckName);

    ReadFromFile commandFile;
    int length = commandFile.findNumberOfLines(commandsName);
    auto lines = commandFile.readLines(commandsName,length);



    bool isStockFinished = false;
    bool error = false;
    for (int i = 0; i < length ; i++) {


        istringstream iss {lines[i]} ;
        string temp1, temp2, temp3, temp4, temp5;
        iss >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;


        string stockString = "@@@ ";
        if (isStockFinished) {
            stockString = "___ ";
        }

        cout << stockString;
        waste.display();
        cout << "         ";
        cout << foundationArea.toString() << endl << endl;
        table.displayTableau();
        cout << endl;

        if (table.isGameOver()) {
            cout << "You Win!" << endl << endl;
            cout << "Game Over!" << endl;
            return;
        }
        cout << lines[i] << endl << endl;




        if (temp1 == "exit") {
            cout << "****************************************" << endl << endl;
            cout << "Game Over!" << endl;
            return;
        }

        if (temp1 == "move") {
            if (temp2 == "to") {
                if (temp4 == "waste") {

                    // move from waste to foundation
                    Card card = waste.getLastCard();

                    bool statement = foundationArea.addToFoundation(card);
                    if (statement) {
                        waste.remove();
                    }
                    else {
                        error = true;
                    }


                }
                else if (temp4 == "pile") {
                    // move from pile to foundation
                    int pileNumber = stoi(temp5);


                    if (table.getPiles()[pileNumber].getHead() < 0) {
                        cout << "Invalid Move!" << endl << endl;
                    }

                    else {

                        Card card = table.getPiles()[pileNumber].getCards()[table.getPiles()[pileNumber].getHead()];
                        if (!(card.isOpened())) {
                            error = true;

                        }
                        else {
                            bool statement = foundationArea.addToFoundation(card);
                            if (statement) {
                                table.getPiles()[pileNumber].removeCard();

                            }
                            else {
                                error = true;

                            }
                        }


                    }



                }
            }
            else if (temp2 == "pile") {
                // move pile to pile
                int fromPile = stoi(temp3);
                int howManyCards = stoi(temp4);
                int toPile = stoi(temp5);


                table.moveFromPileToPile(fromPile,howManyCards,toPile);



            }
            else if (temp2 == "waste") {
                // move waste to pile
                Card card = waste.getLastCard();
                if (card.getSuit() == "n") {
                    error = true;
                }
                else {
                    int toPile = stoi(temp3);

                    bool condition = table.addToPile(card,toPile);

                    if (condition) {
                        waste.remove();
                    }

                }
            }
            else if (temp2 == "foundation") {
                int fromFoundation = stoi(temp3);
                int toPile = stoi(temp4);
                Card card = foundationArea.getFoundations()[fromFoundation].getLastCard();
                bool condition = table.addToPile(card,toPile);

                // if card which will be moved from foundation to pile is convenient for pile
                // remove it from foundation
                if (condition) {
                    foundationArea.removeFromFoundation(fromFoundation);
                }


            }

        }
        else if (temp1 == "open") {
            if (temp2 == "from") {
                //transport cards from stock to waste
                if (stock.getHead() < 0) {

                    // transfer all to the stock (if stock head < 0)
                    int numberOfElementsInWaste = waste.getHead();
                    if (numberOfElementsInWaste == -1) {
                        cout << "Invalid Move!" << endl << endl;

                    }
                    else {
                        while (numberOfElementsInWaste >= 0) {
                            Card tempCard = waste.getLastCard();
                            stock.addCard(tempCard);
                            waste.remove();

                            numberOfElementsInWaste--;
                        }
                        isStockFinished = false;
                    }

                }

                else {
                    int condition;
                    if (stock.getHead() < 2) {
                        condition = stock.getHead() + 1;
                    }
                    else {
                        condition = 3;
                    }

                    int k = 0;
                    waste.setCurrentNumberOfCardsOnWaste(condition);
                    while (k < condition) {
                        Card temp = stock.getLastCard();
                        temp.setOpened(true);
                        if (temp.getSuit() == "n") {
                            break;
                        }
                        waste.add(temp);
                        stock.removeCard();
                        k++;
                        }


                }

                if (stock.getHead() < 0) {
                    isStockFinished = true;
                }




            }


            else {
                bool condition = table.openLastCard(std::stoi(temp2));

                if (!(condition)) {
                    cout << "Invalid Move!" << endl << endl;
                }

            }
        }
        if (error) {
            cout << "Invalid Move!" << endl << endl;
            error = false;
        }

        cout << "****************************************" << endl << endl;
//        string stockString = "@@@ ";
//        if (isStockFinished) {
//            stockString = "___ ";
//        }
//
//        cout << stockString;
//        waste.display();
//        cout << "         ";
//        cout << foundationArea.toString() << endl << endl;
//        table.displayTableau();
//        cout << endl;
//
//        if (table.isGameOver()) {
//            cout << "You Win!" << endl << endl;
//            cout << "Game Over!" << endl;
//            return;
//        }
//        cout << lines[i] << endl << endl;
//
//        if (error) {
//            cout << "Invalid Move!" << endl << endl;
//        }
//
//        cout << "****************************************" << endl << endl;

    }
    string stockString = "@@@ ";
    if (isStockFinished) {
        stockString = "___ ";
    }

    cout << stockString;
    waste.display();

    cout << "         ";
    cout << foundationArea.toString() << endl << endl;
    table.displayTableau();
    cout << endl << endl;
    cout << "****************************************" << endl << endl;

    if (table.isGameOver()) {
        cout << "You Win!" << endl << endl;


    }

    cout << "Game Over!" << endl;






}

void Operations::setGameBoard(string deckName) {
    ReadFromFile commandFile;

    int length = commandFile.findNumberOfLines(deckName);
    auto lines = commandFile.readLines(deckName,length);


    table.generatePiles(lines,length);
    stock.generateStock(lines,length);


}
