//
// Created by stas on 15.10.19.
//

#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    first = nullptr;
    pLast = &first;
}

LinkedList::LinkedList(std::initializer_list<int> list): first(nullptr), pLast(&first){
    for(auto& element : list){
        PushBack(element);
    }
}

LinkedList::~LinkedList() {
    while (!IsEmpty()){
        PopFront();
    }
}

void LinkedList::PopFront(){
    Element* new_first = first->next;
    delete first;
    first = new_first;
}

void LinkedList::PushBack(int add_value){
    *pLast = new Element(add_value);
    pLast = &(*pLast)->next;
}

void LinkedList::PushFront(int add_value){
    Element *add_element = new Element(add_value);
    add_element->next = first;
    first = add_element;

    if(!first->next){
        pLast = &first->next;
    }
}

void LinkedList::PrintList(std::ostream& out_stream){
    Element* now_element = first;

    while (now_element){
        out_stream << now_element->value << ' ';
        now_element = now_element->next;
    }
    out_stream << '\n';
}

void LinkedList::Clear(){
    while (first){
        Element* new_first = first->next;
        delete first;
        first = new_first;
    }
    pLast = &first;
}

