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
            this->data = copy.data;
            this->size = copy.size;
            this->curr = copy.curr;
        }
        return *this;
    }

    DSVector& operator= (const DSVector& copy){
        if (this->data != copy.data) {
            delete[] this->data;
            this->data = new T[copy.size];
            this->data = copy.data;
            this->size = copy.size;
            this->curr = copy.curr;
        }
        return *this;
    }




};

#endif //INC_21F_PA02_DSVECTOR_H
