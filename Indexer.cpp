//
// Created by Braiden Hook on 9/25/21.
//

#include "Indexer.h"

Indexer::Indexer(char *inputFile, char *outputFile) {

    readInFile(inputFile);

}

void Indexer::readInFile(char *input) {

    char extendedWord[85];
    char extendedNested[85];
    int charCountW = 0;
    int charCountN = 0;
    char char1[85];
    char pageNum[85];
    DSString pageNumObj;
    DSVector<DSString> pageNumV;

    ifstream inFile(input);

    while (!inFile.eof()) {

        inFile.getline(char1, 85, '\n');

        if (char1[0] == '<') {
            for (int i = 1; i < strlen(char1) - 1; i++)
                pageNum[i - 1] = char1[i];
            pageNum[strlen(char1) - 2] = '\0';
            pageNumObj = pageNum;
            pageNumV.push_back(pageNumObj);
        }
    }
    for (int i = 0; i < pageNumV.getSize(); i++)
        cout << pageNumV.at(i) << endl;

}
