// WinterWinter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int n;
	long k;
	std::vector<long> arr;
	long temp;
	bool flag = false;
	long count = 0;

	std::cin >> n;
	std::cin >> k;

	long max = 0;

	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		arr.push_back(temp);

		if (max < temp)
		{
			max = temp;
		}
	}

	long min = 0;

	while (min <= max)
	{
		long mid = floor((min + max) / 2);
		long hairdryer = 0;
		long last_hirdryer = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > count)
			{
				hairdryer += ceil(arr[i] / k);
			}
		}

		if (hairdryer > count)
		{
			min = mid + 1;
		}

		else if(hairdryer < count)
		{
			max = mid - 1;
		}
		else if(hairdryer == count)
		{
			std::cout<< mid;
			break;
		}
	}

	return 0;
}
   

