//
// Created by stas on 16.10.19.
//

#ifndef LABS_LINKEDLISTITERATOR_H
#define LABS_LINKEDLISTITERATOR_H

#import "LinkedList.h"

class LinkedListIterator {
public:
    explicit LinkedListIterator(Element* new_now){
        now = new_now;
        start = new_now;
    }

    void Go(){
        now = now->next;
    }

    bool IsEnd(){
        return now == nullptr;
    }

    Element* GetNow(){
        return now;
    }

    void SetNow(Element* new_now){
        now = new_now;
    }

    int GetValue(){
        return now->value;
    }

    void Reset(){
        now = start;
    }

    void operator++(){
        Go();
    }

private:
    Element* now;
    Element* start;
};


#endif //LABS_LINKEDLISTITERATOR_H
