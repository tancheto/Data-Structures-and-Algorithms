// Ritsari.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int n;

struct node {

	int number;
	node* next;
};

struct roundList {

	int size=n;
	node* head=nullptr;
	node* tail=nullptr;
	int counter=0;

	void add(int num) {
		counter++;
		node* temp = new node;
		temp->number = num;		

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else
		{
			tail->next = temp;
			tail = temp;
			temp = nullptr;
		}

		if (counter == size)
		{
			tail->next = head;
		}
	}

	int winner()
	{
		node* temp = head;

		while (counter != 2)
		{
			temp->next = temp->next->next;
			temp = temp->next;
			counter--;
		}

		if (n % 2 == 0)
		{
			return temp->number;
		}

		else if (n%2 != 0 && temp->number == 1)
		{
			return n;
		}

		else
		{
			return temp->number - 2;
		}

		return temp->number;
	}
};

int main()
{
	
	std::cin >> n;

	roundList myList;

	if (n == 1) 
	{
		std::cout << 1;
	}

	else
	{
		for (int i = 1; i <= n; i+=2)
		{
			myList.add(i);
		}

		std::cout << myList.winner();
	}

    return 0;
}

