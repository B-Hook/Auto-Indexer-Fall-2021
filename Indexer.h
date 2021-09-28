//
// Created by Braiden Hook on 9/25/21.
//

#ifndef INC_21F_PA02_INDEXER_H
#define INC_21F_PA02_INDEXER_H
#include <fstream>
#include "DSString.h"
#include "DSVector.h"
#include "PrintToFile.h"
#include "Word.h"
using namespace std;

class Indexer {

public:
    Indexer(char*, char*);
    void readInFile (char*);
    void endWord(int&, int&, DSString&);

private:
    DSVector<Word> wordObjs;
    DSVector<DSString> indexCategories;
    DSVector<DSString> words;
    DSString pageNumObj;
};


#endif //INC_21F_PA02_INDEXER_H
