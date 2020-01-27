//using namespace std;

#include "pch.h"

// Sequential containers
#include <vector>
#include <array>
#include <list>
#include <queue>

// Associative containers
#include <set>
#include <map>

// Unordered associative containers
#include <unordered_set>
#include <unordered_map>

#include <algorithm>

#include <iostream>

using namespace std;

template<class iteratorType>
void PrintCollection(iteratorType begin, iteratorType end)
{
    for (auto iter = begin; iter != end; ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void RunAlgorithmDemo()
{
    array<int, 3> testArray1 = { 3, 2, 1 };
    array<int, 3> testArray2 = { 6, 5, 4 };
    priority_queue<int> testPriorityQueue;
    testPriorityQueue.emplace(3);
    testPriorityQueue.emplace(2);
    testPriorityQueue.emplace(1);
    vector<int> testVector = { 3, 2, 1 };
    map<string, int> testMap = { {"foo", 3 }, { "bar", 2 }, {"baz", 1} };

    unordered_map<string, int> testUnorderedMap = { {"foo", 3 }, {"bar", 2}, {"baz", 1} };
    auto testMapIter = testMap.begin();
    auto vectorIter = testMap.begin();

    // Non-modifying sequence operations
    cout << "testArray all_of() i < 5 = " 
        << all_of(testArray1.begin(), testArray1.end(), [](auto element) { return element < 5; }) << endl;

    // Modifying sequence operations
    cout << "testArray copy()" << endl;
    copy(testArray2.begin(), testArray2.end(), testArray1.begin());
    PrintCollection(testArray1.begin(), testArray1.end());

    // Partitions
    cout << "Checking if testArray2 is partitioned based on i >= 5 = "
        << is_partitioned(testArray2.begin(), testArray2.begin(), [](auto elem) { return elem >= 5; })
        << endl;

    // Sorting
    cout << "Sorting testArray1" << endl;
    sort(testArray1.begin(), testArray1.end());
    PrintCollection(testArray1.begin(), testArray1.end());

    // Binary search
    cout << "Binary search on testArray 1 now that it's sorted for 6: " 
        << binary_search(testArray1.begin(), testArray1.end(), 6) 
        << endl;
    cout << "Binary search on testArray 2 (unsorted) for 6: "
        << binary_search(testArray2.begin(), testArray2.end(), 6)
        << endl;

    cout << "Sorting testArray2" << endl;
    sort(testArray2.begin(), testArray2.end());

    // Merge
    cout << "Merging testArray1 and testArray2 as testArray3" << endl;
    array<int, 6> testArray3{};
    merge(testArray1.begin(), testArray1.end(), testArray2.begin(), testArray2.end(), testArray3.begin());
    PrintCollection(testArray3.begin(), testArray3.end());

    // Heap
    cout << "Making a maxheap out of testArray3" << endl;
    make_heap(testArray3.begin(), testArray3.end());
    PrintCollection(testArray3.begin(), testArray3.end());

    // Min/max
    auto minMax = minmax_element(testArray3.begin(), testArray3.end());
    cout << "Getting minmax of testArray3" << endl;
    cout << "minMax.first = " << *minMax.first << " minMax.second = " << *minMax.second << endl;

    // Other
    cout << "Printing lexicographic permutations of testArray3: " << endl;
    do
    {
        PrintCollection(testArray3.begin(), testArray3.end());
    } while (next_permutation(testArray3.begin(), testArray3.end()));
}
