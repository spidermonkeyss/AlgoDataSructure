#include "BinarySearch.h"

int SearchAndSplit(int* array, int numberToFind,int middleIndex, int lowIndex, int highIndex)
{
	int index = -1;
	if (array[middleIndex] == numberToFind)
		return middleIndex;

	if (lowIndex >= highIndex)
		return -1;

	if (numberToFind > array[middleIndex])
	{
		int newMiddleIndex = middleIndex + ((highIndex - lowIndex) / 2);
		index = SearchAndSplit(array, numberToFind, newMiddleIndex, middleIndex + 1, highIndex);
	}
	else
	{
		int newMiddleIndex = middleIndex - ((highIndex - lowIndex) / 2);
		index = SearchAndSplit(array, numberToFind, newMiddleIndex, lowIndex, middleIndex - 1);
	}
}

//returns -1 if not found
int BinarySearch(int * array, int numberToFin, int arraySize)
{
	int middleIndex = arraySize / 2;
	int index = SearchAndSplit(array, numberToFin, middleIndex, 0, arraySize - 1);
	
	return index;
}
