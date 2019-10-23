//
// Created by stas on 11.10.19.
//
#include <iostream>

bool IsPolly(int a){
    int b = 0;
    int a_ = a;
    while(a_ > 0){
        b = a_ % 10 + b * 10;
        a_/= 10;
    }
    return b == a;
}


int main(){
    int num;
    std::cin >> num;
    std::cout << IsPolly(num);
}