#include "pch.h"

template <typename T>
class SinglyLinkedList
{
public:
    class Iterator;
    class Node;
    
    SinglyLinkedList()
    {
    }

    ~SinglyLinkedList()
    {
        while (front_ != 0)
        {
            Node *temp = front_;
            front_ = front_->next_;
            delete temp;
        }
    }

    int GetCount() { return elementsCount_; }

    Iterator GetBegin()
    {
        return Iterator(front_);
    }

    Iterator GetEnd()
    {
        return Iterator(0);
    }

    void PushFront(T element)
    {
        Node *newNode = new Node(element);

        if (front_ == 0)
        {
            front_ = back_ = newNode;
        }
        else
        {
            newNode->next_ = front_;
            front_ = newNode;
        }

        ++elementsCount_;
    }

    void PushBack(T element)
    {
        Node *newNode = new Node(element);

        if (back_ == 0)
        {
            front_ = back_ = newNode;
        }
        else
        {
            back_->next_ = newNode;
            back_ = newNode;
        }

        ++elementsCount_;
    }

    T PopFront()
    {
        Node* nodeToPop = 0;

        if (front_ != 0)
        {
            nodeToPop = front_;
            front_ = front_->next_;
            --elementsCount_;
        }

        return nodeToPop != 0 ? nodeToPop->data_ : 0;
    }

    void Clear()
    {
        while (elementsCount_ > 0)
        {
            PopFront();
        }
    }

    T PopBack()
    {
        Node *nodeToPop = 0;
        
        if (back_ != 0 && front_ != 0)
        {
            nodeToPop = back_;

            // Get node one before back, can't use prev since this is singly linked list:
            if (elementsCount_ > 1)
            {
                Node *newBack = front_;

                while (newBack->next_ != back_)
                {
                    newBack = newBack->next_;
                }

                newBack->next_ = 0;
                back_ = newBack;
            }
            else
            {
                back_ = front_ = 0;
            }

            --elementsCount_;
        }

        return nodeToPop != 0 ? nodeToPop->data_ : 0;
    }

    void Remove(T element)
    {
        if (front_ == 0 || back_ == 0)
            return;

        // If we remove front or back, we need to choose a new front or back
        if (front_ != 0 && front_->data_ == element)
            PopFront();
        else if (back_ != 0 && back_->data_ == element)
            PopBack();
        else
        {
            // Node parent needs to point to node next
            // Removed node needs to be deleted

            Node *parentOfNodeToRemove = front_;
            Node *nodeToRemove = 0;
            while (parentOfNodeToRemove->next_->data_ != element)
            {
                parentOfNodeToRemove = parentOfNodeToRemove->next_;
            }
            
            nodeToRemove = parentOfNodeToRemove->next_;
            parentOfNodeToRemove->next_ = nodeToRemove->next_;

            delete nodeToRemove;

            --elementsCount_;
        }
    }

    class Iterator
    {
    public:
        Iterator(Node * node) : node_(node)
        {
        }

        bool operator==(const Iterator &rhs)
        {
            return this->node_ == rhs.node_;
        }

        bool operator!=(const Iterator &rhs)
        {
            return !((*this) == rhs);
        }

        bool operator++()
        {
            if (node_ != 0)
                node_ = node_->next_;

            return node_ != 0;
        }

        T& operator*()
        {
            if (node_ != 0)
                return node_->data_;
            throw;
        }

    private:
        Node *node_;
    };

private:
    Node *front_;
    Node *back_;
    int elementsCount_;

    class Node
    {
    public:
        Node(T data) : data_(data) {}

        T data_;
        Node *next_;
    };
};

template
<typename T>
void PrintListHelper(SinglyLinkedList<T> &list)
{
    std::cout << "Printing list..." << std::endl;

    if (list.GetCount() > 0)
    {
        for (auto iter = list.GetBegin(); iter != list.GetEnd(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
    }
}

void Test1(SinglyLinkedList<int> &list)
{
    std::cout << "PushFront(3, 5, 7)" << std::endl;
    list.PushFront(3);
    list.PushFront(5);
    list.PushFront(7);
    PrintListHelper(list);


    std::cout << "PopFront()" << std::endl;
    list.PopFront();
    PrintListHelper(list);
}

void Test2(SinglyLinkedList<int> &list)
{
    std::cout << "PushBack(5, 3, 4, 1)" << std::endl;
    list.PushBack(5);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(1);
    PrintListHelper(list);

    std::cout << "PopBack()" << std::endl;
    list.PopBack();
    PrintListHelper(list);

    std::cout << "PopBack()" << std::endl;
    list.PopBack();
    PrintListHelper(list);

    std::cout << "PopBack()" << std::endl;
    list.PopBack();
    PrintListHelper(list);

    std::cout << "PopBack()" << std::endl;
    list.PopBack();
    PrintListHelper(list);
}

void Test3(SinglyLinkedList<int> &list)
{
    std::cout << "PushBack(2, 4, 6, 8)" << std::endl;
    list.PushBack(2);
    list.PushBack(4);
    list.PushBack(6);
    list.PushBack(8);
    PrintListHelper(list);

    std::cout << "Remove(6)" << std::endl;
    list.Remove(6);
    PrintListHelper(list);
}

void RunSinglyLinkedListDriver()
{
    SinglyLinkedList<int> list;

    Test1(list);
    Test2(list);
    Test3(list);
}
