// SnejniTopki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

struct node {

	short lastBall;
	node* parent;
	long sum;
};

int main()
{
	int n;

	std::cin >> n;

	int p;
	short m;

	long sum = 0;
	
	std::vector<node*> snowMen;
	std::vector<long> arrSum;
	node* temp=new node;
	temp->lastBall = 0;
	temp->sum = 0;
	temp->parent = nullptr;

	snowMen.push_back(temp);
	arrSum.push_back(temp->sum);
	sum += temp->sum;

	for (int i = 1; i <= n; i++)
	{
		node* temp=new node;

		std::cin >> p;
		std::cin >> m;

		if (m != 0) {

			temp->lastBall = m;
			temp->parent = snowMen[p];
			temp->sum = arrSum[p] + m;
			arrSum.push_back(temp->sum);
			sum += temp->sum;
		}

		else if (m == 0) {

			temp->parent = snowMen[p]->parent->parent;
			temp->lastBall = snowMen[p]->parent->lastBall;
			temp->sum = snowMen[p]->parent->sum;
			arrSum.push_back(temp->sum);
			sum += temp->sum;
		}
		
		snowMen.push_back(temp);

	}

	std::cout << sum;

	return 0;
}



