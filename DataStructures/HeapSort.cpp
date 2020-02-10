#include "pch.h"
#include "HeapSort.h"
#include "ContainerHelpers.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Heapify(vector<int> &arr, int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

// main function to do heap sort
void HeapSort(vector<int> &arr, int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        // Heapify root element to get highest element at root again
        Heapify(arr, i, 0);
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
