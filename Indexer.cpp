//
// Created by Braiden Hook on 9/25/21.
//
#include "Indexer.h"
Indexer::Indexer(char *inputFile, char *outputFile) {
    // Reads in the file
    readInFile(inputFile);
    // Calls the print object to format and print what was read in
    PrintToFile print(outputFile, wordObjs, indexCategories, words);
}
void Indexer::readInFile(char *inFile) {
    int countW = 0; // Keeps count for the non nested word
    int countN = 0; // Keeps count for the nested word
    ifstream input(inFile); // Opening file
    char temp[200]; // Buffer
    // Reading the first line of the file and places it into the buffer
    input.getline(temp, 200, '\n');
    DSString inputString (temp); // Places temp into the DSString object
    // Looping through the file reading in line by line and adding the buffer to the inputString
    while (!input.eof()) {
        char buffer[200];
        input.getline(buffer, 200, '\n');
        buffer[strlen(buffer)] = '\0';
        inputString = inputString + buffer;
    }
    // Looping through the entire file
    for (int i = 0; i < inputString.getLength(); i++){
        // Checking for the page number
        if (inputString[i] == '<') {
            i++;
            int start = i;
            int countPageNum = 0;
            while (inputString[i] != '>'){
                countPageNum++;
                i++;
            }
            // Places new page number into the object
            pageNumObj = inputString.substring(start, countPageNum);
            // Stops reading through the inputString when -1 appears
            if (pageNumObj == "-1")
                break;
        }
        // Enters when a bracket word appears
        else if (inputString [i] == '['){
            int check = 0; // Check which will break the following for when the bracketed word ends
            int startL1 = i; // Keep track of the non-nested word
            countW++;
            i++;
            // Loops through bracket word, ends when the bracket ends
            for (;i < inputString.getLength(); i++) {
                // If there is no bracket add to the count
                if ((inputString[i] != '[') && (inputString[i] != ']')) {
                    countW++;
                }
                // Enters when the word ends
                else if (inputString[i] == ']') {
                    endWord(countW, startL1, inputString); // Calling function to end word
                    check = 1; // Makes it exit the loop that is running when non-nested words appears
                    break;
                }
                // If a nested words appears
                else if (inputString[i] == '[') {
                    int startL2 = i; // Start for nested word
                    countW++; // Still keeping count for the non-nested word
                    countN++;
                    i++;
                    // For loop enters when nested word appears
                    for (; i < inputString.getLength(); i++) {
                        if (inputString[i] == ']') {
                            endWord(countN, startL2, inputString);
                            countW++;
                            break;
                        }
                        else {
                            countN++;
                            countW++;
                        }
                    }
                }
                if (check == 1)
                    break;
            }
        }
    }
    input.close(); // Closes input file
}
// Function that ends the read in for the word
void Indexer::endWord(int &count, int &start, DSString &inputString) {
    count++;
    // Creates DSString buffer based on where the count started and ended
    DSString wordBuffer1(inputString.substring(start, count));
    char temp[wordBuffer1.getLength()]; // Temp char buffer
    int tempCount = 0;
    // loops through placing the chars into the temp cstring taking out the brackets and making it lower case
    for (int j = 0; j < wordBuffer1.getLength(); j ++){
        if((wordBuffer1[j] != '[') && wordBuffer1[j] != ']'){
            temp[tempCount] = wordBuffer1[j];
            if (isalpha(temp[tempCount]))
                temp[tempCount] = tolower(temp[tempCount]);
            tempCount++;
        }
    }
    temp[tempCount] = '\0';
    DSString word1(temp); // DSString for the temp
    DSString index(word1.substring(0, 1)); // DSString for the index
    Word completeIndex (word1, pageNumObj, index); // Creates a Word obj containing the 3 DSStrings
    wordObjs.push_back(completeIndex); // Pushes back the new Word
    int check0 = 0;
    // Checks to see if the page number exists or not in the index category
    for (int j = 0; j < indexCategories.getSize(); j++){
        if (index == indexCategories.at(j))
            check0 = 1;
    }
    // If it doesn't it will push back the index into the vector
    if (check0 == 0) {
        indexCategories.push_back(index);
        indexCategories.sort();
    }
    int check1 = 0;
    // Checks to see if the word exists
    for (int j = 0; j < words.getSize(); j++){
        if (word1 == words.at(j))
            check1 = 1;
    }
    // If it doesn't it will push back the word
    if (check1 == 0) {
        words.push_back(word1);
        words.sort();
    }
    count = 0;
}
