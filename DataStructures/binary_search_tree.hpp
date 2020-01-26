#include "pch.h"
#include <iostream>
#include <stdexcept>
#include <string>

// We will not be treating this in the same manner as a map/dictionary even though that's usually the purpose of a tree.
// This tree can support insert, search, and delete for integers.
// Characters or strings may be supported in the future.
// This class is only for educational purposes.

class BinarySearchTree
{
public:
    BinarySearchTree()
    {
    }

    ~BinarySearchTree()
    {
        Clear();
    }

    void Insert(int element)
    {
        Node *newNode = new Node(element);

        if (root_ == 0)
            root_ = newNode;
        else
            InsertNodeRecursively(newNode, root_);
    }

    template <typename T>
    void Insert(std::initializer_list<T> elements)
    {
        for (auto element : elements)
        {
            Insert(element);
        }
    }

    int * Search(int value)
    {
        Node *result = SearchRecursively(value, root_);
        return result ? &result->value_ : 0;
    }

    void Delete(int element)
    {
        DeleteNodeRecursively(element, root_);
    }

    void Clear()
    {
        if (root_)
        {
            ClearNodeRecursively(root_);
            root_ = 0;
        }
    }

    void PrintInOrderTraversal()
    {
        std::cout << "Printing tree..." << std::endl;
        PrintNodesInOrderTraversal(root_);
        std::cout << std::endl;
    }

    void PrintGraphically()
    {
        std::cout << "Printing tree..." << std::endl;
        PrintNodesGraphically(root_);
        std::cout << std::endl;
    }
private:
    class Node;

    void InsertNodeRecursively(Node *nodeToInsert, Node *currNode)
    {
        if (nodeToInsert->value_ == currNode->value_)
            throw std::invalid_argument("Can't insert a duplicate value in a binary search tree.");

        if (nodeToInsert->value_ > currNode->value_)
        {
            // Recurse right if node available
            if (currNode->right_ != 0)
                InsertNodeRecursively(nodeToInsert, currNode->right_);
            else
                nodeToInsert->SetAsRightChildOf(currNode);
        }
        else
        {
            if (currNode->left_ != 0)
                InsertNodeRecursively(nodeToInsert, currNode->left_);
            else
                nodeToInsert->SetAsLeftChildOf(currNode);
        }
    }

    Node* SearchRecursively(int value, Node* currNode)
    {
        if (!currNode)
            return currNode;
        else if (currNode->value_ == value)
            return currNode;
        else if (value < currNode->value_ && currNode->left_)
            return SearchRecursively(value, currNode->left_);
        else if (value > currNode->value_&& currNode->right_)
            return SearchRecursively(value, currNode->right_);

        return 0;
    }

    int DeleteNodeRecursively(int value, Node *currNode)
    {
        if (currNode->value_ == value)
        {
            Node *nodeToDelete = currNode;
            Node *nodeToPromote = 0;

            // Delete node
            if (nodeToDelete->left_ && !nodeToDelete->right_)
            {
                nodeToPromote = nodeToDelete->left_;
                if (nodeToDelete->parent_)
                    nodeToPromote->SetAsRightChildOf(nodeToDelete->parent_);
                delete nodeToDelete;
            }
            else if (!nodeToDelete->left_ && nodeToDelete->right_)
            {
                nodeToPromote = nodeToDelete->right_;
                if (nodeToDelete->parent_)
                    nodeToPromote->SetAsLeftChildOf(nodeToDelete->parent_);
                delete nodeToDelete;
            }
            else if (nodeToDelete->left_ && nodeToDelete->right_)
            {
                // Try to get right most leaf in left subtree, otherwise, we promote left child
                nodeToPromote = nodeToDelete->left_;
                while (nodeToPromote->right_ != 0)
                    nodeToPromote = nodeToPromote->right_;

                if (nodeToPromote != nodeToDelete->left_)
                {
                    // We only worry about a left subtree since the rightmost child won't have a right subtree 
                    // by definition
                    Node *secondaryNodeToPromote = nodeToPromote->left_;
                    if (secondaryNodeToPromote)
                        secondaryNodeToPromote->SetAsRightChildOf(nodeToPromote->parent_);
                    nodeToDelete->left_->SetAsLeftChildOf(nodeToPromote);
                }
                
                nodeToDelete->right_->SetAsRightChildOf(nodeToPromote);
                    
                if (nodeToDelete->parent_ != 0)
                    nodeToPromote->SetAsRightChildOf(nodeToDelete->parent_);
                if (nodeToDelete == root_)
                    root_ = nodeToPromote;

                delete nodeToDelete;
            }
            else
            {
                delete nodeToDelete;
            }
        }
        else
        {
            if (value < currNode->value_ && currNode->left_)
                DeleteNodeRecursively(value, currNode->left_);
            if (value > currNode->value_ && currNode->right_)
                DeleteNodeRecursively(value, currNode->right_);
        }

        return 0;
    }

    void ClearNodeRecursively(Node *node)
    {
        if (!node)
            return;
        if (node->left_)
            ClearNodeRecursively(node->left_);
        if (node->right_)
            ClearNodeRecursively(node->right_);
        delete node;
    }

    void PrintNodesInOrderTraversal(Node *node)
    {
        if (node->left_)
            PrintNodesInOrderTraversal(node->left_);
        std::cout << node->value_ << " ";
        if (node->right_)
            PrintNodesInOrderTraversal(node->right_);
    }

    void PrintNodesGraphically(Node *node)
    {
        std::cout << "Node: " << node->value_ 
            << "  Left: " << (node->left_ != 0 ? std::to_string(node->left_->value_) : "Null")
            << "  Right: " << (node->right_ != 0 ? std::to_string(node->right_->value_) : "Null")
            << "  Parent: " << (node->parent_ != 0 ? std::to_string(node->parent_->value_) : "Null") << std::endl;
        if (node->left_)
            PrintNodesGraphically(node->left_);
        if (node->right_)
            PrintNodesGraphically(node->right_);
    }

    Node *root_;

    class Node 
    {
    public:
        Node(int value) : value_(value) {}
        ~Node() 
        {
            if (parent_)
            {
                if (parent_->left_ == this)
                    parent_->left_ = 0;
                if (parent_->right_ == this)
                    parent_->right_ = 0;
            }

            if (left_ && left_->parent_ == this)
                left_->parent_ = 0;
            if (right_ && right_->parent_ == this)
                right_->parent_ = 0;
        }

        void SetAsLeftChildOf(Node *parent)
        {
            if (parent == this)
                throw std::invalid_argument("A node cannot be its own child.");

            parent->left_ = this;
            parent_ = parent;
        }

        void SetAsRightChildOf(Node *parent)
        {
            if (parent == this)
                throw std::invalid_argument("A node cannot be its own child.");

            parent->right_ = this;
            parent_ = parent;
        }

        int value_;
        Node* left_;
        Node* right_;
        Node* parent_;
    private:
    };
};

void Test1(BinarySearchTree &tree)
{
    std::cout << "Testing Insert..." << std::endl;

    std::cout << "Insert(3)" << std::endl;
    tree.Insert(3);
    tree.PrintGraphically();

    std::cout << "Insert(2, 7)" << std::endl;
    tree.Insert(2);
    tree.Insert(7);
    tree.PrintGraphically();

    std::cout << "Insert(9, 4, 8, 1, 5, 6, 0)" << std::endl;
    tree.Insert(9);
    tree.Insert(4);
    tree.Insert(8);
    tree.Insert(1);
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(0);
    tree.PrintGraphically();

    tree.Clear();
}

void Test2(BinarySearchTree &tree)
{
    std::cout << "Testing Case 1 of Delete..." << std::endl;
    tree.Insert({ 44, 17, 88, 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    std::cout << "Delete(97)" << std::endl;
    tree.Delete(97);
    tree.PrintGraphically();

    tree.Clear();
}

void Test3(BinarySearchTree &tree)
{
    std::cout << "Testing Case 2 of Delete..." << std::endl;
    tree.Insert({ 44, 17, 88, 65, 82, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    std::cout << "Delete(65)" << std::endl;
    tree.Delete(65);
    tree.PrintGraphically();

    tree.Clear();
}

void Test4(BinarySearchTree &tree)
{
    std::cout << "Testing Case 3 of Delete..." << std::endl;
    tree.Insert({ 44, 17, 88, 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    std::cout << "Delete(88)" << std::endl;
    tree.Delete(88);
    tree.PrintGraphically();

    tree.Clear();
}

void Test5(BinarySearchTree &tree)
{
    std::cout << "Testing Case 4 of Delete..." << std::endl;
    tree.Insert({ 44, 17, 88, 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    std::cout << "Delete(80)" << std::endl;
    tree.Delete(80);
    tree.PrintGraphically();

    tree.Clear();
}

void Test6(BinarySearchTree &tree)
{
    std::cout << "Testing Delete on root..." << std::endl;
    tree.Insert({ 44, 17, 88 });
    tree.PrintGraphically();
    std::cout << "Delete(44)" << std::endl;
    tree.Delete(44);
    std::cout << "Insert(65, 82, 54, 76, 68, 80, 97, 93)" << std::endl;
    tree.Insert({ 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    std::cout << "Delete(17)" << std::endl;
    tree.Delete(17);
    tree.PrintGraphically();

    tree.Clear();
}

void Test7(BinarySearchTree &tree)
{
    std::cout << "Testing Search..." << std::endl;

    tree.Insert({ 44, 17, 88, 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    std::cout << "Search(88)" << std::endl;
    int *result = tree.Search(88);
    std::cout << "Result = " + (result ? std::to_string(*result) : "Null") << std::endl;
    std::cout << "Search(13)" << std::endl;
    result = tree.Search(13);
    std::cout << "Result = " + (result ? std::to_string(*result) : "Null") << std::endl;
    std::cout << "Search(44)" << std::endl;
    result = tree.Search(44);
    std::cout << "Result = " + (result ? std::to_string(*result) : "Null") << std::endl;

    tree.Clear();
}

void RunBinarySearchTreeDriver()
{
    BinarySearchTree tree;
    Test1(tree);
    Test2(tree);
    Test3(tree);
    Test4(tree);
    Test5(tree);
    Test6(tree);
    Test7(tree);
}
