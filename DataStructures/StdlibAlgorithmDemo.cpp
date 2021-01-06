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

template<class IteratorType>
void PrintCollection(IteratorType begin, IteratorType end)
{
    for (auto iter = begin; iter != end; ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void RunAlgorithmDemo()
{
    array<int, 3> intArray1 = { 3, 2, 1 };
    array<int, 3> intArray2 = { 6, 5, 4 };
    vector<string> wordsVector1 = { "Array", "Stack", "Queue", "SinglyLinkedList", "Stack", "Queue" };
    vector<string> wordsVector2 = { "Stack", "Queue" };
    priority_queue<int> testPriorityQueue;
    testPriorityQueue.emplace(3);
    testPriorityQueue.emplace(2);
    testPriorityQueue.emplace(1);
    vector<int> testVector = { 3, 2, 1 };
    map<string, int> testMap = { {"foo", 3 }, { "bar", 2 }, {"baz", 1} };

    unordered_map<string, int> testUnorderedMap = { {"foo", 3 }, {"bar", 2}, {"baz", 1} };
    auto testMapIter = testMap.begin();
    auto vectorIter = testMap.begin();

    // Predicates
    auto isEven = [](auto x) { return x % 2 == 0; };
    auto isOdd = [](auto x) { return x % 2 == 1; };
    auto isGreaterThan100 = [](auto x) { return x > 100; };
    auto isGreaterThan3 = [](auto x) { return x > 3; };
    auto isLessThan3 = [](auto x) { return x < 3; };
    auto doesFirstLetterMatch = [](const string& lhs, const string& rhs) {return (!lhs.empty() && !rhs.empty() && lhs[0] == rhs[0]); };

    // Functions
    auto printThreeTimes = [](auto elem) { for (int i = 0; i < 3; ++i) { cout << elem << " "; } cout << endl; };

    PrintCollection(intArray1.begin(), intArray1.end());
    PrintCollection(intArray2.begin(), intArray2.end());

    // Non-modifying sequence operations
    cout << "intArray all_of() i < 5 = "
        << all_of(intArray1.begin(), intArray1.end(), [](auto element) { return element < 5; }) << endl;

    cout << "any_of(intArray1.begin(), intArray1.end(), isEven) = "
        << any_of(intArray1.begin(), intArray1.end(), isEven) << endl;

    cout << "none_of(intArray1.begin(), intArray1.end(), isGreaterThan100) = "
        << none_of(intArray1.begin(), intArray1.end(), isGreaterThan100) << endl;

    cout << "Testing for_each(intArray2) by printing each index three times." << endl;
    for_each(intArray2.begin(), intArray2.end(), printThreeTimes);

    cout << "Testing for_each_n(intArray1) by printing two indices three times." << endl;
    for_each_n(intArray1.begin(), 2, printThreeTimes); // Not supported on C++14!

    cout << "Testing find, find_if, and find_if_not" << endl;

    cout << "(find(intArray2.begin(), intArray2.end(), 4) != intArray2.end()) = "
        << (find(intArray2.begin(), intArray2.end(), 4) != intArray2.end()) << endl;
    cout << "(find_if(intArray1.begin(), intArray1.end(), isGreaterThan3) != intArray1.end()) = "
        << (find_if(intArray1.begin(), intArray1.end(), isGreaterThan3) != intArray1.end()) << endl;
    cout << "(find_if_not(intArray2.begin(), intArray2.end(), isGreaterThan3) != intArray2.end()) = "
        << (find_if_not(intArray2.begin(), intArray2.end(), isGreaterThan3) != intArray2.end()) << endl;

    cout << "find_end(wordsVector1.begin(), wordsVector1.end(), wordsVector2.begin(), wordsVector2.end())" << endl;
    auto findEndResult = find_end(wordsVector1.begin(), wordsVector1.end(), wordsVector2.begin(), wordsVector2.end());
    for (findEndResult; findEndResult != wordsVector1.end(); ++findEndResult)
        cout << *findEndResult << endl;

    cout << "find_first_of(wordsVector1.begin(), wordsVector1.end(), wordsVector2.begin(), wordsVector2.end())" << endl;
    auto findFirstOfResult = find_first_of(wordsVector1.begin(), wordsVector1.end(), wordsVector2.begin(), wordsVector2.end());
    for (findFirstOfResult; findFirstOfResult != wordsVector1.end(); ++findFirstOfResult)
        cout << *findFirstOfResult << endl;

    cout << "adjacent_find(wordsVector1.begin(), wordsVector1.end(), doesFirstLetterMatch)" << endl;
    auto adjacentFindResult = adjacent_find(wordsVector1.begin(), wordsVector1.end(), doesFirstLetterMatch);
    for (adjacentFindResult; adjacentFindResult != wordsVector1.end(); ++adjacentFindResult);
        cout << *adjacentFindResult << endl;

    cout << "mismatch(wordsVector1.begin(), wordsVector1.end(), wordsVector2.begin(), wordsVector2.end())" << endl;
    auto mismatchResult = mismatch(wordsVector1.begin(), wordsVector1.end(), wordsVector2.begin(), wordsVector2.end());
    cout << (*mismatchResult.first) << endl;

    // Modifying sequence operations
    cout << "intArray copy()" << endl;
    copy(intArray2.begin(), intArray2.end(), intArray1.begin());
    PrintCollection(intArray1.begin(), intArray1.end());

    // Partitions
    cout << "Checking if intArray2 is partitioned based on i >= 5 = "
        << is_partitioned(intArray2.begin(), intArray2.begin(), [](auto elem) { return elem >= 5; })
        << endl;

    // Sorting
    cout << "Sorting intArray1" << endl;
    sort(intArray1.begin(), intArray1.end());
    PrintCollection(intArray1.begin(), intArray1.end());

    // Binary search
    cout << "Binary search on intArray 1 now that it's sorted for 6: "
        << binary_search(intArray1.begin(), intArray1.end(), 6)
        << endl;
    cout << "Binary search on intArray 2 (unsorted) for 6: "
        << binary_search(intArray2.begin(), intArray2.end(), 6)
        << endl;

    cout << "Sorting intArray2" << endl;
    sort(intArray2.begin(), intArray2.end());

    // Merge
    cout << "Merging intArray1 and intArray2 as intArray3" << endl;
    array<int, 6> intArray3{};
    merge(intArray1.begin(), intArray1.end(), intArray2.begin(), intArray2.end(), intArray3.begin());
    PrintCollection(intArray3.begin(), intArray3.end());

    // Heap
    cout << "Making a maxheap out of intArray3" << endl;
    make_heap(intArray3.begin(), intArray3.end());
    PrintCollection(intArray3.begin(), intArray3.end());

    // Min/max
    auto minMax = minmax_element(intArray3.begin(), intArray3.end());
    cout << "Getting minmax of intArray3" << endl;
    cout << "minMax.first = " << *minMax.first << " minMax.second = " << *minMax.second << endl;

    // Other
    cout << "Printing lexicographic permutations of intArray3: " << endl;
    do
    {
        PrintCollection(intArray3.begin(), intArray3.end());
    } while (next_permutation(intArray3.begin(), intArray3.end()));
}
