//
// Created by stas on 5.11.19.
//

#ifndef LABS_LINKEDLISTITERATOR_H
#define LABS_LINKEDLISTITERATOR_H

#include "IIterator.h"
#include "../linkedList/LinkedList.h"
#include "../linkedList/LinkedListElement.h"

#include <iostream>

template <typename T>
class LinkedListIterator : public IIterator<T>{
public:
    LinkedListIterator(Element<T>* first){
        now = first;
    }

    LinkedListIterator(const LinkedListIterator<T>& iterator){
        now = iterator.now;
    }

    bool HasNext() override {
        return true;
    };

    T Next() override {
        auto temp = now;
        now = now->next;
        return temp->value;
    };
private:
    Element<T>* now;
};


#endif //LABS_LINKEDLISTITERATOR_H
