//
// Created by Braiden Hook on 9/25/21.
//
#include "Indexer.h"
Indexer::Indexer(char *inputFile, char *outputFile) {
    readInFile(inputFile);
}
void Indexer::readInFile(char *input) {

    int countW = 0;
    int countN = 0;
    //char char1[85];
    //char pageNum[85];
    DSString pageNumObj;
    DSString pageNumBuffer;
    DSVector<DSString> pageNumV;
    ifstream inFile(input);
    char temp[85];
    inFile.getline(temp, 85, '\n');
    DSString inputString (temp);
    while (!inFile.eof()) {
        char buffer[85];
        inFile.getline(buffer, 85, '\n');
        inputString = inputString + buffer;
    }

    for (int i = 0; i < inputString.getLength(); i++){
        //inFile.getline(char1, 85, '\n');
        if (inputString[i] == '<') {
            i++;
            int start = i;
            int countPageNum = 0;
            while (inputString[i] != '>'){
                countPageNum++;
                i++;
            }
            pageNumBuffer = inputString.substring(start, countPageNum);
            pageNumObj = pageNumBuffer; //TODO:: Make Object
            if (pageNumObj == "-1")
                break;
            i++;
        }
        else if (inputString [i] == '['){
            int check = 0;
            for (; i < inputString.getLength(); i++){

                if (inputString[i] == '['){
                    //char word1[85];
                    int startL1 = i;
                    countW++;
                    //DSString word1;
                    i++;
                    for (;i < inputString.getLength(); i++){
                        if ((inputString[i] != '[') && (inputString[i] != ']')){
                            //word1[countW] = [i];
                            countW++;
                            //i++;
                        }

                        else if (inputString[i] == ']'){
                            countW++;
                            DSString wordBuffer1(inputString.substring(startL1, countW));
                            char temp[wordBuffer1.getLength()];
                            int tempCount = 0;
                            for (int j = 0; j < wordBuffer1.getLength(); j ++){
                                if((wordBuffer1[j] != '[') && wordBuffer1[j] != ']'){
                                    temp[tempCount] = wordBuffer1[j];
                                    tempCount++;
                                }
                            }
                            temp[tempCount] = '\0';
                            DSString wordL1(temp);

                            DSString indexL1(wordL1.substring(0, 1));

                            //word1[countW] = '\0';
                            cout << wordL1 << " : " << pageNumObj << endl;
                            //memset(word1, 0, strlen(char1));
                            //obj1(word1, pageNumObj)
                            countW = 0;
                            //i++;
                            check = 1;
                            break;
                        }
                        else if (inputString[i] == '['){
                            //char nested1[85];
                            int startL2 = i;
                            countW++;
                            countN++;
                            i++;
                            for (; i < inputString.getLength(); i++){
                                if(inputString[i] != ']'){
                                    //nested1[countN] = char1[i];
                                    //word1[countW] = char1[i];
                                    countN++;
                                    countW++;
                                    //i++;
                                    //j++;
                                }
                                else if (inputString[i] == ']'){
                                    //obj1(nested1, pageNumObj)
                                    countN++;
                                    DSString wordBuffer2(inputString.substring(startL2, countN));
                                    char temp[wordBuffer2.getLength()];
                                    int tempCount = 0;
                                    for (int j = 0; j < wordBuffer2.getLength(); j ++){
                                        if((wordBuffer2[j] != '[') && wordBuffer2[j] != ']'){
                                            temp[tempCount] = wordBuffer2[j];
                                            tempCount++;
                                        }
                                    }
                                    temp[tempCount] = '\0';
                                    DSString wordL2(temp);
                                    DSString indexL1(wordL2.substring(0, 1));


                                    //countN++;
                                    //DSString wordL2(inputString.substring(startL2, countN));
                                    //nested1[countN] = '\0';
                                    cout << wordL2 << " : " << pageNumObj << endl;
                                    //memset(nested1, 0, strlen(char1));
                                    countN = 0;
                                    countW++;
                                    //i++;
                                    //j++;
                                    break;
                                }

                            }

                        }

                    }

                }
                if (check == 1)
                    break;

            }


        }

    }
    for (int i = 0; i < pageNumV.getSize(); i++)
        cout << pageNumV.at(i) << endl;
}
   /*  ifstream inFile(input);
    char temp[85];
    inFile.getline(temp, 85, '\n');
    DSString inputString (temp);
    DSString pageNum;
    DSString pageNumBuffer;
    DSVector<DSString> nestedWords;
    DSVector<DSString> wordsTotal;
    while (!inFile.eof()) {
        char buffer[85];
        inFile.getline(buffer, 85, '\n');
        inputString = inputString + buffer;
    }

    for (int i = 0; i < inputString.getLength(); i++){

        if (inputString[i] == '<'){
            i++;
            int start = i;
            int countPageNum = 0;
            while (inputString[i] != '>'){
                countPageNum++;
                i++;
            }
            pageNumBuffer = inputString.substring(start, countPageNum);
            pageNum = pageNumBuffer; //TODO:: Make Object
            if (pageNum == "-1")
                break;
            i++;
        }
        else if (inputString[i] == '['){
            i++;
            //DSString wordLevel1;
            int start1 = i;
            int end1 = 0;
            int check = 0;
            while (inputString[i] != ']') {
                end1++;
                if (inputString[i] == '[') {
                    check = 1;
                    DSString wordLevel1A (inputString.substring(start1, end1 - 1));
                    i++;
                    //DSString wordLevel2;
                    int start2 = i;
                    int end2 = 0;
                    while (inputString[i] != ']') {
                        end2++;
                        i++;
                    }
                    i++;
                    DSString wordLevel2 (inputString.substring(start2, end2));
                    wordsTotal.push_back(wordLevel2);
                    if (end2 >1) {
                        DSString wordLevel1B(wordLevel1A + wordLevel2);
                        nestedWords.push_back(wordLevel1B);
                    }
                    else {
                        nestedWords.push_back(wordLevel1A);
                    }
                    start1 = i + 1;
                    end1 = 0;
                }
                i++;
            }
            if (inputString[i] == ']') {
                if (check == 0) {
                    DSString wordLevel1(inputString.substring(start1, end1));
                    wordsTotal.push_back(wordLevel1);
                } else {
                    DSString wordLevel1(nestedWords.at(0));
                    for (int j = 1; j < nestedWords.getSize(); j++) {
                        wordLevel1 = wordLevel1 + nestedWords.at(j);
                    }
                    DSString wordLevel0(inputString.substring(start1, end1));
                    wordLevel0 = wordLevel0 + wordLevel1;
                    wordsTotal.push_back(wordLevel0);
                }
                //if (i >= )
                i++;
            }
        }


    }
    for (int i = 0; i < wordsTotal.getSize(); i++){
        cout << wordsTotal.at(i) << endl;
    }


    //cout << inputString << endl;


}*/




    //char extendedWord[85];
    //char extendedNested[85];
    /*int countW = 0;
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
}*/