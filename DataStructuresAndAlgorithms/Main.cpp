// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <crtdbg.h>
#include "DynamicArray.h"
#include "Queue.h"
#include "SinglyLinkedList.h"
#include "BinarySearchTree.h"
#include "StdlibAlgorithmDemo.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "CountingSort.h"
#include "RadixSort.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    RunRadixSortDriver();
}
