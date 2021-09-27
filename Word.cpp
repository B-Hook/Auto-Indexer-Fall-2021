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

/*void Word::addPageNum(const DSString& num){
    this->pageNum.push_back(num);
    this->pageNum.sort();
}*/

DSString Word::getIndexedWord() {
    return this->indexedWord;
}

DSString Word::getPageNum() {
    return this->pageNum;
}

DSString Word::getIndex() {
    return DSString();
}
