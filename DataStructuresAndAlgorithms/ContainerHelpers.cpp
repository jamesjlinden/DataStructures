#include "pch.h"
#include "ContainerHelpers.h"
#include <iostream>
#include <vector>

using namespace std;

template<typename IteratorType>
void PrintContainer(IteratorType begin, IteratorType end)
{
    for (auto iter = begin; iter != end; ++iter)
        cout << *iter << " ";
    cout << endl;
}

template<typename IteratorType>
string ContainerToString(IteratorType begin, IteratorType end)
{
    string str = "";
    for (auto iter = begin; iter != end; ++iter)
        str.append(to_string(*iter)).append(" ");
    return str;
}

template void PrintContainer<std::vector<int>::iterator>(std::vector<int>::iterator begin, 
    std::vector<int>::iterator end);

template string ContainerToString<std::vector<int>::iterator>(std::vector<int>::iterator begin, 
    std::vector<int>::iterator end);
