#include "pch.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// We will not be treating this in the same manner as a map/dictionary even though that's usually the purpose of a tree.
// This tree can support insert, search, and delete for integers.
// Characters or strings may be supported in the future.
// This class is only for educational purposes.

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
    Clear();
}

void BinarySearchTree::Insert(int element)
{
    Node* newNode = new Node(element);

    if (root == 0)
        root = newNode;
    else
        InsertNodeRecursively(newNode, root);
}

template <typename T>
void BinarySearchTree::Insert(initializer_list<T> elements)
{
    for (auto element : elements)
    {
        Insert(element);
    }
}

int* BinarySearchTree::Search(int value)
{
    Node* result = SearchRecursively(value, root);
    return result ? &result->value : 0;
}

void BinarySearchTree::Delete(int element)
{
    DeleteNodeRecursively(element, root);
}

void BinarySearchTree::Clear()
{
    if (root)
    {
        ClearNodeRecursively(root);
        root = 0;
    }
}

void BinarySearchTree::PrintInOrderTraversal()
{
    cout << "Printing tree..." << endl;
    PrintNodesInOrderTraversal(root);
    cout << endl;
}

void BinarySearchTree::PrintGraphically()
{
    cout << "Printing tree..." << endl;
    PrintNodesGraphically(root);
    cout << endl;
}

void BinarySearchTree::InsertNodeRecursively(Node* nodeToInsert, Node* currNode)
{
    if (nodeToInsert->value == currNode->value)
        throw invalid_argument("Can't insert a duplicate value in a binary search tree.");

    if (nodeToInsert->value > currNode->value)
    {
        // Recurse right if node available
        if (currNode->right != 0)
            InsertNodeRecursively(nodeToInsert, currNode->right);
        else
            nodeToInsert->SetAsRightChildOf(currNode);
    }
    else
    {
        if (currNode->left != 0)
            InsertNodeRecursively(nodeToInsert, currNode->left);
        else
            nodeToInsert->SetAsLeftChildOf(currNode);
    }
}

BinarySearchTree::Node* BinarySearchTree::SearchRecursively(int value, Node* currNode)
{
    if (!currNode)
        return currNode;
    else if (currNode->value == value)
        return currNode;
    else if (value < currNode->value && currNode->left)
        return SearchRecursively(value, currNode->left);
    else if (value > currNode->value&& currNode->right)
        return SearchRecursively(value, currNode->right);

    return 0;
}

int BinarySearchTree::DeleteNodeRecursively(int value, Node* currNode)
{
    if (currNode->value == value)
    {
        Node* nodeToDelete = currNode;
        Node* nodeToPromote = 0;

        if (nodeToDelete->left && !nodeToDelete->right)
        {
            nodeToPromote = nodeToDelete->left;
            if (nodeToDelete->parent)
                nodeToPromote->SetAsRightChildOf(nodeToDelete->parent);
        }
        else if (!nodeToDelete->left && nodeToDelete->right)
        {
            nodeToPromote = nodeToDelete->right;
            if (nodeToDelete->parent)
                nodeToPromote->SetAsLeftChildOf(nodeToDelete->parent);
        }
        else if (nodeToDelete->left && nodeToDelete->right)
        {
            // Try to get right most leaf in left subtree, otherwise, we promote left child
            nodeToPromote = nodeToDelete->left;
            while (nodeToPromote->right != 0)
                nodeToPromote = nodeToPromote->right;

            if (nodeToPromote != nodeToDelete->left)
            {
                // We only worry about a left subtree since the rightmost child won't have a right subtree 
                // by definition
                Node* secondaryNodeToPromote = nodeToPromote->left;
                if (secondaryNodeToPromote)
                    secondaryNodeToPromote->SetAsRightChildOf(nodeToPromote->parent);
                nodeToDelete->left->SetAsLeftChildOf(nodeToPromote);
            }

            nodeToDelete->right->SetAsRightChildOf(nodeToPromote);

            if (nodeToDelete->parent != 0)
                nodeToPromote->SetAsRightChildOf(nodeToDelete->parent);
        }

        if (nodeToDelete == root && nodeToPromote)
            root = nodeToPromote;
        delete nodeToDelete;
    }
    else
    {
        if (value < currNode->value && currNode->left)
            DeleteNodeRecursively(value, currNode->left);
        if (value > currNode->value&& currNode->right)
            DeleteNodeRecursively(value, currNode->right);
    }

    return 0;
}

void BinarySearchTree::ClearNodeRecursively(Node* node)
{
    if (!node)
        return;
    if (node->left)
        ClearNodeRecursively(node->left);
    if (node->right)
        ClearNodeRecursively(node->right);
    delete node;
}

void BinarySearchTree::PrintNodesInOrderTraversal(Node* node)
{
    if (node->left)
        PrintNodesInOrderTraversal(node->left);
    cout << node->value << " ";
    if (node->right)
        PrintNodesInOrderTraversal(node->right);
}

void BinarySearchTree::PrintNodesGraphically(Node* node)
{
    cout << "Node: " << node->value
        << "  Left: " << (node->left != 0 ? to_string(node->left->value) : "Null")
        << "  Right: " << (node->right != 0 ? to_string(node->right->value) : "Null")
        << "  Parent: " << (node->parent != 0 ? to_string(node->parent->value) : "Null") << endl;
    if (node->left)
        PrintNodesGraphically(node->left);
    if (node->right)
        PrintNodesGraphically(node->right);
}

BinarySearchTree::Node::Node(int value) : value(value) {}

BinarySearchTree::Node::~Node()
{
    if (parent)
    {
        if (parent->left == this)
            parent->left = 0;
        if (parent->right == this)
            parent->right = 0;
    }

    if (left && left->parent == this)
        left->parent = 0;
    if (right && right->parent == this)
        right->parent = 0;
}

void BinarySearchTree::Node::SetAsLeftChildOf(Node* newParent)
{
    if (parent == this)
        throw invalid_argument("A node cannot be its own child.");

    newParent->left = this;
    parent = newParent;
}

void BinarySearchTree::Node::SetAsRightChildOf(Node* newParent)
{
    if (parent == this)
        throw invalid_argument("A node cannot be its own child.");

    newParent->right = this;
    parent = newParent;
}

void Test1(BinarySearchTree& tree)
{
    cout << "Testing Insert..." << endl;

    cout << "Insert(3)" << endl;
    tree.Insert(3);
    tree.PrintGraphically();

    cout << "Insert(2, 7)" << endl;
    tree.Insert(2);
    tree.Insert(7);
    tree.PrintGraphically();

    cout << "Insert(9, 4, 8, 1, 5, 6, 0)" << endl;
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

void Test2(BinarySearchTree& tree)
{
    cout << "Testing Case 1 of Delete..." << endl;
    tree.Insert({ 44, 17, 88, 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    cout << "Delete(97)" << endl;
    tree.Delete(97);
    tree.PrintGraphically();

    tree.Clear();
}

void Test3(BinarySearchTree& tree)
{
    cout << "Testing Case 2 of Delete..." << endl;
    tree.Insert({ 44, 17, 88, 65, 82, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    cout << "Delete(65)" << endl;
    tree.Delete(65);
    tree.PrintGraphically();

    tree.Clear();
}

void Test4(BinarySearchTree& tree)
{
    cout << "Testing Case 3 of Delete..." << endl;
    tree.Insert({ 44, 17, 88, 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    cout << "Delete(88)" << endl;
    tree.Delete(88);
    tree.PrintGraphically();

    tree.Clear();
}

void Test5(BinarySearchTree& tree)
{
    cout << "Testing Case 4 of Delete..." << endl;
    tree.Insert({ 44, 17, 88, 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    cout << "Delete(80)" << endl;
    tree.Delete(80);
    tree.PrintGraphically();

    tree.Clear();
}

void Test6(BinarySearchTree& tree)
{
    cout << "Testing Delete on root..." << endl;
    tree.Insert({ 44, 17, 88 });
    tree.PrintGraphically();
    cout << "Delete(44)" << endl;
    tree.Delete(44);
    cout << "Insert(65, 82, 54, 76, 68, 80, 97, 93)" << endl;
    tree.Insert({ 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    cout << "Delete(17)" << endl;
    tree.Delete(17);
    tree.PrintGraphically();

    tree.Clear();
}

void Test7(BinarySearchTree& tree)
{
    cout << "Testing Search..." << endl;

    tree.Insert({ 44, 17, 88, 65, 82, 54, 76, 68, 80, 97, 93 });
    tree.PrintGraphically();
    cout << "Search(88)" << endl;
    int* result = tree.Search(88);
    cout << "Result = " + (result ? to_string(*result) : "Null") << endl;
    cout << "Search(13)" << endl;
    result = tree.Search(13);
    cout << "Result = " + (result ? to_string(*result) : "Null") << endl;
    cout << "Search(44)" << endl;
    result = tree.Search(44);
    cout << "Result = " + (result ? to_string(*result) : "Null") << endl;

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
