//
// Created by stas on 23.10.19.
//

#include <iostream>
#include <string>
#include "TreeMap.h"

int main(){
    TreeMap<int, std::string> treeMap;
    treeMap.Set(5, "Hello");
    treeMap.Set(4, "world");
    treeMap.Set(6, "!");
    treeMap[8] = "tt";
    treeMap[66] = "What!!";
    treeMap[-1] = "hh";

    auto pairs = treeMap.GetPairs();
    for(auto pair : pairs){
        std::cout << pair.first << " " << pair.second << '\n';
    }
    return 0;
}