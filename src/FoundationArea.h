

#ifndef ASSIGNMENT1_FOUNDATIONAREA_H
#define ASSIGNMENT1_FOUNDATIONAREA_H


#include "Foundation.h"
/**
 * First foundation (foundations[0]) is for hearts
 * Second foundation (foundations[1]) is for diamonds
 * Third foundation (foundations[2]) is for spades
 * Forth foundation (foundations[3]) is for clubs
 *
 */
class FoundationArea {
private:
    Foundation foundations[4] = {Foundation(),
                                Foundation(),
                                Foundation(),
                                Foundation()};

public:
    Foundation *getFoundations() ;
    bool addToFoundation(Card card);
    string toString();
    void removeFromFoundation(int foundationNumber);
};


#endif //ASSIGNMENT1_FOUNDATIONAREA_H
