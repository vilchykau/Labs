//
// Created by stas on 23.10.19.
//

#include <iostream>
#include <string>
#include "TreeMap.h"

int main(){
    TreeMap<int, std::string> map;
    std::string str = "55";
    map.Set(55, str);
    std::cout << "Map: " << map.Get(55);
    int g = 1;
    return 0;
}