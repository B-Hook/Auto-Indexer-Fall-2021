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
    DSString pageNumObj;
    DSVector<DSString> pageNumV;
    ifstream inFile(input);
    char temp[200];
    inFile.getline(temp, 200, '\n');
    DSString inputString (temp);
    while (!inFile.eof()) {
        char buffer[200];
        inFile.getline(buffer, 200, '\n');
        buffer[strlen(buffer)] = '\0';
        inputString = inputString + buffer;
        memset(buffer, 0, strlen(buffer));
    }

    for (int i = 0; i < inputString.getLength(); i++){
        if (inputString[i] == '<') {
            i++;
            int start = i;
            int countPageNum = 0;
            while (inputString[i] != '>'){
                countPageNum++;
                i++;
            }
            pageNumObj = inputString.substring(start, countPageNum);
            if (pageNumObj == "-1")
                break;
            i++;
        }
        else if (inputString [i] == '['){
            int check = 0;
            for (; i < inputString.getLength(); i++){

                if (inputString[i] == '['){
                    int startL1 = i;
                    countW++;
                    i++;
                    for (;i < inputString.getLength(); i++){
                        if ((inputString[i] != '[') && (inputString[i] != ']')){
                            countW++;
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
                            DSString indexL1(wordL1.substring(0, 1));
                            Word completeIndex (wordL1, pageNumObj, indexL1);
                            allWords.push_back(completeIndex);
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
                            cout << wordL1 << " : " << pageNumObj << " : " << indexL1 << endl;
                            countW = 0;
                            check = 1;
                            break;
                        }
                        else if (inputString[i] == '['){
                            int startL2 = i;
                            countW++;
                            countN++;
                            i++;
                            for (; i < inputString.getLength(); i++){
                                if(inputString[i] != ']'){
                                    countN++;
                                    countW++;
                                }
                                else if (inputString[i] == ']'){
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
                                    cout << wordL2 << " : " << pageNumObj << " : " << indexL2 << endl;
                                    countN = 0;
                                    countW++;
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
                if (count0 == 0) {
                    char indexUpperCase[2];
                    indexUpperCase[0] = toupper(indexCategories.at(i)[0]);
                    indexUpperCase[1] = '\0';
                    DSString newindexCategory (indexUpperCase);
                    cout << "[" << newindexCategory << "]" << endl;
                }
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
}