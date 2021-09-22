//
// Created by Braiden Hook on 9/22/21.
//

#include "DSString.h"
#include <iostream>

DSString::DSString() {
    data = nullptr;
}

DSString::DSString(const char *cStr) {
    this->data = new char[strlen(cStr) + 1]; // Creates a new cstring based on the length of the passed cstring
    strcpy(this->data, cStr); // Copies the passed cstring to the object data
}

DSString::DSString(const DSString &obj) {
    // Creates a new cstring based on the length of the data of the passed obj
    this->data = new char[strlen(obj.data) + 1];
    strcpy(this->data, obj.data); // Copies the data from the passed obj to the new object data
}

DSString::~DSString() {

    if (this->data != nullptr){
        delete[] this->data; //deleting the cstring
    }

}

DSString &DSString::operator=(const char *copy) {
    // If the data does not equal the copy
    if (this->data != copy) {
        delete[] this->data; // Deletes the cstring
        this->data = new char[strlen(copy) + 1]; // New cstring
        strcpy(this->data, copy); // Copies the passed cstring to data
    }
    return *this; // Returns the object
}

DSString &DSString::operator=(const DSString &copy) {
    // If the data does not equal the copy's data
    if (this->data != copy.data) {
        delete[] this->data; // Deletes the cstring
        this->data = new char[strlen(copy.data) + 1]; // New cstring
        strcpy(this->data, copy.data); // Copies the passed data's cstring to this object's data
    }
    return *this; // Returns this object
}

DSString DSString::operator+(const DSString &a) {
    // Creates a new cstring adding the length of the data and the passed data + 1 for the 0/
    char newStr [strlen(this->data) + strlen(a.data) + 1];
    strcpy(newStr, this->data); // Copies this objects data in the new str
    strcat(newStr, a.data); // Adds the passed data

    return newStr; // Returns the new obj
}

bool DSString::operator==(const char *c) const{
    // Compares the data to the passed cstring
    int a = strcmp(this->data, c);
    // If they equal return true, if not then return false
    if (a == 0)
        return true;
    else
        return false;
}

bool DSString::operator==(const DSString &c) const{
    // Compares the data to the passed object's data
    int a = strcmp(this->data, c.data);
    // If they equal return true, if not then return false
    if (a == 0)
        return true;
    else
        return false;
}

bool DSString::operator>(const DSString &c) const{
    // Compares the data to the passed object's data
    int a = strcmp(this->data, c.data);
    // If a is greater than 0 then true, if not false
    if (a > 0)
        return true;
    else
        return false;
}

bool DSString::operator<(const DSString &c) const{
    // Compares the data to the passed object's data
    int a = strcmp(this->data, c.data);
    // If a is less than 0 then true, if not false
    if (a < 0)
        return true;
    else
        return false;
}


bool DSString::operator>(const char *c) const{
    // Compares the data to the passed cstring
    int a = strcmp(this->data, c);
    // If a is greater than 0 then true, if not false
    if (a > 0)
        return true;
    else
        return false;
}

char &DSString::operator[](const int index) {
    return this->data[index]; // Returns the char at the specfic passed index
}

int DSString::getLength() {
    return strlen(this->data); // Returns length of the cstring
}

DSString DSString::substring(int start, int numChars) {
    DSString newObj; // Creates new object
    newObj.data = new char [numChars + 1]; // Makes the cstring the length of num of characters wanting to read in
    strncpy(newObj.data, this->data + start, numChars); // Copies the data from this object into the new one
    newObj.data[numChars] = '\0'; // Puts a null char at the end of the cstring to terminate it
    return newObj; // Returns the new object
}

char *DSString::c_str() {
    return this->data; // Returns the cstring
}

std::ostream &operator<<(std::ostream &oFile, const DSString &objPrint) {
    return oFile << objPrint.data; // Prints the object to the output file
}