//
// Created by Braiden Hook on 9/25/21.
//

#ifndef INC_21F_PA02_WORD_H
#define INC_21F_PA02_WORD_H


#include "DSString.h"
#include "DSVector.h"

class Word {

public:
    Word ();
    Word (const DSString&, const DSString&);
    void addPageNum (const DSString&);
    DSVector <DSString> getPageNum ();
    DSString getIndexedWord ();

private:
    DSString indexedWord;
    DSVector <DSString> pageNum;

};


#endif //INC_21F_PA02_WORD_H
