//
// Created by Braiden Hook on 9/25/21.
//
#include "Indexer.h"
Indexer::Indexer(char *inputFile, char *outputFile) {
    readInFile(inputFile);
}
void Indexer::readInFile(char *input) {
    //char extendedWord[85];
    //char extendedNested[85];
    int countW = 0;
    int countN = 0;
    char char1[85];
    char pageNum[85];
    map<DSString, DSVector<Word>> mIndex;
    //DSString pageNumObj;
    DSVector<DSString> pageNumV;
    DSVector<DSString> wordV;
    // DSVector<Word> wordIndex;
    // DSVector<StoredIndex> index;
    DSVector<DSString> charIV;
    int count = 0;

    ifstream inFile(input);
    while (!inFile.eof()) {
        inFile.getline(char1, 85, '\n');
        if (char1[0] == '<') {
            for (int i = 1; i < strlen(char1) - 1; i++)
                pageNum[i - 1] = char1[i];
            pageNum[strlen(char1) - 2] = '\0';
        } else {
            DSString pageNumObj(pageNum);
            for (int i = 0; i < strlen(char1); i++) {
                if ((char1[i] == '[') || (countW != 0)) {
                    char word1[85];
                    if (char1[i] == '[')
                        i++;
                    for (; i < strlen(char1); i++) {
                        if ((char1[i] == '[') || (countN != 0)) {
                            char nested1[85];
                            if (char1[i] == '[')
                                i++;
                            for (; i < strlen(char1); i++) {
                                if (char1[i] == ']') {
                                    nested1[countN] = '\0';
                                    char char0[2];
                                    char0[0] = nested1[0];
                                    char0[1] = '\0';
                                    if (isalpha(char0[0]))
                                        char0[0] = toupper(char0[0]);
                                    DSString charI(char0);
                                    DSString nested(nested1);
                                    int check = 0;
                                    if ((mIndex.count(charI) > 0)) {
                                        for (int j = 0; j < mIndex.at(charI).getSize(); j++) {
                                            if (nested == mIndex.at(charI).at(j).getIndexedWord()) {
                                                mIndex.at(charI).at(j).addPageNum(pageNumObj);
                                                check = 1;
                                                break;
                                            }
                                        }
                                    }
                                    if (check == 0) {
                                        Word nestedWord(nested, pageNumObj);
                                        if (mIndex.count(charI) > 0) {
                                            mIndex.at(charI).push_back(nestedWord);
                                        }
                                        else {
                                            DSVector<Word> nestedIndex;
                                            nestedIndex.push_back(nestedWord);
                                            mIndex.emplace(charI, nestedIndex);
                                            charIV.push_back(charI);
                                        }
                                    }

                                    memset(nested1, 0, strlen(char1));
                                    countN = 0;
                                    break;
                                } else {
                                    nested1[countN] = char1[i];
                                    word1[countW] = char1[i];
                                    countN++;
                                    countW++;
                                }
                            }
                        }
                        else if (char1[i] == ']') {

                            word1[countW] = '\0';
                            char char0[2];
                            char0[0] = word1[0];
                            char0[1] = '\0';
                            if (isalpha(char0[0]))
                                char0[0] = toupper(char0[0]);
                            DSString charI(char0);
                            DSString word(word1);
                            int check = 0;
                            if ((mIndex.count(charI) > 0)) {
                                for (int j = 0; j < mIndex.at(charI).getSize(); j++) {
                                    if (word == mIndex.at(charI).at(j).getIndexedWord()) {
                                        mIndex.at(charI).at(j).addPageNum(pageNumObj);
                                        check = 1;
                                        break;
                                    }
                                }
                            }
                            if (check == 0) {
                                Word newWord(word, pageNumObj);
                                if (mIndex.count(charI) > 0) {
                                    mIndex.at(charI).push_back(newWord);
                                }
                                else {
                                    DSVector<Word> wordIndex;
                                    wordIndex.push_back(newWord);
                                    mIndex.emplace(charI, wordIndex);
                                    charIV.push_back(charI);
                                }
                            }
                            memset(word1, 0, strlen(char1));
                            countW = 0;
                            break;
                        }
                        else {
                            word1[countW] = char1[i];
                            countW++;
                        }
                    }
                }
            }
        }


    }
    for (int i = 0; i < charIV.getSize(); i++) {
        for (int j = 0; j < mIndex.at(charIV.at(i)).getSize(); j++) {
            for (int k = 0; k < mIndex.at(charIV.at(i)).at(j).getPageNum().getSize(); k++) {
                cout << mIndex.at(charIV.at(i)).at(j).getIndexedWord() << " : " <<
                     mIndex.at(charIV.at(i)).at(j).getPageNum().at(k) << endl;
            }
        }
    }
    for (int i = 0; i < pageNumV.getSize(); i++)
        cout << pageNumV.at(i) << endl;
}