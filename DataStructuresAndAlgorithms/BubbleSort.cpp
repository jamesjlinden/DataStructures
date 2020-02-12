#include "pch.h"
#include "BubbleSort.h"
#include "ContainerHelpers.h"
#include <vector>
#include <iostream>

using namespace std;

void BubbleSort(vector<int>& a)
{
    for (int step = 0; step < a.size() - 1; ++step)
        for (int i = 0; i < a.size() - 1 - step; ++i)
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
}

void RunBubbleSortDriver()
{
    vector<int> sequence1 = { 19, 2, 90, 8, 18, 2 };

    cout << "sequence1 = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
    cout << "BubbleSort() on sequence1..." << endl;

    BubbleSort(sequence1);

    cout << "sequence1 = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
}
