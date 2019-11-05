//
// Created by stas on 5.11.19.
//

#ifndef LABS_ITERATOR_H
#define LABS_ITERATOR_H

#include "IIterator.h"

template <typename T>
class Iterator {
    Iterator(IIterator<T>* iterator){
        this->iterator = iterator;
    }

    ~Iterator(){
        delete iterator;
    }

    bool HasNext(){
        return iterator->HasNext();
    };

    T Next(){
        return iterator->Next();
    };
private:
    IIterator<T>* iterator;
};


#endif //LABS_ITERATOR_H
