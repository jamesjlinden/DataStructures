#pragma once
#include "pch.h"
#include <iostream>

template<typename T>
class DynamicArray
{
public:
    DynamicArray() : elementCount_(0), elementCapacity_(0)
    {
    }

    DynamicArray(DynamicArray<T> &other) : elementCount_(0), elementCapacity_(0)
    {
        for (int i = 0; i << other.GetCount(); ++i)
        {
            PushBack(other[i]);
        }
    }

    ~DynamicArray()
    {
        delete[] container_;
    }

    int operator[](int i)
    {
        return container_[i];
    }

    int GetCount() { return elementCount_; }
    int GetCapacity() { return elementCapacity_; }

    void PushBack(T element)
    {
        if (elementCount_ == elementCapacity_)
            GrowContainer();

        container_[elementCount_] = element;
        ++elementCount_;
    }

    void PopBack()
    {
        if (elementCount_ == 0) return;
        --elementCount_;
    }

    void Clear()
    {
        if (container_ != 0)
        {
            delete[] container_;
        }
        elementCount_ = elementCapacity_ = 0;
    }

private:
    void GrowContainer()
    {
        int oldCapacity = elementCapacity_;
        // Double elementCapacity by power of 2 if non-zero, otherwise increment to 1.
        elementCapacity_ = elementCapacity_ == 0 ? 1 : elementCapacity_ << 1;

        // Allocate new array
        auto newContainer = new T[elementCapacity_];

        // Copy elements from old array into new array
        for (int i = 0; i < oldCapacity; ++i)
        {
            newContainer[i] = container_[i];
        }

        delete[] container_;
        container_ = newContainer;
    }

    T *container_;
    int elementCount_;
    int elementCapacity_;
};

void RunDynamicArrayDriver()
{
    DynamicArray<int> dynamicArray;
    std::cout << "Count: " << dynamicArray.GetCount() << std::endl;
    std::cout << "Capacity: " << dynamicArray.GetCapacity() << std::endl;

    std::cout << "Pushing back (3)" << std::endl;
    dynamicArray.PushBack(3);
    std::cout << dynamicArray[0] << std::endl;

    std::cout << "Count: " << dynamicArray.GetCount() << std::endl;
    std::cout << "Capacity: " << dynamicArray.GetCapacity() << std::endl;

    std::cout << "Pushing back (2, 7, 5, 8, 9)" << std::endl;
    dynamicArray.PushBack(2);
    dynamicArray.PushBack(7);
    dynamicArray.PushBack(5);
    dynamicArray.PushBack(8);
    dynamicArray.PushBack(9);
    for (int i = 0; i < dynamicArray.GetCount(); ++i)
    {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Count: " << dynamicArray.GetCount() << std::endl;
    std::cout << "Capacity: " << dynamicArray.GetCapacity() << std::endl;

    std::cout << "Popping back an element" << std::endl;
    dynamicArray.PopBack();
    for (int i = 0; i < dynamicArray.GetCount(); ++i)
    {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Count: " << dynamicArray.GetCount() << std::endl;
    std::cout << "Capacity: " << dynamicArray.GetCapacity() << std::endl;

    std::cout << "Popping back 10 elements" << std::endl;
    for (int i = 0; i < 10; ++i)
        dynamicArray.PopBack();

    std::cout << "Printing container:" << std::endl;
    for (int i = 0; i < dynamicArray.GetCount(); ++i)
    {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Count: " << dynamicArray.GetCount() << std::endl;
    std::cout << "Capacity: " << dynamicArray.GetCapacity() << std::endl;

    std::cout << "Pushing back (2, 7, 5, 8, 9)" << std::endl;
    dynamicArray.PushBack(2);
    dynamicArray.PushBack(7);
    dynamicArray.PushBack(5);
    dynamicArray.PushBack(8);
    dynamicArray.PushBack(9);
    for (int i = 0; i < dynamicArray.GetCount(); ++i)
    {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Count: " << dynamicArray.GetCount() << std::endl;
    std::cout << "Capacity: " << dynamicArray.GetCapacity() << std::endl;
}