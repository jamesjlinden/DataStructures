#pragma once

template <typename T>
class SinglyLinkedList
{
public:
    class Iterator;
    class Node;

    SinglyLinkedList();

    ~SinglyLinkedList();

    int GetCount();

    Iterator GetBegin();

    Iterator GetEnd();

    void PushFront(T element);

    void PushBack(T element);

    T PopFront();

    void Clear();

    T PopBack();

    void Remove(T element);

    class Iterator
    {
    public:
        Iterator(Node* node);

        bool operator==(const Iterator& rhs);

        bool operator!=(const Iterator& rhs);

        bool operator++();

        T& operator*();

    private:
        Node* node_;
    };

private:
    Node* front_;
    Node* back_;
    int elementsCount_;

    class Node
    {
    public:
        Node(T data) : data_(data) {}

        T data_;
        Node* next_;
    };
};
