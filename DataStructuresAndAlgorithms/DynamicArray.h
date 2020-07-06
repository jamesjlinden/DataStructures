#pragma once
#include "pch.h"
#include <iostream>
#include <memory>

template<typename T>
class DynamicArray {
public:
    DynamicArray();

    DynamicArray(DynamicArray<T>& other);

    T operator[](int i);

    int GetCount();

    int GetCapacity();

    void PushBack(T element);

    void PopBack();

    void Clear();

private:
    void GrowContainer();

    std::unique_ptr<std::unique_ptr<T>[]> container;
    int elementCount;
    int elementCapacity;
};

void RunDynamicArrayDriver();