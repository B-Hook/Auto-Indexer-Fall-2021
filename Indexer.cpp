//
// Created by Braiden Hook on 9/25/21.
//

#include "Indexer.h"

Indexer::Indexer(char *inputFile, char *outputFile) {

    readInFile(inputFile);

}

void Indexer::readInFile(char *input) {

    char extendedWord[85];
    char extendedNested[85];
    int countW = 0;
    int countN = 0;
    char char1[85];
    char pageNum[85];
    map <DSString, DSVector <Word>> mIndex;
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
            //pageNumObj = pageNum;
            //if (pageNumObj == "-1") { break; }
            if (count != 0)
                //index.push_back(StoredIndex(pageNumObj, wordIndex));
            count++;
            //pageNumV.push_back(pageNumObj);
        }
        else{
            DSString pageNumObj(pageNum);
            for (int i = 0; i < strlen(char1); i++){

                //if (char1[i] == '[')
                    //i++;

                if ((char1[i] == '[') || (countW != 0)){
                    char word1[85];
                    if (char1[i] == '[')
                        i++;
                    //i++;
                    for (;i < strlen(char1); i++){
                        if ((char1[i] == '[') || (countN != 0)){
                            char nested1[85];
                            if (char1[i] == '[')
                                i++;
                            //i++;
                            for (; i < strlen(char1); i++){
                                if (char1[i] == ']'){
                                    //obj1(nested1, pageNumObj)
                                    nested1[countN] = '\0';
                                    int temp = i;
                                    char char0[2];
                                    char0[0] = nested1[0];
                                    char0[1] = '\0';
                                    if (isalpha(char0[0]))
                                        char0[0] = toupper(char0[0]);
                                    //i = temp;
                                    DSString charI(char0);
                                    DSString nested(nested1);
                                    //cout << nested1 << endl;
                                    //bool wordExists = false;
                                    //int locationI = 0;
                                    //int locationW = 0;
                                    //int check = 0;
                                    /*for (int j = 0; j < index.getSize(); j++){
                                        for (int k = 0; k < index.at(j).getWordV().getSize(); k++) {
                                            if (nested == index.at(j).getWordV().at(k).getIndexedWord()) {
                                                wordExists = true;
                                                locationI = j;
                                                locationW = k;
                                                check = 1;
                                                break;
                                            }
                                        }
                                        if (check == 1)
                                            break;
                                    }
                                    if (wordExists){
                                        index.at(locationI).getWordV().at(locationW).addPageNum(pageNumObj);
                                    }*/
                                    //i = temp;
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
                                    if (check == 0){
                                        //int check1 = 0;
                                        Word nestedWord(nested, pageNumObj);
                                        /*for (int j = 0; j < index.getSize(); j++){ //check for [A]
                                            if (charI == index.at(j).getCharIndex()){
                                                index.at(j).addToWordV(nestedWord);
                                                check1 = 1;
                                                break;
                                            }
                                        }*/
                                        if (mIndex.count(charI) > 0) {
                                            mIndex.at(charI).push_back(nestedWord);
                                            //index.at(j).addToWordV(newWord);
                                            //check1 = 1;
                                            //break;
                                        }
                                        /*if (check1 != 1){
                                            DSVector<Word> wordIndex;
                                            wordIndex.push_back(nestedWord);
                                            StoredIndex indexS(charI, wordIndex);
                                            index.push_back(indexS);
                                        }
                                    }*/
                                        else{
                                            DSVector<Word> nestedIndex;
                                            nestedIndex.push_back(nestedWord);
                                            mIndex.emplace(charI, nestedIndex);
                                            charIV.push_back(charI);
                                            //StoredIndex indexS(charI, wordIndex);
                                            //index.push_back(indexS);
                                        }
                                    }

                                    memset(nested1, 0, strlen(char1));
                                    countN = 0;
                                    //i++;
                                    //j++;
                                    break;
                                }
                                else {
                                    nested1[countN] = char1[i];
                                    word1[countW] = char1[i];
                                    countN++;
                                    countW++;
                                    //i++;
                                    //j++;
                                }

                            }

                        }
                        /*else if ((char1[i] != '[') && (char1[i] != ']')){
                            word1[countW] = char1[i];
                            countW++;
                            //i++;
                        }*/

                        else if (char1[i] == ']'){

                            word1[countW] = '\0';
                            int temp = i;
                            char char0[2];
                            char0[0] = word1[0];
                            char0[1] = '\0';
                            if (isalpha(char0[0]))
                                char0[0] = toupper(char0[0]);
                            //i = temp;
                            DSString charI(char0);
                            DSString word(word1);
                            //cout << word1 << endl;
                            //bool wordExists = false;
                            //int locationI = 0;
                            //int locationW = 0;
                            //int check = 0;
                            /*for (int j = 0; j < index.getSize(); j++){
                                for (int k = 0; k < index.at(j).getWordV().getSize(); k++) {
                                    if (word == index.at(j).getWordV().at(k).getIndexedWord()) {
                                        //wordExists = true;
                                        locationI = j;
                                        locationW = k;
                                        check = 1;
                                        break;
                                    }
                                }
                                if (check == 1)
                                    break;
                            }*/
                            //if (check == 1){
                            //i = temp;
                            int check = 0;
                            if ((mIndex.count(charI) > 0)){
                                for (int j = 0; j < mIndex.at(charI).getSize(); j++) {
                                    if (word == mIndex.at(charI).at(j).getIndexedWord()){
                                        mIndex.at(charI).at(j).addPageNum(pageNumObj);
                                        check = 1;
                                        break;
                                    }
                                }
                                /*Word newWord(word, pageNumObj);
                                DSVector <DSString> oldPageNum = index.at(locationI).getWordV().at(locationW).getPageNum();
                                for (int j = 0; j < oldPageNum.getSize(); j++ ){
                                    newWord.addPageNum(oldPageNum.at(j));
                                }
                                index.at(locationI).getWordV().remove(locationW);
                                index.at(locationI).addToWordV(newWord);*/
                                //index.at(locationI).getWordV().at(locationW).addPageNum(pageNumObj);
                                //mIndex.at(charI).at(locationI).addPageNum(pageNumObj);
                            }
                            if (check == 0){
                                //int check1 = 0;
                                Word newWord(word, pageNumObj);
                                //for (int j = 0; j < index.getSize(); j++){ //check for [A]
                                //for(int j = 0; j < charIV.getSize(); j++){
                                    //if (charI == index.at(j).getCharIndex()){
                                    if (mIndex.count(charI) > 0) {
                                        mIndex.at(charI).push_back(newWord);
                                        //index.at(j).addToWordV(newWord);
                                        //check1 = 1;
                                        //break;
                                    }
                                //}
                                //if (check1 != 1){
                                    else{
                                    DSVector<Word> wordIndex;
                                    wordIndex.push_back(newWord);
                                    mIndex.emplace(charI, wordIndex);
                                    charIV.push_back(charI);
                                    //StoredIndex indexS(charI, wordIndex);
                                    //index.push_back(indexS);
                                }
                            }
                            memset(word1, 0, strlen(char1));
                            countW = 0;
                            //i++;
                            //j++;
                            break;
                        }












                            /*word1[countW] = '\0';
                            cout << word1 << endl;
                            memset(word1, 0, strlen(char1));
                            //obj1(word1, pageNumObj)
                            countW = 0;
                            //i++;
                            break;
                        }*/
                        else {
                            word1[countW] = char1[i];
                            countW++;
                        }
                            //i++;
                        /*else if ((char1[i] == '[') || (countN != 0)){
                            char nested1[85];
                            i++;
                            for (; i < strlen(char1); i++){
                                if(char1[i] != ']'){
                                    nested1[countN] = char1[i];
                                    word1[countW] = char1[i];
                                    countN++;
                                    countW++;
                                    //i++;
                                    //j++;
                                }
                                else if (char1[i] == ']'){
                                    //obj1(nested1, pageNumObj)
                                    nested1[countN] = '\0';
                                    cout << nested1 << endl;
                                    memset(nested1, 0, strlen(char1));
                                    countN = 0;
                                    //i++;
                                    //j++;
                                    break;
                                }

                            }

                        }*/

                    }

                }



            }




        }




    }
    for(int i = 0; i < charIV.getSize(); i++) {
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
