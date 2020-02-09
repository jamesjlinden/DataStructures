#pragma once
#include "pch.h"
#include "DynamicArray.h"
#include <iostream>

template<typename T>
DynamicArray<T>::DynamicArray() : elementCount(0), elementCapacity(0)
{
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>& other) : elementCount(0), elementCapacity(0)
{
    for (int i = 0; i << other.GetCount(); ++i)
    {
        PushBack(other[i]);
    }
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] container_;
}

template<typename T>
int DynamicArray<T>::operator[](int i)
{
    return container_[i];
}

template<typename T>
int DynamicArray<T>::GetCount() { return elementCount; }

template<typename T>
int DynamicArray<T>::GetCapacity() { return elementCapacity; }

template<typename T>
void DynamicArray<T>::PushBack(T element)
{
    if (elementCount_ == elementCapacity)
        GrowContainer();

    container_[elementCount] = element;
    ++elementCount;
}

template<typename T>
void DynamicArray<T>::PopBack()
{
    if (elementCount_ == 0) return;
    --elementCount;
}

template<typename T>
void DynamicArray<T>::Clear()
{
    if (container != 0)
    {
        delete[] container;
    }
    elementCount = elementCapacity_ = 0;
}

template<typename T>
void DynamicArray<T>::GrowContainer()
{
    int oldCapacity = elementCapacity;
    // Double elementCapacity by power of 2 if non-zero, otherwise increment to 1.
    elementCapacity = elementCapacity == 0 ? 1 : elementCapacity << 1;

    // Allocate new array
    auto newContainer = new T[elementCapacity];

    // Copy elements from old array into new array
    for (int i = 0; i < oldCapacity; ++i)
    {
        newContainer[i] = container[i];
    }

    delete[] container;
    container = newContainer;
}

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