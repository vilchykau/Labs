//
// Created by stas on 5.11.19.
//

#include <iostream>
#include "DList.h"

int main(){
    DList<int> list;
    list.PushFront(5);
    list.PushFront(5);
    list.PushFront(5);

    std::cout << list << 0.5;
}