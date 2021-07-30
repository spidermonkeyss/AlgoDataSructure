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
	list.PushFront(7);
	list.PopFront();
	std::cout << "Display List:" << list.DisplayList() << std::endl;//Display only works with primtive data types
	list.BeginListIteration();
	list.NextListIteration();
	list.NextListIteration();
	list.NextListIteration();
	list.NextListIteration();
	list.NextListIteration();
	list.NextListIteration();
	std::cout << "Current list iteration:" << list.GetCurrentListIterationData() << std::endl;

	LinkedList<char> charList;
	charList.PushBack('h');
	charList.PushBack('e');
	charList.PushBack('l');
	charList.PushBack('l');
	charList.PushBack('o');
	std::cout << charList.DisplayList() << std::endl;

	LinkedList<std::string> stringList;
	stringList.PushBack("th");
	stringList.PushBack("er");
	stringList.PushBack("e!");
	std::cout << stringList.DisplayList() << std::endl;

	//Custom classes must have default constructor
	LinkedList<TestClass> testClassList;
	TestClass test1("one", 1);
	TestClass test2("two", 2);
	TestClass test3("3", 3);
	testClassList.PushBack(test1);
	testClassList.PushBack(test2);
	testClassList.PushBack(test3);
	testClassList.BeginListIteration();
	testClassList.NextListIteration();
	std::cout << "Current list iteration:" << testClassList.GetCurrentListIterationData().name << std::endl;
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