//
// Created by stas on 23.10.19.
//

#ifndef LABS_BINARYTREE_H
#define LABS_BINARYTREE_H

template <typename T>
struct TreeElement{
    T value;
    TreeElement* left;
    TreeElement* right;

};


template <typename T>
class BinaryTree{
public:
    BinaryTree():root(nullptr){};

    void Add(T new_value){
        AddToNode(new_value);
    }

    std::string ToString(){
        return ToString(root);
    }

private:
    std::string ToString(TreeElement<T>* element){
        std::string out = "";

        if(element->left){
            out += ToString(element->left);
        }
        out += std::to_string(element->value) + " ";
        if(element->right){
            out += ToString(element->right);
        }

        return out;
    }


    void AddToNode(T new_value){
        TreeElement<T>** p = &root;

        while(*p != nullptr){
            TreeElement<T>* now_element = *p;
            if(now_element->value > new_value){
                p = &now_element->left;
            }else if(now_element->value < new_value){
                p = &now_element->right;
            }else{
                return;
            }
        }

        TreeElement<T>* new_element = new TreeElement<T>{new_value, nullptr, nullptr};
        (*p) = new_element;
    }

    TreeElement<T>* root;
};



#endif //LABS_BINARYTREE_H
