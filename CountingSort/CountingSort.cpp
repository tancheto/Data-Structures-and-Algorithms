// CountingSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void CountingSort(int* arr, int size)
{
	int max=arr[0];
	int maxIndex = 0;

	for (int i = 1; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			maxIndex = i;
		}
	}                          

	int *countArr = new int[max+1];

	for (int i = 0; i <= max; i++)
	{
		countArr[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		countArr[arr[i]]++;
	}

	int arrIndex = 0;
	int countIndex = 0;

	while (countIndex <= max)
	{
		if (countArr[countIndex] > 0)           
		{
			arr[arrIndex] = countIndex;
			arrIndex++;
			countArr[countIndex]--;
		}
		else
		{
			countIndex++;
		}
	}

	delete[] countArr;
}

void PrintMyArr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}


int main()
{
	int myArr[10] = { 3,6,1,8,2,9,12,9,4,5 };

	CountingSort(myArr, 10);

	PrintMyArr(myArr, 10);

    return 0;
}

