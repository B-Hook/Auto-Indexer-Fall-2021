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
    DSString pageNumObj;
    DSVector<DSString> pageNumV;

    ifstream inFile(input);

    while (!inFile.eof()) {

        inFile.getline(char1, 85, '\n');

        if (char1[0] == '<') {
            for (int i = 1; i < strlen(char1) - 1; i++)
                pageNum[i - 1] = char1[i];
            pageNum[strlen(char1) - 2] = '\0';
            pageNumObj = pageNum;
            pageNumV.push_back(pageNumObj);
        }
        else{
            for (int i = 0; i < strlen(char1); i++){

                if (char1[i] == '['){
                    char word1[85];
                    i++;
                    for (;i < strlen(char1); i++){
                        if ((char1[i] != '[') && (char1[i] != ']')){
                            word1[countW] = char1[i];
                            countW++;
                            //i++;
                        }

                        else if (char1[i] == ']'){
                            word1[countW] = '\0';
                            cout << word1 << endl;
                            memset(word1, 0, strlen(char1));
                            //obj1(word1, pageNumObj)
                            countW = 0;
                            //i++;
                            break;
                        }
                        else if (char1[i] == '['){
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

                        }

                    }

                }



            }




        }




    }
    for (int i = 0; i < pageNumV.getSize(); i++)
        cout << pageNumV.at(i) << endl;

}
