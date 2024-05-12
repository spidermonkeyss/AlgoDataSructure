#include "LinkedList.h"
#include "QuickSort.h"
#include "BinarySearch.h"

#include <iostream>

class TestClass
{
public:
	TestClass() {}
	TestClass(std::string name, int number) :name(name), number(number) {}
	std::string name;
	int number;
};

void RunLinkedListExample()
{
	LinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(5);

	for (LinkedList<int>::Iterator i = list.Begin(); i != list.End(); i++)
	{
		std::cout << *i.Data() << std::endl;
		if (2 == *i.Data())
			list.Remove(&i);
	}

	for (LinkedList<int>::Iterator i = list.Begin(); i != list.End(); i++)
	{
		std::cout << *(i.Data()) << std::endl;
	}


}

void RunSortAndSearchExample()
{
	std::cout << std::endl;
	const int arraySize = 7;
	int numArray[arraySize] = { 6, 5, 8, 9, 7, 3, 4};
	QuickSortArray(numArray, arraySize);

	std::cout << "Sorted Array:";
	for (int i = 0; i < arraySize - 1; i++)
		std::cout << numArray[i] << ",";
	std::cout << numArray[arraySize - 1];

	std::cout << std::endl;
	int number = 9;
	int index = BinarySearch(numArray, number, arraySize);
	std::cout << "Checking for:" << number << " Index:" << index << std::endl;

	number = 11;
	index = BinarySearch(numArray, number, arraySize);
	std::cout << "Checking for:" << number << " Index:" << index << " (returns -1 when number wasn't found)" << std::endl;
}

int main()
{
	RunLinkedListExample();
	RunSortAndSearchExample();
}