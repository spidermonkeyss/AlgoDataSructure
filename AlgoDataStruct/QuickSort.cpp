#include "QuickSort.h"
#include <limits.h>

void SwapIndices(int* array, int fIndex, int sIndex)
{
	int tempFnum = array[fIndex];
	int tempSnum = array[sIndex];
	array[fIndex] = tempSnum;
	array[sIndex] = tempFnum;
}

int Partition(int* array, int lowIndex, int highIndex)
{
	int pivotPoint = array[lowIndex];
	int i = lowIndex;
	int j = highIndex;
	while (i < j)
	{
		//increment i till number less than pivot
		do
		{
			i++;
		} while (array[i] < pivotPoint);
		//decrement j till number greater than pivot
		do
		{
			j--;
		} while (array[j] > pivotPoint);

		//swap index points till i passes j
		if (i < j)
			SwapIndices(array, i, j);
	}
	//swap the pivot to its sorted point
	SwapIndices(array, lowIndex, j);
	return j;//return the sorted pivot to split the sections
}

void SortSection(int* array, int lowIndex, int highIndex)
{
	if (lowIndex < highIndex)
	{
		int sortedPivot = Partition(array, lowIndex, highIndex);//sorted pivot
		SortSection(array, lowIndex, sortedPivot);//left section
		SortSection(array, sortedPivot + 1, highIndex);//right section
	}
}

void QuickSortArray(int* array, int arraySize)
{
	int* newArray = new int[arraySize + 1];
	
	//create new array with MAX NUMBER at end
	for (int i = 0; i < arraySize; i++)
		newArray[i] = array[i];
	newArray[arraySize] = INT_MAX;

	SortSection(newArray, 0, arraySize);

	//put new sorted array back into array
	for (int i = 0; i < arraySize; i++)
		array[i] = newArray[i];

	delete[] newArray;
}
