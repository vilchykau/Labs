//
// Created by stas on 1.11.19.
//
#include "IMatrix.h"
#include "SolidMatrix.h"
#include "../Iterator/SolidMatrixIterator.h"

#include <iostream>
#include <memory>

int main(){
    std::unique_ptr<IMatrix<int>> matrix(new SolidMatrix<int>(4, 4));
    matrix.get()->Set(10, 2, 3);
    int c = (*matrix.get())[2][3];

    SolidMatrixIterator<int> iterator(*(*SolidMatrix<int>)matrix.get());

    return 0;
}

