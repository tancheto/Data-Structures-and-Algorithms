// KraliMarko.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

int arr_bool[1235][1235];

struct node
{
	int data;
	node *next;
};

class linkedList
{
private:
	node *head;
	node *tail;

public:
	linkedList()
	{
		head = NULL;
		tail = NULL;
	}

	node* getHead()
	{
		return this->head;
	}

	void createNode(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}

		else
		{
			tail->next = temp;
			tail = temp;
			temp = NULL;
		}
	}

	void display()
	{
		node *temp = new node;
		temp = head;
		while (temp != NULL)
		{
			std::cout << temp->data << "\t";
			temp = temp->next;
		}
	}
};

bool binarySearch(std::vector<long> arr, int left, int right, int target)
{
	while (left <= right)
	{
		int mid = floor((left + right) / 2);
		if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else if (arr[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int n;

	linkedList myList;

	std::cin >> n;

	short tem;

	for (int i = 0; i < n; i++)
	{
		std::cin >> tem;
		myList.createNode(tem);
	}

	short p;

	std::cin >> p;

	long elem;

	std::vector<long> elements;

	for (int i = 0; i < p; i++)
	{
		std::cin >> elem;
		elements.push_back(elem);
	}

	std::sort(elements.begin(), elements.end());

	node* temp = myList.getHead();

	short counter=0;

	while (temp != NULL && temp->next != NULL)
	{
		if (binarySearch(elements, 0, p-1, temp->data) && binarySearch(elements, 0, p-1, temp->next->data))
		{
			if (arr_bool[temp->data][temp->next->data] == false )
			{
				counter++;
			}

			arr_bool[temp->data][temp->next->data] = true;
			arr_bool[temp->next->data][temp->data] = true;
						
		}

		temp = temp->next;
	}

	std::cout << counter;
}

