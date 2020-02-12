#include "pch.h"
#include "InsertionSort.h"
#include "ContainerHelpers.h"
#include <vector>
#include <iostream>

using namespace std;

void InsertionSort(vector<int>& a)
{
    if (a.size() <= 1)
        return;

    for (int i = 1; i < a.size(); ++i)
    {
        int key = a[i];

        int j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[static_cast<size_t>(j) + 1] = a[j];
            --j;
        }
        a[static_cast<size_t>(j) + 1] = key;
    }
}

void RunInsertionSortDriver()
{
    vector<int> sequence1 = { 12, 8, 92, 81, 4, 59 };

    cout << "sequence1 = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
    cout << "InsertionSort() on sequence1..." << endl;

    InsertionSort(sequence1);

    cout << "sequence1 = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
}
