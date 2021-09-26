//
// Created by Braiden Hook on 9/25/21.
//

#ifndef INC_21F_PA02_STOREDINDEX_H
#define INC_21F_PA02_STOREDINDEX_H


#include "Word.h"
#include "DSString.h"
#include "DSVector.h"

class StoredIndex {

public:
    StoredIndex();
    StoredIndex(DSString, DSVector<Word>);
    void addToWordV(Word);
    DSString getCharIndex();
    DSVector<Word> getWordV();

private:
    DSString charIndex;
    DSVector<Word> wordV;

};


#endif //INC_21F_PA02_STOREDINDEX_H
