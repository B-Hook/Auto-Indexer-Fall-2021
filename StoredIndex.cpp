//
// Created by Braiden Hook on 9/25/21.
//

#include "StoredIndex.h"

StoredIndex::StoredIndex() {

}

StoredIndex::StoredIndex(DSString charIndex, DSVector<Word> wordV) {
    this->charIndex = charIndex;
    this->wordV = wordV;
}

void StoredIndex::addToWordV(Word passedWord) {
    this->wordV.push_back(passedWord);
    //this->wordV.sort();
}

DSString StoredIndex::getCharIndex() {
    return this->charIndex;
}

DSVector<Word> StoredIndex::getWordV() {
    return this->wordV;
}
