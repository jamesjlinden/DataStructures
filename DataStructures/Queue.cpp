#include "pch.h"
#include "Queue.h"
#include <iostream>

// Queue as implemented with an array (linked list implementation is also possible).

using namespace std;

template <typename T>
Queue<T>::Queue() : elementCount_(0), elementCapacity_(0), frontIndex_(0), backIndex_(0), container_(0)
{
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] container_;
}

template <typename T>
int Queue<T>::GetCount() { return elementCount_; }

template <typename T>
int Queue<T>::GetCapacity() { return elementCapacity_; }

template <typename T>
T* Queue<T>::GetFront() { return container_[frontIndex_]; }

template <typename T>
T* Queue<T>::GetBack() { return container_[backIndex_]; }

template <typename T>
void Queue<T>::Push(T element)
{
    if (elementCount_ == elementCapacity_)
        GrowContainer();

    int indexToInsertAt = (frontIndex_ + elementCount_) % elementCapacity_;
    container_[indexToInsertAt] = element;
    backIndex_ = indexToInsertAt;

    ++elementCount_;
}

template <typename T>
T* Queue<T>::Pop()
{
    if (elementCount_ == 0)
        return 0;

    // Get the element we're popping
    T* elementToPop = &container_[frontIndex_];

    // Get next front index
    int nextFrontIndex = (frontIndex_ + 1) % elementCapacity_;
    frontIndex_ = nextFrontIndex;

    // Decrement count
    --elementCount_;

    return elementToPop;
}

template <typename T>
void Queue<T>::Clear()
{
    while (elementCount_ > 0)
        Pop();
}

template <typename T>
void Queue<T>::GrowContainer()
{
    int oldCapacity = elementCapacity_;
    // Double elementCapacity by power of 2 if non-zero, otherwise increment to 1.
    elementCapacity_ = elementCapacity_ == 0 ? 1 : elementCapacity_ << 1;

    // Allocate new array
    T* newContainer = new T[elementCapacity_];

    // Copy elements from old array into new array
    for (int i = 0; i < elementCount_; ++i)
    {
        int containerIndexRelativeToFront = (frontIndex_ + i) % elementCount_;

        // elementCount is guaranteed to be smaller than elementCapacity since we immediately increment
        // capacity to the next power of 2 any time elementCount == elementCapacity. This warning can be disregarded.
        newContainer[i] = container_[containerIndexRelativeToFront]; 
    }

    // Set front and back to new array's beginning and ending
    frontIndex_ = 0;
    backIndex_ = ((elementCount_ - 1) < 0) ? 0 : (elementCount_ - 1);

    delete[] container_;
    container_ = newContainer;
}

void RunQueueDriver()
{
    Queue<int> queue;

    // Testing Push() on empty Queue
    std::cout << "Pushing 3, 7, 2" << std::endl;

    queue.Push(3);
    queue.Push(7);
    queue.Push(2);

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    // Testing Pop() on populated Queue
    std::cout << "Pop() result = " << *queue.Pop() << std::endl;
    std::cout << "Pop() result = " << *queue.Pop() << std::endl;
    std::cout << "Pop() result = " << *queue.Pop() << std::endl;

    // Testing Pop() on empty Queue
    bool popResult = queue.Pop() != 0;
    std::cout << "Pop() result = " << popResult << std::endl;

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    // Testing Push() on a Queue that had all elements popped
    std::cout << "Pushing 2, 1, 4, 7" << std::endl;

    queue.Push(2);
    queue.Push(1);
    queue.Push(4);
    queue.Push(7);

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    // Testing Pop() to cause the queue to wrap around on next Push()
    std::cout << "Pop() result = " << *queue.Pop() << std::endl;
    std::cout << "Pop() result = " << *queue.Pop() << std::endl;

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    std::cout << std::endl;

    std::cout << "Pushing 3" << std::endl;
    queue.Push(3);

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    // Testing Pop() to check our pop order is correct now the queue wrapped around in memory
    std::cout << "Pop() result = " << *queue.Pop() << std::endl;
    std::cout << "Pop() result = " << *queue.Pop() << std::endl;
    std::cout << "Pop() result = " << *queue.Pop() << std::endl;

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    // Testing Push() with big example
    std::cout << "Pushing 1 ... 100" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        queue.Push(i + 1);
    }

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    std::cout << std::endl;

    // Testing Clear()
    std::cout << "Popping all items..." << std::endl;
    queue.Clear();

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    std::cout << std::endl;

    // Testing Push() with an even bigger example
    std::cout << "Pushing 1 ... 1000" << std::endl;
    for (int i = 0; i < 1000; ++i)
    {
        queue.Push(i + 1);
    }

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;

    std::cout << std::endl;

    std::cout << "Popping all items..." << std::endl;
    queue.Clear();

    std::cout << "Count: " << queue.GetCount() << std::endl;
    std::cout << "Capacity: " << queue.GetCapacity() << std::endl;
}
