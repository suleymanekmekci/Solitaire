
#include "ReadFromFile.h"
#include "Operations.h"
#include <cstdio>
#include <iostream>

using namespace std;
int main(int argc, char** argv) {

    string deckName {argv[1]};
    string commandsName = {argv[2]};

    string outputName = string(argv[3]);
    freopen(outputName.c_str(),"w",stdout);
    cout<< endl;
    Operations operations;
    operations.startGame(commandsName , deckName);



    return 0;
}
