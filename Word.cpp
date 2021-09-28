//
// Created by Braiden Hook on 9/25/21.
//

#include "Word.h"

Word::Word() {

}

Word::Word(const DSString& indexedWord, const DSString& pageNum, const DSString& index) {
    this->indexedWord = indexedWord;
    this->pageNum = pageNum;
    this->index = index;
}

DSString Word::getIndexedWord() {
    return this->indexedWord;
}

DSString Word::getPageNum() {
    return this->pageNum;
}

DSString Word::getIndex() {
    return this->index;
}
