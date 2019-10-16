//
// Created by stas on 11.10.19.
//

#include <iostream>

template <typename T>
class DArray{
public:
    DArray(int new_size){
        size = new_size;
        array = new T[size];
    }

    ~DArray(){
        delete[] array;
    }

    int& operator[](int i){
        return array[i];
    }

    int GetSize(){
        return size;
    }

    int CopyTo(T* target, int start, int len){
        for(int i = start; i < start + len; ++i){
            target[i - start] = array[i];
        }
    }

    void Fill(T f){
        for(int i = 0; i < size; ++i){
            array[i] = f;
        }
    }

private:
    int size;
    T* array;
};

int main(){
    DArray<int> tt(5);
    DArray<int> t2(10);

    tt.CopyTo(&t2[3], 4, 2);

    for(int i = 0;i < 10; ++i){
        std::cout << tt[i] << ' ';
    }

    return 0;
}