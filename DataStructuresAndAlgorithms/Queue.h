#pragma once
#include "pch.h"

// Queue as implemented with an array (linked list implementation is also possible).

template <typename T>
class Queue
{
public:
    Queue();

    ~Queue();

    int GetCount();

    int GetCapacity();

    T* GetFront();

    T* GetBack();

    void Push(T element);

    T* Pop();

    void Clear();

private:
    void GrowContainer();

    T* container_;
    int elementCount_;
    int elementCapacity_;
    int frontIndex_;
    int backIndex_;
};

void RunQueueDriver();