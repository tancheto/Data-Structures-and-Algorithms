// LinearSearching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int arr[10] = {5,7,14,8,10,22,39,69,4,0};
	int t, n;

	std::cin >> t;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == t)
		{
			std::cout << i;
			break;
		}
	}

    return 0;
}

