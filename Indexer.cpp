//
// Created by Braiden Hook on 9/25/21.
//
#include "Indexer.h"
Indexer::Indexer(char *inputFile, char *outputFile) {
    readInFile(inputFile);
}
void Indexer::readInFile(char *input) {
    DSVector<Word> allWords;
    DSVector<DSString> indexCategories;
    DSVector<DSString> words;
    map<DSString, DSVector<DSString>> indexMap;
    map<DSString, DSVector<DSString>> wordsMap;
    map<DSString, DSVector<DSString>> pageNumMap;
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
                                    if (isalpha(temp[tempCount]))
                                        temp[tempCount] = tolower(temp[tempCount]);
                                    tempCount++;
                                }
                            }
                            temp[tempCount] = '\0';
                            DSString wordL1(temp);

                            /*char indexBuffer[2];
                            indexBuffer[0] = wordL1[0];
                            indexBuffer[0] = toupper(indexBuffer[0]);
                            indexBuffer[1] = '\0';*/


                            //DSString indexL1(indexBuffer);
                            DSString indexL1(wordL1.substring(0, 1));


                            Word completeIndex (wordL1, pageNumObj, indexL1);

                            /*for (int j = 0; j < allWords.getSize(); j++){
                                if((allWords.at(j).getIndexedWord() == wordL1) &&
                                    (allWords.at(j).getPageNum() == pageNumObj)){

                                }
                            }*/

                            allWords.push_back(completeIndex);
                            /*
                            if (indexMap.count(indexL1) == 0) {
                                DSVector <DSString> newWord;
                                newWord.push_back(wordL1);
                                indexMap.emplace(indexL1, newWord);
                            }
                            else {
                                indexMap.at(indexL1).push_back(wordL1);
                            }
                            DSString pageNumB(pageNumObj);

                            if (wordsMap.count(wordL1) == 0) {
                                DSVector <DSString> newPageNum;
                                newPageNum.push_back(pageNumObj);
                                wordsMap.emplace(wordL1, newPageNum);
                            }
                            //else if (wordsMap)
                            else{
                                int check5 = 0;
                                for (int j = 0; j < wordsMap.at(wordL1).getSize(); j++){
                                    if (wordsMap.at(wordL1).at(j) == pageNumObj)
                                        check5 = 1;
                                }
                                if (check5 == 0)
                                    wordsMap.at(wordL1).push_back(pageNumObj);
                            }
                            */
                            int check0 = 0;
                            for (int j = 0; j < indexCategories.getSize(); j++){
                                if (indexL1 == indexCategories.at(j))
                                    check0 = 1;
                            }
                            if (check0 == 0) {
                                indexCategories.push_back(indexL1);
                                indexCategories.sort();
                            }

                            int check1 = 0;
                            for (int j = 0; j < words.getSize(); j++){
                                if (wordL1 == words.at(j))
                                    check1 = 1;
                            }
                            if (check1 == 0) {
                                words.push_back(wordL1);
                                words.sort();
                            }
                            //word1[countW] = '\0';
                            cout << wordL1 << " : " << pageNumObj << " : " << indexL1 << endl;
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
                                            if (isalpha(temp[tempCount]))
                                                temp[tempCount] = tolower(temp[tempCount]);
                                            tempCount++;
                                        }
                                    }
                                    temp[tempCount] = '\0';
                                    DSString wordL2(temp);

                                    char indexBuffer[2];
                                    indexBuffer[0] = wordL2[0];
                                    indexBuffer[0] = toupper(indexBuffer[0]);
                                    indexBuffer[1] = '\0';


                                    //DSString indexL2(indexBuffer);
                                    DSString indexL2(wordL2.substring(0, 1));

                                    Word completeIndex (wordL2, pageNumObj, indexL2);

                                    allWords.push_back(completeIndex);
                                    int check0 = 0;
                                    for (int j = 0; j < indexCategories.getSize(); j++){
                                        if (indexL2 == indexCategories.at(j))
                                            check0 = 1;
                                    }
                                    if (check0 == 0) {
                                        indexCategories.push_back(indexL2);
                                        indexCategories.sort();
                                    }

                                    int check1 = 0;
                                    for (int j = 0; j < words.getSize(); j++){
                                        if (wordL2 == words.at(j))
                                            check1 = 1;
                                    }
                                    if (check1 == 0) {
                                        words.push_back(wordL2);
                                        words.sort();
                                    }


                                    //countN++;
                                    //DSString wordL2(inputString.substring(startL2, countN));
                                    //nested1[countN] = '\0';
                                    cout << wordL2 << " : " << pageNumObj << " : " << indexL2 << endl;
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

    for (int i = 0; i < indexCategories.getSize(); i++){
        cout << indexCategories.at(i) << endl;
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < words.getSize(); i++){
        cout << words.at(i) << endl;
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < indexCategories.getSize(); i++){
        int count0 = 0;
        for (int j = 0; j < words.getSize(); j++){
            if (indexCategories.at(i)[0] == words.at(j)[0]){
                if (count0 == 0)
                    cout << "[" << indexCategories.at(i) << "]" << endl;
                count0++;
                DSVector <DSString> pageNumV;
                cout << words.at(j) << ": ";
                int count = 0;
                int pageRepeat = 0;
                for (int k = 0; k < allWords.getSize(); k++){
                    if (words.at(j) == allWords.at(k).getIndexedWord()){
                        for (int l = 0; l < pageNumV.getSize(); l++){
                            if (pageNumV.at(l) == allWords.at(k).getPageNum()) {
                                pageRepeat = 1;
                                break;
                            }
                        }
                        if (pageRepeat == 0) {
                            if (count != 0)
                                cout << ", ";
                            cout << allWords.at(k).getPageNum();
                            pageNumV.push_back(allWords.at(k).getPageNum());
                            count++;
                        }
                    }
                }
                cout << endl;
            }
        }
    }

    /*for (int i = 0; i < allWords.getSize(); i++){
        //for (int j = 0; j < allWords.getSize(); j++){
        int j = 0;
        while (allWords.at(j) != nullptr)

            if (allWords.at(i).getIndex() > allWords.at(j).getIndex())
                break;
            else if (allWords.at(i).getIndex() == allWords.at(j).getIndex()){

                DSString newPageNum = allWords.at(i).getPageNum();

                if (newPageNum > allWords.at(j).getPageNum()){
                    newPageNum = newPageNum + ", " + ;
                }



                Word newWord;
            }
        }



    }*/



}