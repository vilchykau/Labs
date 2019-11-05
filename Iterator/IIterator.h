//
// Created by stas on 1.11.19.
//

#ifndef LABS_IITERATOR_H
#define LABS_IITERATOR_H

template <typename T>
class IIterator{
public:
    virtual bool HasNext(){ return false;};

    virtual T Next(){ return T();};
};

#endif //LABS_IITERATOR_H
