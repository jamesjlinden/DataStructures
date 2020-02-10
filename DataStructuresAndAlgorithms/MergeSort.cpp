#include "pch.h"
#include "MergeSort.h"
#include <iostream>
#include <string>
#include "ContainerHelpers.h"

using namespace std;

void Merge(vector<int>& sequence, unsigned minIndex, unsigned midIndex, unsigned maxIndex)
{
    // We always merge two sorted subarrays a[min...mid], a[mid + 1...max] as a[min...max]
    vector<int> minToMidSubsequence(static_cast<size_t>(midIndex - minIndex) + 1);
    vector<int> midPlus1ToMaxSubsequence(static_cast<size_t>(maxIndex - midIndex));

    for (size_t i = 0; i < minToMidSubsequence.size(); ++i)
        minToMidSubsequence[i] = sequence[i + minIndex];
    for (size_t i = 0; i < midPlus1ToMaxSubsequence.size(); ++i)
        midPlus1ToMaxSubsequence[i] = sequence[i + midIndex + 1];

    int minToMidIter = 0, midPlus1ToMaxIter = 0, mergedSequenceIter = minIndex - 1;

    while (minToMidIter < minToMidSubsequence.size() && midPlus1ToMaxIter < midPlus1ToMaxSubsequence.size())
    {
        if (minToMidSubsequence[minToMidIter] <= midPlus1ToMaxSubsequence[midPlus1ToMaxIter])
        {
            ++mergedSequenceIter;
            sequence[mergedSequenceIter] = minToMidSubsequence[minToMidIter];
            ++minToMidIter;
        }
        else
        {
            ++mergedSequenceIter;
            sequence[mergedSequenceIter] = midPlus1ToMaxSubsequence[midPlus1ToMaxIter];
            ++midPlus1ToMaxIter;
        }
    }

    while (minToMidIter < minToMidSubsequence.size())
    {
        ++mergedSequenceIter;
        sequence[mergedSequenceIter] = minToMidSubsequence[minToMidIter];
        ++minToMidIter;
    }

    while (midPlus1ToMaxIter < midPlus1ToMaxSubsequence.size())
    {
        ++mergedSequenceIter;
        sequence[mergedSequenceIter] = midPlus1ToMaxSubsequence[midPlus1ToMaxIter];
        ++midPlus1ToMaxIter;
    }
}

void MergeSortRecursively(vector<int>& sequence, unsigned minIndex, unsigned maxIndex)
{
    if (minIndex < maxIndex)
    {
        int midIndex = minIndex + (maxIndex - minIndex) / 2;
        MergeSortRecursively(sequence, minIndex, midIndex);
        MergeSortRecursively(sequence, midIndex + 1, maxIndex);
        Merge(sequence, minIndex, midIndex, maxIndex);
    }
}

void MergeSort(vector<int>& sequence)
{
    MergeSortRecursively(sequence, 0, static_cast<unsigned>(sequence.size()) - 1);
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
