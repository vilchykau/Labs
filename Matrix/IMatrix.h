//
// Created by stas on 1.11.19.
//

#ifndef LABS_IMATRIX_H
#define LABS_IMATRIX_H
template <typename T>
class IMatrix{
    virtual T Get(int x, int y);
};
#endif //LABS_IMATRIX_H
