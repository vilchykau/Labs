//
// Created by stas on 15.10.19.
//
#include <iostream>
#import "LinkedList.h"

#include "../Iterator/Iterator.h"

using namespace std;

int main(){
    LinkedList list;
    list.PushBack(5);
    list.PushBack(1);
    Iterator iterator(list.GetIterator());

    while (iterator.HasNext()){
        std::cout << "F: " << iterator.Next() << '\n';
    }
}