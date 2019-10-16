//
// Created by stas on 15.10.19.
//
#include <iostream>
#import "LinkedList.h"

int main(){
    LinkedList list;
    list.PushFront(77);
    list.PushBack(5);
    list.PushBack(6);
    list.PushFront(9);
    list.PushBack(7);


    list.PrintList(std::cout);
}