#ifndef ASSIGNMENT1_CARD_H
#define ASSIGNMENT1_CARD_H


#include <iostream>
using namespace std;
class Card {
public:


    Card();

    Card(bool opened,  int number, string suit);

    int getNumber() const;

    void setNumber(int number);


    bool isOpened() const;

    void setOpened(bool opened);

    const string &getSuit() const;

    void setSuit(string suit);



    string toString();


private:
    bool opened;
    int number;
    string suit;

};


#endif //ASSIGNMENT1_CARD_H
