//
// Created by stas on 15.10.19.
//

#ifndef LABS_LINKEDLIST_H
#define LABS_LINKEDLIST_H

#include <iostream>

struct Element{
    int value;
    Element* next;

    explicit Element(int new_value){
        value = new_value;
        next = nullptr;
    }
};

class LinkedList{
public:
    LinkedList();
    LinkedList(std::initializer_list<int> list);
    LinkedList(const LinkedList& other);
    ~LinkedList();

    LinkedList& operator=(const LinkedList& list);
    int& operator[](const int pos_);

    void Swap(LinkedList& list);
    bool IsEmpty(){ return !first;};
    void PopFront();
    void PushBack(int add_value);
    void PushFront(int add_value);
    int Front() const {return first->value;}
    void PrintList(std::ostream& out_stream) const;
    void Clear();
    void Insert_A(int value);
    void InvertPreLast(int value);
    void Insert(int value, int pos);
    int Size();

    void Invert(){
        if(first){
            auto prev = first;
            auto p = first->next;

            prev->next = nullptr;

            while (p){
                auto temp = p->next;
                p->next = prev;
                prev = p;
                p = temp;
            }
            pLast = &first->next;
            first = prev;
        }
    }

    Element* GetFirstElement(){
        return first;
    }
private:
    void Erase();

    Element* first;
    Element** pLast;
};



#endif //LABS_LINKEDLIST_H
