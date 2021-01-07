#include "pch.h"
#include "CountingSort.h"
#include "ContainerHelpers.h"
#include <vector>
#include <iostream>

using namespace std;

// Only works on non-negative integer numbers. Space complexity is better with smaller number range.
void CountingSort(vector<int>& a)
{
    if (a.size() < 1)
        return;

    int max = a[0];
    for (int i = 0; i < a.size(); ++i)
        if (max < a[i])
            max = a[i];

    vector<int> count(static_cast<size_t>(max) + 1, 0);
    vector<int> output(a.size(), 0);

    for (int i = 0; i < a.size(); ++i)
        ++count[a[i]];

    for (int i = 1; i < count.size(); ++i)
    {
        count[i] += count[static_cast<size_t>(i) - 1];
    }
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i)
    {
        output[static_cast<size_t>(count[a[i]]) - 1] = a[i];
        --count[a[i]];
    }
    for (int i = 0; i < a.size(); ++i)
        a[i] = output[i];
}

void RunCountingSortDriver()
{
    vector<int> sequence1 = { 21, 199, 4, 2, 2, 8, 77, 11, 4, 3, 3, 1 };
    CountingSort(sequence1);
    cout << "CountingSort(sequence1) = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
}
