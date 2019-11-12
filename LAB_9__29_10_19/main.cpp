//
// Created by stas on 29.10.19.
// 3

#include "BinaryTreeIterator.h"
#include <iostream>

int main(){
    BinaryTree<int> tree;

    tree.Add(5);
    tree.Add(3);
    tree.Add(1);
    tree.Add(7);

    BinaryTreeIterator iterator(tree);
    return 0;
}