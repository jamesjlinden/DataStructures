#include "pch.h"
#include "RadixSort.h"
#include "ContainerHelpers.h"

#include <iostream>
#include <vector>

using namespace std;

// TODO: Work this out on paper
void CountingSort(vector<int>& a, int place)
{
    const int max = 10;
    vector<int> output(a.size(), 0);
    vector<int> count(max, 0);

    for (int i = 0; i < a.size(); ++i)
        ++count[(a[i] / place) % 10];

    for (int i = 1; i < max; ++i)
        count[i] += count[static_cast<size_t>(i) - 1];

    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i)
    {
        output[static_cast<size_t>(count[(static_cast<size_t>(a[i]) / place) % 10]) - 1] = a[i];
        --count[(a[i] / place) % 10];
    }

    for (int i = 0; i < a.size(); ++i)
        a[i] = output[i];
}

void RadixSort(vector<int>& a)
{
    if (a.size() < 1)
        return;

    int maxValue = a[0];
    for (int i = 0; i < a.size(); ++i)
        if (a[i] > maxValue)
            maxValue = a[i];

    // TODO: Try making a version of Radix Sort using floating point numbers
    for (int place = 1; maxValue / place > 0; place *= 10)
        CountingSort(a, place);
}

void RunRadixSortDriver()
{
    vector<int> sequence1 = { 121, 432, 564, 23, 1, 45, 788 };
    RadixSort(sequence1);
    cout << "RadixSort(sequence1) = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
}