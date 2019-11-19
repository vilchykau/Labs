//
// Created by stas on 11.10.19.
//
#include <iostream>
#include <string.h>
#include <cctype>

#include "../Iterator/Iterator.h"
#include "../linkedList/LinkedList.h"

using namespace std;

int main(){
    LinkedList list;
    list.PushBack(5);
    list.PushBack(1);
    Iterator iterator(list.GetIterator());

    while (iterator.HasNext()){
        std::cout << iterator.Next() << '\n';
    }
}