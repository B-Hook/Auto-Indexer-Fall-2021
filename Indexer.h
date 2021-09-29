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
    // Constructor
    Indexer(char*, char*);
    // Reading in the file
    void readInFile (char*);
    // Called when a bracketed word ends
    void endWord(int&, int&, DSString&);
// Private data memebers
private:
    DSVector<Word> wordObjs; // Contains all the read in Word that contains the word, page# and index
    DSVector<DSString> indexCategories; // Contains all indexes
    DSVector<DSString> words; // Contains all words
    DSString pageNumObj; // Contains all page numbers
};


#endif //INC_21F_PA02_INDEXER_H
