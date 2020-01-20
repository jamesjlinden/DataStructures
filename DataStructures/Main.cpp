// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <crtdbg.h>
#include "DynamicArray.hpp"
#include "Queue.hpp"
#include "SinglyLinkedList.hpp"
#include <string>
#include <list>
#include "BinarySearchTree.hpp"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	RunBinarySearchTreeDriver();
}
