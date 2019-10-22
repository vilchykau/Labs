//
// Created by stas on 11.10.19.
//
#include <fstream>
#include <vector>
#include <iostream>

void find(int n,int pos, int number, std::vector<bool>& map, std::vector<int>& answs){
    if(pos == 0){
        answs.push_back(number);
        return;
    }

    for(int i = (pos == n ? 1 : 0); i < 10; ++i){
        if(!map[i]) {
            map[i] = 1;
            find(n, pos - 1, i + number * 10, map, answs);
            map[i] = 0;
        }
    }
}

int main(){
    int n;
    std::cin >> n;

    std::vector<int> answs;
    std::vector<bool> map(10, 0);

    find(n, n, 0, map, answs);

    for(auto e : answs){
        std::cout << e << '\n';
    }
}