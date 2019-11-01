//
// Created by stas on 1.11.19.
//

#ifndef LABS_SOLIDMATRIX_H
#define LABS_SOLIDMATRIX_H

#include <cassert>
#include "IMatrix.h"

template <typename T>
class SolidMatrix : public IMatrix<T>{
public:
    SolidMatrix(int new_n, int new_m){
        n = new_n;
        m = new_m;
        array = new T[n*m];
    }

    ~SolidMatrix(){
        delete[] array;
    }

    T Get(int in_n, int in_m) const override {
        assert(in_n < n);
        assert(in_m < m);
        return array[in_n*m + in_m];
    }

    void Set(T value, int in_n, int in_m) override {
        array[in_n*m + in_m] = value;
    }

    T*operator[](int x) override {
        return &array[x* m];
    }


private:
    T* array;
    int n;
    int m;
};


#endif //LABS_SOLIDMATRIX_H
