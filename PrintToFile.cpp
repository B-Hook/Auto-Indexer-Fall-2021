//
// Created by Braiden Hook on 9/27/21.
//

#include "PrintToFile.h"

PrintToFile::PrintToFile(char * outputFile, DSVector<Word> &wordObjs, DSVector<DSString> &indexCategories
                         , DSVector<DSString> &words) {

    for (int i = 0; i < indexCategories.getSize(); i++){
        int count0 = 0;
        for (int j = 0; j < words.getSize(); j++){
            if (indexCategories.at(i)[0] == words.at(j)[0]){
                if (count0 == 0) {
                    char indexUpperCase[2];
                    indexUpperCase[0] = toupper(indexCategories.at(i)[0]);
                    indexUpperCase[1] = '\0';
                    DSString newIndexCategory (indexUpperCase);
                    cout << "[" << newIndexCategory << "]" << endl;
                }
                count0++;
                DSVector <DSString> pageNumV;
                cout << words.at(j) << ": ";
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
                                cout << ", ";
                            cout << wordObjs.at(k).getPageNum();
                            pageNumV.push_back(wordObjs.at(k).getPageNum());
                            count++;
                        }
                    }
                }
                cout << endl;
            }
        }
    }

}
