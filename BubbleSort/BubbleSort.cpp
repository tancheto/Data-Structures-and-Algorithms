// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void BubbleSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				std::swap(arr[j], arr[i]);
			}
		}
	}
}

void SelectionSort(int *arr, int size)
{
	int i, j, temp;

	for (i = 0; i < size-1; i++)
	{
		temp=i;

		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[temp])
			{
				temp = j;
			}
		}

		std::swap(arr[temp], arr[i]);
	}
}

void InsertionSort(int *arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
			}

			else
			{
				break;
			}
		}
	}
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

	//BubbleSort(myArr, 10);

	//SelectionSort(myArr, 10);

	InsertionSort(myArr, 10);

	PrintMyArr(myArr, 10);

    return 0;
}

