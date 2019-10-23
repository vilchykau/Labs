//
// Created by stas on 23.10.19.
//

#include <iostream>
#include <string>
#include <fstream>

#include "BinaryTree.h"


int main(){
    BinaryTree<int> tree;

    tree.Add(6);
    tree.Add(4);
    tree.Add(5);

    tree.Remove(4);

    std::cout << tree << "\n" << tree.IsContains(0);
    return 0;
}