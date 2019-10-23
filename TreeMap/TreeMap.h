//
// Created by stas on 23.10.19.
//

#ifndef LABS_TREEMAP_H
#define LABS_TREEMAP_H

#include <vector>

template <typename T_compare, typename T_container>
struct TreeNode{
    T_compare compare;
    T_container container;

    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(T_compare tCompare, T_container tContainer):compare(tCompare), container(tContainer){};
};

template <typename T_compare, typename T_container>
class TreeMap {
public:
    TreeMap():root(nullptr){};

    void Set(T_compare comp, T_container value){
        auto p = &root;

        while(*p){
            if((*p)->compare > comp){
                p = &(*p)->left;
            }else if((*p)->compare < comp){
                p = &(*p)->right;
            } else{
                break;
            }
        }

        if(*p){
            (*p)->container = value;
        }else{
            (*p) = new TreeNode<T_compare, T_container>(comp, value);
        }
    }

    T_container& operator[](const T_compare& index){
        auto p = &root;

        while(*p){
            if((*p)->compare > index){
                p = &(*p)->left;
            }else if((*p)->compare < index){
                p = &(*p)->right;
            } else{
                break;
            }
        }

        if(!(*p)){
            (*p) = new TreeNode<T_compare, T_container>(index, T_container());
        }
        return (*p)->container;
    }

    std::vector<std::pair<T_compare, T_container>> GetPairs(){
        std::vector<std::pair<T_compare, T_container>> pairs;
        GetSubPairs(pairs, root);
        return pairs;
    }


private:
    void GetSubPairs(std::vector<std::pair<T_compare, T_container>>& pairs, TreeNode<T_compare, T_container>* node){
        if(!node){
            return;
        }

        GetSubPairs(pairs, node->left);
        pairs.push_back({node->compare, node->container});
        GetSubPairs(pairs, node->right);
    }

    TreeNode<T_compare, T_container>* root;
};


#endif //LABS_TREEMAP_H