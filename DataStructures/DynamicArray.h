#pragma once
#include "pch.h"
#include <iostream>

template<typename T>
class DynamicArray
{
public:
    DynamicArray();

    DynamicArray(DynamicArray<T>& other);

    ~DynamicArray();

    int operator[](int i);

    int GetCount();

    int GetCapacity();

    void PushBack(T element);

    void PopBack();

    void Clear();

private:
    void GrowContainer();

    T* container;
    int elementCount;
    int elementCapacity;
};

void RunDynamicArrayDriver();