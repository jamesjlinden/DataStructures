#include "pch.h"
#include "QuickSort.h"
#include "ContainerHelpers.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Partition(vector<int>& sequence, int minIndex, int maxIndex)
{
    int pivot = sequence[maxIndex];
    int storeIndex = minIndex - 1;
    for (int i = minIndex; i < maxIndex; ++i)
    {
        if (sequence[i] <= pivot)
        {
            ++storeIndex;
            swap(sequence[storeIndex], sequence[i]);
        }
    }

    swap(sequence[static_cast<size_t>(storeIndex) + 1], sequence[maxIndex]);
    return storeIndex + 1;
}

void QuickSort(vector<int>& sequence, int minIndex, int maxIndex)
{
    if (minIndex < maxIndex)
    {
        int pivotIndex = Partition(sequence, minIndex, maxIndex);

        QuickSort(sequence, minIndex, pivotIndex - 1);
        QuickSort(sequence, pivotIndex + 1, minIndex);
    }
}

void RunQuicksortDriver()
{
    vector<int> sequence1 = { 49, 10, 8, 11, 53 };

    PrintContainer(sequence1.begin(), sequence1.end());

    cout << "Quicksort sequence1..." << endl;

    QuickSort(sequence1, 0, static_cast<int>(sequence1.size()) - 1);

    PrintContainer(sequence1.begin(), sequence1.end());
}
