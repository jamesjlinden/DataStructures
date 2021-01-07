#include "pch.h"
#include "ContainerHelpers.h"
#include <vector>
#include <iostream>

using namespace std;

void ShellSort(vector<int>& a, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            int temp = a[i];
            int j;

            for (j = i; j >= gap && a[j - static_cast<size_t>(gap)] > temp; j -= gap)
            {
                a[j] = a[j - static_cast<size_t>(gap)];
            }

            a[j] = temp;
        }
    }
}

void RunShellSortDriver()
{
    vector<int> sequence1 = { 9, 8, 3, 7, 5, 6, 4, 1 };

    cout << "sequence1 = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
    ShellSort(sequence1, static_cast<int>(sequence1.size()));
    cout << "ShellSort() sequence1..." << endl;
    cout << "sequence1 = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
}
