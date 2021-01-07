#include "pch.h"
#include "BucketSort.h"
#include "ContainerHelpers.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BucketSort(vector<float>& a)
{
    const int size = 7; // TODO: Make this non-hard-coded

    vector<float> bucket[size];
    for (int i = 0; i < size; i++)
    {
        bucket[int(a[i]) * 10].push_back(a[i]);
    }
    for (int i = 0; i < size; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        while (!bucket[i].empty())
        {
            a[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
    }
}

void RunBucketSortDriver()
{
    vector<float> sequence1 = { .42f, .32f, .33f, .52f, .37f, .47f, .51f };
    BucketSort(sequence1);
    cout << "BucketSort(sequence1) = " << ContainerToString(sequence1.begin(), sequence1.end()) << endl;
}