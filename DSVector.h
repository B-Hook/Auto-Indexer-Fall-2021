//
// Created by Braiden Hook on 9/22/21.
//

#ifndef INC_21F_PA02_DSVECTOR_H
#define INC_21F_PA02_DSVECTOR_H

template <typename T>

class DSVector {

private:

    T *data;
    int size;
    int curr;

public:

    DSVector(){
        data = new T[10];
        size = 10;
        curr = 0;
    }

    ~DSVector(){
        delete [] data;
    }

    DSVector (const DSVector& copy){
        if (this->data != copy.data) {
            this->data = new T[copy.getSize()];
            for (int i = 0; i < copy.size; i++)
                this->data[i] = copy.data[i];
            this->size = copy.size;
            this->curr = copy.curr;
        }
    }

    DSVector& operator= (const DSVector& copy){
        if (this->data != copy.data) {
            delete[] this->data;
            this->data = new T[copy.size];
            for (int i = 0; i < copy.size; i++)
                this->data[i] = copy.data[i];
            this->size = copy.size;
            this->curr = copy.curr;
        }
        return *this;
    }

    T& operator[](const int index) {
        return this->data[index];
    }

    void push_back (T sentData){

        if (curr == size){
            T* temp = new T [2 * size];
            for (int i = 0; i < size; i++)
                temp[i] = this->data[i];
            delete[] this->data;
            size *= 2;
            this->data = temp;
        }
        this->data[curr] = sentData;
        curr++;
    }

    void remove (const int index) {

        T* temp = new T [size];
        int tempCount = 0;

        for (int i = 0; i < curr; i++){
            if (i != index){
                temp[tempCount] = this->data[i];
                tempCount++;
            }
        }
        delete[] this->data;
        this->data = temp;
        curr--;
    }

    int search (const T element){
        int location = -1;
        for (int i = 0; i < curr; i++){
            if (this->data[i] == element)
                location = i; //TODO:: will make it return multiple locations if need be later
        }

        return location;
    }

    T at (const int index){ return this->data[index]; }

    int getSize () const { return curr; }
    int getCapacity () const { return size; }
};

#endif //INC_21F_PA02_DSVECTOR_H
