#include "pch.h"
#include "Quicksort.h"
#include "ContainerHelpers.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Partition(vector<int>& sequence, int low, int high)
{
    int pivot = sequence[high];
    int i = low - 1;

    for (int j = low; j <= high; ++j)
    {
        if (sequence[j] < pivot)
        {
            ++i;
            swap(sequence[i], sequence[j]);
        }
    }

    swap(sequence[static_cast<size_t>(i) + 1], sequence[high]);
    return i + 1;
}

void Quicksort(vector<int>& sequence, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = Partition(sequence, low, high);

        Quicksort(sequence, low, partitionIndex - 1);
        Quicksort(sequence, partitionIndex + 1, high);
    }
}

void RunQuicksortDriver()
{
    vector<int> sequence1 = { 49, 10, 8, 11, 53 };

    PrintContainer(sequence1.begin(), sequence1.end());

    cout << "Quicksort sequence1..." << endl;

    Quicksort(sequence1, 0, static_cast<int>(sequence1.size()) - 1);

    PrintContainer(sequence1.begin(), sequence1.end());
}
