#include "pch.h"
#include "QuickSort.h"
#include "ContainerHelpers.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Partition(vector<int>& sequence, int low, int high)
{
    int pivot = sequence[high];
    int lessThanSequenceIndex = low - 1;

    // Break into two subsequences: lessThanSequence followed by greaterThanSequence followed by the pivot
    for (int greaterThanSequenceIndex = low; greaterThanSequenceIndex <= high; ++greaterThanSequenceIndex)
    {
        if (sequence[greaterThanSequenceIndex] < pivot)
        {
            ++lessThanSequenceIndex;
            swap(sequence[lessThanSequenceIndex], sequence[greaterThanSequenceIndex]);
        }
    }

    swap(sequence[static_cast<size_t>(lessThanSequenceIndex) + 1], sequence[high]);

    cout << "Partition() sequence = " << ContainerToString(sequence.begin(), sequence.end())
        << " low = " << low << " high = " << high << endl;

    return lessThanSequenceIndex + 1;
}

void Quicksort(vector<int>& sequence, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = Partition(sequence, low, high);

        Quicksort(sequence, low, pivotIndex - 1);
        Quicksort(sequence, pivotIndex + 1, high);
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
