//
// Created by Braiden Hook on 9/25/21.
//

#include "Word.h"

Word::Word() {

}

Word::Word(const DSString& indexedWord, const DSString& pageNum) {
    this->indexedWord = indexedWord;
    this->pageNum.push_back(pageNum);
}

void Word::addPageNum(const DSString& num){
    this->pageNum.push_back(num);
    this->pageNum.sort();
}

DSVector<DSString> Word::getPageNum() {
    return this->pageNum;
}

DSString Word::getIndexedWord() {
    return this->indexedWord;
}
