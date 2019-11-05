//
// Created by stas on 5.11.19.
//
#pragma once

#include <iostream>

template <typename T>
struct Node{
    T value;
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
class DList {
public:
    DList(){
        start = nullptr;
        end = nullptr;
    }

    ~DList(){
       // Clear();
    }

    void PushFront(T value){
        if(start){
            start = end = new Node<T>{value, nullptr, nullptr};
        }else{
            start = new Node<T>{value, nullptr, start};
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const DList<T> list){
        auto node = list.start;
        while (node){
            stream << node->value << ' ';
            node = node->right;
        }
        return stream;
    }

private:
    void Clear(){
        while (start){
            auto temp = start;
            start = start->left;
            delete temp;
        }
    }

    Node<T>* start;
    Node<T>* end;
};





