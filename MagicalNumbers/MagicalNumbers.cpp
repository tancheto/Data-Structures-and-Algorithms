// MagicalNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

int main()
{
	long long n;

	std::cin >> n;

	std::queue<long long> myQ;

	for (long long i = 1; i <= 9; i++)
	{
		myQ.push(i);
	}

	long long temp = myQ.front();
	long long tDigit1, tDigit2;
	myQ.pop();	

	while (temp <= n)
	{
		std::cout << temp << " ";

		if (temp == 0 || temp == 1) 
		{
			tDigit1 = temp+2;
			temp *= 10;
			temp += tDigit1;
			myQ.push(temp);
		}
		else if (temp == 8 || temp == 9)
		{
			tDigit1 = temp - 2;
			temp *= 10;
			temp += tDigit1;
			myQ.push(temp);
		}
		else {
			tDigit1 = temp - 2;
			tDigit2 = temp + 2;
			temp *= 10;
			myQ.push(temp + tDigit1);
			myQ.push(temp + tDigit2);
		}

		temp = myQ.front();
		myQ.pop();
	}

    return 0;
}

