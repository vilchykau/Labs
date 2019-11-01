//
// Created by stas on 1.11.19.
//

#ifndef LABS_IMATRIX_H
#define LABS_IMATRIX_H
template <typename T>
class IMatrix{
public:
    virtual T Get(int x, int y) const {
        return T();
    }

    virtual void Set(T value, int x, int y){};

    virtual T*operator[](int x){ return nullptr;};
};
#endif //LABS_IMATRIX_H
