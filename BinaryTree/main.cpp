//
// Created by stas on 23.10.19.
//

#include <iostream>
#include <string>
#include <fstream>

#include "BinaryTree.h"


int main(){
    BinaryTree<int> tree;

    std::ifstream file("input.txt");

    int value;

    while (file >> value){
        tree.Add(value);
    }

    std::cout << tree.ToString();
    return 0;
}