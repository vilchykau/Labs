//
// Created by stas on 5.11.19.
//

#ifndef LABS_LINKEDLISTELEMENT_H
#define LABS_LINKEDLISTELEMENT_H

template <typename T>
struct Element{
    T value;
    Element* next;

    explicit Element(int new_value){
        value = new_value;
        next = nullptr;
    }
};

#endif //LABS_LINKEDLISTELEMENT_H
