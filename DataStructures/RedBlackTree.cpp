#include "pch.h"
#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree() {

}

RedBlackTree::~RedBlackTree() {

}

void RedBlackTree::Insert(int element) {
    if (mRoot == nullptr) {
        mRoot = std::make_shared<Node>(element);
    }
}

void RedBlackTree::Clear() {
    // Reset all of the shared_ptrs for nodes ...
}

void RedBlackTree::Print() {
    PrintInOrderTraversal(mRoot);
}

void RedBlackTree::PrintInOrderTraversal(shared_ptr<Node> node) {
    // In-order traversal
    if (node->mLeft != nullptr) {
        PrintInOrderTraversal(node->mLeft);
    }

    cout << node->mValue << " ";

    if (node->mRight != nullptr) {
        PrintInOrderTraversal(node->mRight);
    }
}

RedBlackTree::Node::Node(int value) 
    : mValue(value) {
}

void RedBlackTree::Node::SetAsLeftChildOf(shared_ptr<Node> parent) {
    if (parent.get() == this) {
        throw invalid_argument("A Node was assigned to be a child of itself.");
    }

    parent->mLeft = make_shared<Node>(*this);
    mParent = parent;
}

void RedBlackTree::Node::SetAsRightChildOf(shared_ptr<Node> parent) {
    if (parent.get() == this) {
        throw invalid_argument("A Node was assigned to be a child of itself.");
    }

    parent->mRight = make_shared<Node>(*this);
    mParent = parent;
}

void RunRedBlackTreeTests() {
    RedBlackTree tree;
    tree.Insert(3);
    tree.Print();
}
