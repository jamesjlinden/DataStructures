#include "pch.h"
#include "SelectionSort.h"
#include "ContainerHelpers.h"
#include <vector>
#include <iostream>

using namespace std;

void SelectionSort(vector<int>& a)
{
    for (int step = 0; step < a.size(); ++step)
    {
        int minIndex = step;
        for (int i = step + 1; i < a.size(); ++i)
        {
            if (a[i] < a[minIndex])
                minIndex = i;
        }
        if (minIndex != step)
            swap(a[step], a[minIndex]);
    }
}

void RunSelectionSortDriver()
{

    vector<int> sequence1 = { 19, 21, 90, 44, 77, 12 };

    cout << "sequence1 = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
    cout << "SelectionSort() on sequence1..." << endl;

    SelectionSort(sequence1);

    cout << "sequence1 = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
}