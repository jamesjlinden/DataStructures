#include "pch.h"
#include "MergeSort.h"
#include <iostream>
#include <string>

using namespace std;

void Merge(vector<int>& sequence, unsigned leftIndex, unsigned middleIndex, unsigned rightIndex);
void MergeSortRecursively(vector<int>& sequence, unsigned leftIndex, unsigned rightIndex);
template<typename IteratorType>
string ContainerToString(IteratorType begin, IteratorType end);

void MergeSort(vector<int>& sequence)
{
    MergeSortRecursively(sequence, 0, static_cast<int>(sequence.size() - 1));
}

void MergeSortRecursively(vector<int>& sequence, unsigned leftIndex, unsigned rightIndex)
{
    cout << "MergeSort() sequence = " << ContainerToString(sequence.begin(), sequence.end())
        << " leftIndex = " << leftIndex << " rightIndex = " << rightIndex << endl;

    if (leftIndex < rightIndex)
    {
        int middleIndex = leftIndex + ((rightIndex - leftIndex) / 2);

        cout << "middleIndex = " << middleIndex << endl;

        MergeSortRecursively(sequence, leftIndex, middleIndex);
        MergeSortRecursively(sequence, middleIndex + 1, rightIndex);
        Merge(sequence, leftIndex, middleIndex, rightIndex);
    }
}

void Merge(vector<int>& sequence, unsigned leftIndex, unsigned middleIndex, unsigned rightIndex)
{
    cout << "Merge() sequence = " << ContainerToString(sequence.begin(), sequence.end())
        << " leftIndex = " << leftIndex 
        << " middleIndex = " << middleIndex
        << " rightIndex = " << rightIndex << endl;

    vector<int> leftSequence(static_cast<size_t>(middleIndex - leftIndex) + 1);
    vector<int> rightSequence(rightIndex - middleIndex);

    for (unsigned i = 0; i < leftSequence.size(); ++i)
        leftSequence[i] = sequence[static_cast<size_t>(leftIndex) + i];
    for (unsigned i = 0; i < rightSequence.size(); ++i)
        rightSequence[i] = sequence[static_cast<size_t>(middleIndex) + 1 + i];
        
    int i = 0, j = 0, k = leftIndex; // Left, right, final array iterator indices
    while (i < leftSequence.size() && j < rightSequence.size())
    {
        if (leftSequence[i] <= rightSequence[j])
        {
            sequence[k] = leftSequence[i];
            ++i;
        }
        else
        {
            sequence[k] = rightSequence[j];
            ++j;
        }
        ++k;
    }

    while (i < leftSequence.size())
    {
        sequence[k] = leftSequence[i];
        ++i;
        ++k;
    }

    while (j < rightSequence.size())
    {
        sequence[k] = rightSequence[j];
        ++j;
        ++k;
    }
}

template<typename IteratorType>
string ContainerToString(IteratorType begin, IteratorType end)
{
    string str = "";
    for (auto iter = begin; iter != end; ++iter)
        str.append(to_string(*iter)).append(" ");
    return str;
}

void Test1()
{
    vector<int> sequence1 = { 38, 27 };
    
    cout << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
    cout << "Sorting sequence1..." << endl;
    MergeSort(sequence1);
    cout << ContainerToString(sequence1.begin(), sequence1.end()) << endl;

    cout << endl;

    vector<int> sequence2 = { 38, 27, 43, 3 };
    cout << ContainerToString(sequence2.begin(), sequence2.end()) << endl;
    cout << "Sorting sequence2..." << endl;
    MergeSort(sequence2);
    cout << ContainerToString(sequence2.begin(), sequence2.end()) << endl;

    cout << endl;

    vector<int> sequence3 = { 38, 27, 43, 3, 9, 82, 10 };
    cout << ContainerToString(sequence3.begin(), sequence3.end()) << endl;
    cout << "Sorting sequence3..." << endl;
    MergeSort(sequence3);
    cout << ContainerToString(sequence3.begin(), sequence3.end()) << endl;
}

void RunMergeSortDriver()
{
    Test1();
}
