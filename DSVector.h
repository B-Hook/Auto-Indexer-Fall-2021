//
// Created by Braiden Hook on 9/22/21.
//

#ifndef INC_21F_PA02_DSVECTOR_H
#define INC_21F_PA02_DSVECTOR_H

template <typename T>

class DSVector {
// Calling Private Data members
private:

    T *data;
    int size;
    int curr;
// Calling Public functions
public:
    // Constructor
    DSVector(){
        data = new T[10]; // Allocate 10 spaces in memory on the heap
        size = 10; // size is set to 10
        curr = 0;
    }
    // Destructor
    ~DSVector(){
        delete [] data;
    }
    // Copy Constructor
    DSVector (const DSVector& copy){
            // Allocating memory on the heap based on the size of the passed DSVector for this->data
            this->data = new T[copy.getSize()];
            // Loop through to make a deep copy
            for (int i = 0; i < copy.curr; i++)
                this->data[i] = copy.data[i];
            this->size = copy.size;
            this->curr = copy.curr;
    }

    DSVector& operator= (const DSVector& copy){
        if (this->data != copy.data) { // Check to make sure we are not making an unnecessary copy
                delete[] this->data; // Delete the previous data
            // Repeat process of copy constructor
            this->data = new T[copy.size];
            for (int i = 0; i < copy.curr; i++)
                this->data[i] = copy.data[i];
            this->size = copy.size;
            this->curr = copy.curr;
        }
        return *this; // Return the updated DSVector
    }
    // Checking if the DSVectors are equal
    bool operator==(const DSVector &passedVector) const{
        int count = 0;
        // Check the sizes to see if they are equal
        if ((this->curr == passedVector.curr) && (this->size == passedVector.size)) {
            // Check the values at each index
            for (int i = 0; i < this->curr; i++) {
                if (this->data[i] == passedVector.data[i]){ }
                else{ count++; }
            }
        }
        else{
            count++;
        }
        if (count == 0)
            return true; // Returns true if the size and values are the same
        else
            return false;
    }
    // Returns value at []
    T& operator[](const int index) const{
        return this->data[index];
    }
    // Inserting the sent value into the vector (array)
    void push_back (T sentData){
        // If the array is full, increase the size by double the previous size
        if (curr == size){
            T* temp = new T [2 * size]; // Making a new array of twice the size
            // Deep copy
            for (int i = 0; i < this->getSize(); i++)
                temp[i] = this->data[i];
            delete[] this->data; // Delete the old array
            size *= 2;
            this->data = temp; // copy the array into the current array increasing its size
        }
        this->data[curr] = sentData; // inserts the passed data at the end of the vector
        curr++;
    }
    // removes value at the passed index
    void remove (const int index) {
        T* temp = new T [size]; // New array
        int tempCount = 0;
        for (int i = 0; i < this->getSize(); i++){
            // Put values into the array as long as the index of the remove val is not the same
            if (i != index){
                temp[tempCount] = this->data[i];
                tempCount++;
            }
        }
        delete[] this->data;
        this->data = temp;
        curr--;
    }
    // Searches for values inside the vector
    int search (const T element){
        int location = -1;
        for (int i = 0; i < this->getSize(); i++){
            if (this->data[i] == element)
                location = i;
        }
        return location;
    }
    // Returns the value at passed int
    T at (const int index){ return this->data[index]; }
    // Sorts the entire vector
    void sort() {
        // Loops through the vector sorting the values
        for (int i = 0; i < this->getSize() - 1; ++i) {
            int lowestVal = i;
            // Checks to see if there is a lower value later on in the vector
            for (int j = i + 1; j < this->getSize(); ++j) {
                if (this->data[j] < this->data[lowestVal]) {
                    lowestVal = j;
                }
            }
            // Places the lowest value at the forefront of the vector
            T temp = this->data[i];
            this->data[i] = this->data[lowestVal];
            this->data[lowestVal] = temp;
        }
    }
    // Returns the current index
    int getSize () const { return curr; }
    // Returns the total size of the vector
    int getCapacity () const { return size; }
};

#endif //INC_21F_PA02_DSVECTOR_H
