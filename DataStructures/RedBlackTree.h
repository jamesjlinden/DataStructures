#pragma once
#include "pch.h"

class RedBlackTree {
public:

    RedBlackTree();
    ~RedBlackTree();
    void Insert(int element);
    void Clear();

    // Printing functions that need mRoot:
    void Print(); 

private:
    class Node;

    void PrintInOrderTraversal(std::shared_ptr<Node> node); // Needs mRoot

    std::shared_ptr<Node> mRoot;

    class Node
    {
    public:
        Node(int value);
        ~Node() = default;
        void SetAsLeftChildOf(std::shared_ptr<Node> parent);
        void SetAsRightChildOf(std::shared_ptr<Node> parent);

        int mValue = 0;
        std::shared_ptr<Node> mLeft = 0;
        std::shared_ptr<Node> mRight = 0;
        std::shared_ptr<Node> mParent = 0;
    private:
    };
};

void RunRedBlackTreeTests();
