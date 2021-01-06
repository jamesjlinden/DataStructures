#include "pch.h"
#include "HeapSort.h"
#include "ContainerHelpers.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Heapify(vector<int> &a, int n, int rootIndex)
{
    int largestIndex = rootIndex;
    int leftIndex = 2 * rootIndex + 1;
    int rightIndex = 2 * rootIndex + 2;
    
    if (leftIndex < n && a[leftIndex] > a[largestIndex])
        largestIndex = leftIndex;
    if (rightIndex < n && a[rightIndex] > a[largestIndex])
        largestIndex = rightIndex;

    if (a[largestIndex] > a[rootIndex])
    {
        swap(a[rootIndex], a[largestIndex]);
        Heapify(a, n, largestIndex);
    }
}

void HeapSort(vector<int>& a, int n)
{
    // Build a max heap out of array
    for (int rootIndex = n / 2 - 1; rootIndex >= 0; --rootIndex) // No need to heapify leaf nodes, start at n / 2 - 1 (first node with leaves
        Heapify(a, n, rootIndex);

    // Move root to the end of the array, heapify resulting array, repeat until one node left in tree
    for (int i = n - 1; i >= 0; --i)
    {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}

void RunHeapSortDriver()
{
    vector<int> sequence1 = { 19, 7, 24, 50, 98 };

    PrintContainer(sequence1.begin(), sequence1.end());

    cout << "HeapSort() sequence 1..." << endl;

    HeapSort(sequence1, static_cast<int>(sequence1.size()));

    PrintContainer(sequence1.begin(), sequence1.end());
}
