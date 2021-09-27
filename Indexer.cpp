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
    DSString extendedNested;
    DSString extendedWord;
    int checkW = 0;
    int checkN = 0;
    int startW = 0;
    int startN = 0;
    int countW = 0;
    int countN = 0;
    char char1[85];
    char pageNum[85];
    map <DSString, DSVector <Word>> mIndex;
    DSString pageNumObj;
    DSVector<DSString> pageNumV;
    DSVector<DSString> wordV;
   // DSVector<Word> wordIndex;
   // DSVector<StoredIndex> index;
    DSVector<DSString> charIV;
    int count = 0;

    ifstream inFile(input);

    while (!inFile.eof()) {

        inFile.getline(char1, 85, '\n');
        DSString line = char1;
        int count = 0;

        if (line[0] == '<') {
            for (int i = 1; i < line.getLength() - 1; i++) {
                //for (int i = 1; i < strlen(char1) - 1; i++)
                //pageNum[i - 1] = char1[i];
                count ++;
            }
            pageNumObj = line.substring(1, count);
            //pageNum[strlen(char1) - 2] = '\0';
            //pageNumObj = pageNum;
            //if (pageNumObj == "-1") { break; }
            //if (count != 0)
                //index.push_back(StoredIndex(pageNumObj, wordIndex));
            //count++;
            //pageNumV.push_back(pageNumObj);
        }
        else{
            //DSString pageNumObj(pageNum);
//            for (int i = 0; i < strlen(char1); i++){
            for (int i = 0; i < line.getLength(); i++){

                //if (char1[i] == '[')
                    //i++;
                //if ((line[i] == '[') || (countW != 0)){
                //if ((char1[i] == '[') || (countW != 0)){
                if (line[i] == '['){
                    //char word1[85];
                    checkW = 1;
                    countW = i;
                    startW = i;
                    DSString wordObjW;
                    //if (char1[i] == '[')
                    if (line[i] == '[')
                        i++;
                    //i++;
                    //for (;i < strlen(char1); i++){
                    for (;i < line.getLength(); i++){
                        //if ((line[i] == '[') || (countN != 0)){
                        if (line[i] == '['){
                            //char nested1[85];
                            checkN = 1;
                            countN = i;
                            startN = i;
                            DSString wordObjN;
                            if (line[i] == '[')
                                i++;
                            //if (countN != 0)
                                //wordObjN = extendedNested;
                            //extendedNested = "";
                            //i++;
                            //for (; i < strlen(char1); i++){
                            for (; i < line.getLength(); i++){
                                //if (char1[i] == ']'){
                                if (line[i] == ']'){
                                    //obj1(nested1, pageNumObj)
                                    DSString wordN = line.substring(startN, countN);
                                    if (isblank(extendedNested[0])){
                                        wordObjN = wordN;
                                    }
                                    else{
                                        wordObjN = extendedNested + wordN;
                                    }
                                    //wordObjN = extendedNested;
                                    //wordObjN = wordObjN + wordN;
                                    //nested1[countN] = '\0';
                                    //int temp = i;
                                    DSString charI = wordObjN.substring(0, 1);
                                    //char char0[2];
                                    //char0[0] = nested1[0];
                                    //char0[1] = '\0';
                                    if (isalpha(charI[0]))
                                        charI[0] = toupper(charI[0]);
                                    //i = temp;
                                    //DSString charI(char0);
                                    //DSString nested(nested1);
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
                                            //if (nested == mIndex.at(charI).at(j).getIndexedWord()) {
                                            if (wordObjN == mIndex.at(charI).at(j).getIndexedWord()) {
                                                mIndex.at(charI).at(j).addPageNum(pageNumObj);
                                                check = 1;
                                                break;
                                            }
                                        }
                                    }
                                    if (check == 0){
                                        //int check1 = 0;
                                        Word nestedWord(wordObjN, pageNumObj);
                                        //Word nestedWord(nested, pageNumObj);
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

                                    //memset(nested1, 0, strlen(char1));
                                    checkN = 0;
                                    extendedNested = "";
                                    countN = 0;
                                    startN = 0;
                                    //i++;
                                    //j++;
                                    break;
                                }
                                else {
                                    //nested1[countN] = char1[i];
                                    //word1[countW] = char1[i];
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

                        else if (line[i] == ']'){
                            //obj1(nested1, pageNumObj)
                            DSString wordW = line.substring(startN, countN);
                            if (isblank(extendedWord[0])){
                                wordObjW = wordW;
                            }
                            else{
                                wordObjW = extendedNested + wordW;
                            }
                            //DSString wordW = line.substring(startW, countW);
                            //wordObjW = extendedWord + wordW;
                            //nested1[countN] = '\0';
                            //int temp = i;
                            DSString charI = wordObjW.substring(0, 1);
                            //char char0[2];
                            //char0[0] = nested1[0];
                            //char0[1] = '\0';
                            if (isalpha(charI[0]))
                                charI[0] = toupper(charI[0]);

                        /*else if (char1[i] == ']'){

                            word1[countW] = '\0';
                            int temp = i;
                            char char0[2];
                            char0[0] = word1[0];
                            char0[1] = '\0';
                            if (isalpha(char0[0]))
                                char0[0] = toupper(char0[0]);
                            //i = temp;
                            DSString charI(char0);
                            DSString word(word1);*/
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
                                    //if (word == mIndex.at(charI).at(j).getIndexedWord()){
                                    if (wordObjW == mIndex.at(charI).at(j).getIndexedWord()) {
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
                                //Word newWord(word, pageNumObj);
                                Word newWord(wordObjW, pageNumObj);
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
                                    /*else{
                                    DSVector<Word> wordIndex;
                                    wordIndex.push_back(newWord);
                                    mIndex.emplace(charI, wordIndex);
                                    charIV.push_back(charI);
                                    //StoredIndex indexS(charI, wordIndex);
                                    //index.push_back(indexS);
                                }*/
                                    else{
                                        DSVector<Word> wordIndex;
                                        wordIndex.push_back(newWord);
                                        mIndex.emplace(charI, wordIndex);
                                        charIV.push_back(charI);
                                        //StoredIndex indexS(charI, wordIndex);
                                        //index.push_back(indexS);
                                    }
                            }
                            //memset(word1, 0, strlen(char1));
                            checkW = 0;
                            extendedWord = "";
                            countW = 0;
                            startW = 0;
                            //countW = 0;
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
                            //word1[countW] = char1[i];
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
        if (checkW == 1){
            extendedWord = line.substring(startW, countW);
        }
        if (checkN == 1){
            extendedNested = line.substring(startN, countN);
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
