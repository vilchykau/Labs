//
// Created by stas on 15.10.19. 34+
//
#import "../linkedList/LinkedList.h"
#import "../linkedList/LinkedListIterator.h"
#include <iostream>
#include <fstream>
/*
bool HasSubList(LinkedList& list, LinkedList& sub_list){
    Element * start = list.GetNowElement();
    while (!list.It_isEnd() && !sub_list.It_isEnd()) {
        list.SetNowElement(start);
        list.It_next();
        sub_list.It_reset();
        while (!sub_list.It_isEnd() && !list.It_isEnd() && list.It_now() != sub_list.It_now()) {
            list.It_next();
        }
        start = list.GetNowElement();
        while (!list.It_isEnd() && !sub_list.It_isEnd() && list.It_now() == sub_list.It_now()) {
            list.It_next();
            sub_list.It_next();
        }
    }
    return sub_list.It_isEnd();
}

int main(){
    LinkedList L = {1, 2, 3, 4, 5, 6, 7, 8};

    LinkedList L1 = {2, 3};
    LinkedList L2 = {5, 6};
    LinkedList L3 = {7};

    L.It_reset();
    L1.It_reset();
    L2.It_reset();
    L3.It_reset();

    bool a = HasSubList(L, L1) && HasSubList(L, L2) && HasSubList(L, L3);
    std::cout << a;
}*/

bool HasSubList(LinkedListIterator& main_iterator, LinkedListIterator& sub_iterator){
    Element * start = nullptr;
    while (!main_iterator.IsEnd() && !sub_iterator.IsEnd()) {
        if(start){
            main_iterator.SetNow(start);
            ++main_iterator;
        }
        sub_iterator.Reset();
        while (!main_iterator.IsEnd() && !sub_iterator.IsEnd() && main_iterator.GetValue() != sub_iterator.GetValue()) {
            ++main_iterator;
        }
        start = main_iterator.GetNow();
        while (!main_iterator.IsEnd() && !sub_iterator.IsEnd() && main_iterator.GetValue() == sub_iterator.GetValue()) {
            ++main_iterator;
            ++sub_iterator;
        }
    }
    return sub_iterator.IsEnd();
}

void ReadToList(std::istream& in_stream, LinkedList& list, int n){
    for(int i = 0;i < n; ++i){
        int a;
        in_stream >> a;
        list.PushBack(a);
    }
}

int main(){
    /*LinkedList L = {1, 2, 3, 4, 5, 6, 7, 8};

    LinkedList L1 = {2, 3};
    LinkedList L2 = {5, 6};
    LinkedList L3 = {7};*/

    int l, l1, l2, l3;

    std::ifstream in_stream("input.txt");
    in_stream >> l >> l1 >> l2 >> l3;
    LinkedList L,L1,L2,L3;
    ReadToList(in_stream, L, l);
    ReadToList(in_stream, L1, l1);
    ReadToList(in_stream, L2, l2);
    ReadToList(in_stream, L3, l3);


    LinkedListIterator It(L.GetFirstElement());
    LinkedListIterator It1(L1.GetFirstElement());
    LinkedListIterator It2(L2.GetFirstElement());
    LinkedListIterator It3(L3.GetFirstElement());

    bool a = HasSubList(It, It1) && HasSubList(It, It2) && HasSubList(It, It3);
    std::cout << a;
}