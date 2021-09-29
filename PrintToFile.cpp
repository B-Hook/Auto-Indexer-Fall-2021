//
// Created by Braiden Hook on 9/27/21.
//

#include "PrintToFile.h"

PrintToFile::PrintToFile(char * outputFile, DSVector<Word> &wordObjs, DSVector<DSString> &indexCategories
                         , DSVector<DSString> &words) {

    ofstream output (outputFile); // Opens output file
    // Iterating through each index category
    for (int i = 0; i < indexCategories.getSize(); i++){
        int count0 = 0;
        for (int j = 0; j < words.getSize(); j++){
            if (indexCategories.at(i)[0] == words.at(j)[0]){
                // Makes sure more than 1 of the same index prints
                if (count0 == 0) {
                    char indexUpperCase[2];
                    indexUpperCase[0] = toupper(indexCategories.at(i)[0]);
                    indexUpperCase[1] = '\0';
                    DSString newIndexCategory (indexUpperCase); // Prints in uppercase
                    output << "[" << newIndexCategory << "]" << endl;
                }
                count0++;
                DSVector <DSString> pageNumV; // Creating a vector to contain page numbers
                // If statement which will check if a word is longer than 50 characters
                if (words.at(j).getLength() > 50){
                    int start = 0;
                    // Will continue to print the words on new lines after hitting 50 characters
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
                    output << words.at(j) << ": "; // Will print normally if not longer than 50 characters
                }
                int count = 0;
                int pageRepeat = 0;
                // Printing the page numbers
                for (int k = 0; k < wordObjs.getSize(); k++){
                    if (words.at(j) == wordObjs.at(k).getIndexedWord()){
                        // Checking to see if the page number has already printed for the word
                        for (int l = 0; l < pageNumV.getSize(); l++){
                            if (pageNumV.at(l) == wordObjs.at(k).getPageNum()) {
                                pageRepeat = 1;
                                break;
                            }
                        }
                        // if it hasn't printed then it will print
                        if (pageRepeat == 0) {
                            // Will add comma if it isn't the first page number printed for the word
                            if (count != 0)
                                output << ", ";
                            // Checking to see if the page number is longer then 15 characters
                            // will print on new lines once it extends beyond its limit of 15 characters
                            if (wordObjs.at(k).getPageNum().getLength() > 15){
                                int start = 0;
                                while (start < wordObjs.at(k).getPageNum().getLength()) {
                                    DSString newStr;
                                    if ((start + 15) < wordObjs.at(k).getPageNum().getLength()) {
                                        newStr = wordObjs.at(k).getPageNum().substring(start, 15);
                                    } else {
                                        newStr = wordObjs.at(k).getPageNum().substring
                                                (start, wordObjs.at(k).getPageNum().getLength() - start);
                                    }
                                    start += 15;
                                    output << newStr;
                                    if (start < wordObjs.at(k).getPageNum().getLength())
                                        output << "\n    ";
                                }
                            }
                            else {
                                // will print normally if not longer than 15 chars
                                output << wordObjs.at(k).getPageNum();
                            }
                            // Adds number to the vector
                            pageNumV.push_back(wordObjs.at(k).getPageNum());
                            count++;
                        }
                    }
                }
                output << endl; // Ends the output with an endline
            }
        }
    }
    output.close(); // Close output
}
