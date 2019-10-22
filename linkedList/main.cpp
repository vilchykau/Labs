//
// Created by stas on 15.10.19.
//
#include <iostream>
#import "LinkedList.h"

int main(){
    LinkedList list = {1, 2, 3, 4, 5};

    LinkedList L2(list);
    list.PopFront();

    L2.PrintList(std::cout);
    std::cout << '\n';
    list.PrintList(std::cout);
    //std::cout << list;
}