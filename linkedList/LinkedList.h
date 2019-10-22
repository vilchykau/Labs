//
// Created by stas on 15.10.19.
//

#ifndef LABS_LINKEDLIST_H
#define LABS_LINKEDLIST_H

#include <ostream>

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
    ~LinkedList();

    bool IsEmpty(){ return !first;};
    void PopFront();
    void PushBack(int add_value);
    void PushFront(int add_value);
    int Front() const {return first->value;}
    void PrintList(std::ostream& out_stream);
    void Clear();

    Element* GetFirstElement(){
        return first;
    }
private:
    void Erase();

    Element* first;
    Element** pLast;

    Element *now;
};

std::ostream& operator<<(std::ostream& stream, LinkedList linkedList){
    linkedList.PrintList(stream);
    return stream;
}



#endif //LABS_LINKEDLIST_H
