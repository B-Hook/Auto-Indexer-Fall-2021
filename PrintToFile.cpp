//
// Created by Braiden Hook on 9/27/21.
//

#include "PrintToFile.h"

PrintToFile::PrintToFile(char * outputFile, DSVector<Word> &wordObjs, DSVector<DSString> &indexCategories
                         , DSVector<DSString> &words) {

    ofstream output (outputFile);

    for (int i = 0; i < indexCategories.getSize(); i++){
        int count0 = 0;
        for (int j = 0; j < words.getSize(); j++){
            if (indexCategories.at(i)[0] == words.at(j)[0]){
                if (count0 == 0) {
                    char indexUpperCase[2];
                    indexUpperCase[0] = toupper(indexCategories.at(i)[0]);
                    indexUpperCase[1] = '\0';
                    DSString newIndexCategory (indexUpperCase);
                    output << "[" << newIndexCategory << "]" << endl;
                }
                count0++;
                DSVector <DSString> pageNumV;
                if (words.at(j).getLength() > 50){
                    int start = 0;
                    while (start < words.at(j).getLength()) {
                        DSString newStr;
                        if ((start + 50) < words.at(j).getLength()) {
                            newStr = words.at(j).substring(start, 50);
                        } else {
                            newStr = words.at(j).substring
                                    (start, words.at(j).getLength() - start);
                        }
                        start += 50;
                        output << newStr;
                        if (start < words.at(j).getLength())
                            output << "\n    ";
                    }
                    output << ": " ;
                }
                else {
                    output << words.at(j) << ": ";
                }
                int count = 0;
                int pageRepeat = 0;
                for (int k = 0; k < wordObjs.getSize(); k++){
                    if (words.at(j) == wordObjs.at(k).getIndexedWord()){
                        for (int l = 0; l < pageNumV.getSize(); l++){
                            if (pageNumV.at(l) == wordObjs.at(k).getPageNum()) {
                                pageRepeat = 1;
                                break;
                            }
                        }
                        if (pageRepeat == 0) {
                            if (count != 0)
                                output << ", ";

                            if (wordObjs.at(k).getPageNum().getLength() > 30){
                                int start = 0;
                                while (start < wordObjs.at(k).getPageNum().getLength()) {
                                    DSString newStr;
                                    if ((start + 30) < wordObjs.at(k).getPageNum().getLength()) {
                                        newStr = wordObjs.at(k).getPageNum().substring(start, 30);
                                    } else {
                                        newStr = wordObjs.at(k).getPageNum().substring
                                                (start, wordObjs.at(k).getPageNum().getLength() - start);
                                    }
                                    start += 30;
                                    output << newStr;
                                    if (start < wordObjs.at(k).getPageNum().getLength())
                                        output << "\n    ";
                                }
                            }
                            else {
                                output << wordObjs.at(k).getPageNum();
                            }
                            pageNumV.push_back(wordObjs.at(k).getPageNum());
                            count++;
                        }
                    }
                }
                output << endl;
            }
        }
    }

}
