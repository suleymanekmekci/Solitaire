#include <iostream>
#include <iomanip>
#include <fstream>
#include "ReadFromFile.h"

using namespace std;
ifstream inFile;




string * ReadFromFile::readLines(const string &filename,const int &numberOfLines) {

    auto *myTextArray = new string[numberOfLines];

    string myText;
    ifstream MyReadFile( filename);
    int counter {0};
    while (getline (MyReadFile, myText)) {
        // Output the text from the file

        myTextArray[counter] = myText;

        counter++;
    }

    MyReadFile.close();

    return myTextArray;

}




int ReadFromFile::findNumberOfLines(const string &filename) {
    int counter{0};
    ifstream MyReadFile(filename);

    string myText;
    while (getline (MyReadFile, myText)) {
        counter++;
    }
    MyReadFile.close();
    return counter;

}


