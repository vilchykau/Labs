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

LinkedList::LinkedList(const LinkedList& other):first(nullptr), pLast(&first){
    Element* e = other.first;
    while(e){
        PushBack(e->value);
        e = e->next;
    }
};

LinkedList::~LinkedList() {
    Erase();
}

LinkedList& LinkedList::operator=(const LinkedList& list){
    if(this != &list){
        LinkedList temp(list);
        Swap(temp);
    }
    return *this;
}

void LinkedList::Swap(LinkedList& list){
    Element* f_ = list.first;
    Element** l_ = list.pLast;

    list.first = this->first;
    list.pLast = this->pLast;

    this->pLast = l_;
    this->first = f_;
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

void LinkedList::PrintList(std::ostream& out_stream) const {
    Element* now_element = first;

    while (now_element){
        out_stream << now_element->value << ' ';
        now_element = now_element->next;
    }
}

void LinkedList::Clear(){
    while (first){
        Element* new_first = first->next;
        delete first;
        first = new_first;
    }
    first = nullptr;
    pLast = &first;
}

void LinkedList::Erase() {
    Clear();
}

void LinkedList::InvertPreLast(int value){
    if(!first->next){PushFront(value);return;}
    Element* pre = first;

    while (pre->next->next){
        pre = pre->next;
    }

    Element* new_element = new Element(value);
    new_element->next = pre->next;
    pre->next = new_element;
}

void LinkedList::Insert_A(int value){
    Element* element = new Element(value);
    element->next = first->next;
    first->next = element;
}

void LinkedList::Insert(int value, int pos){
    Element* pre = first;
    for(int i = 1; i < pos; ++i){
        pre = pre->next;
    }

    Element* element = new Element(value);
    element->next = pre->next;
    pre->next = element;
}

