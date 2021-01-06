#pragma once
#include "pch.h"
#include <initializer_list>

// We will not be treating this in the same manner as a map/dictionary even though that's usually the purpose of a tree.
// This tree can support insert, search, and delete for integers.
// Characters or strings may be supported in the future.
// This class is only for educational purposes.

class BinarySearchTree
{
public:
    BinarySearchTree();

    ~BinarySearchTree();

    void Insert(int element);

    template <typename T> void Insert(std::initializer_list<T> elements);

    int* Search(int value);

    void Delete(int element);

    void Clear();

    void PrintInOrderTraversal();

    void PrintGraphically();

private:
    class Node;

    void Insert(Node* nodeToInsert, Node* currNode);

    Node* SearchRecursively(int value, Node* currNode);

    int Delete(int value, Node* currNode);

    void ClearNodeRecursively(Node* node);

    void PrintNodesInOrderTraversal(Node* node);

    void PrintGraphically(Node* node);

    Node* root = 0;

    class Node
    {
    public:
        Node(int value);

        ~Node();

        void SetAsLeftChildOf(Node* parent);

        void SetAsRightChildOf(Node* parent);

        int value = 0;
        Node* left = 0;
        Node* right = 0;
        Node* parent = 0;
    private:
    };
};

void RunBinarySearchTreeDriver();
