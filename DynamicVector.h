//
// Created by tudi1 on 4/5/2019.
//

#ifndef UNTITLED3_DYNAMICVECTOR_H
#define UNTITLED3_DYNAMICVECTOR_H

#endif //UNTITLED3_DYNAMICVECTOR_H

#pragma once
#include "Movie.h"

typedef Movie TElement;

class DynamicVector
{
private:
    TElement * elems;
    int size;
    int capacity;
public:
    DynamicVector(int capacity = 10);

    DynamicVector(const DynamicVector& v);
    ~DynamicVector();

    DynamicVector& operator=(const DynamicVector& v);
    DynamicVector& operator+(const TElement& e);

    void add(const TElement& e);

    int getSize() const;
    TElement* getAllElems() const;
private:
    void resize(double factor = 2);
};