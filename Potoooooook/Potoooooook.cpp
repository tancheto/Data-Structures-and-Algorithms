// Potoooooook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

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
		node* temp=new node;
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
		node *temp=new node;
		temp = head;
		while (temp != NULL)
		{
			std::cout << temp->data << "\t";
			temp = temp->next;
		}
	}
};

int main()
{
	int num;

	linkedList myList;

	while (std::cin >> num)
	{
		myList.createNode(num);
	}

	node* temp = myList.getHead();

	int min=temp->data;
	int max = temp->data;
	int sum = 0;
	
	//myList.display();

	
	while (temp != NULL)
	{
		if (min > temp->data)
		{
			min = temp->data;
		}

		if (max < temp->data)
		{
			max = temp->data;
		}

		sum += temp->data;

		temp = temp->next;
	}

	std::cout << min << " " << max << " " << sum << std::endl;

    return 0;
}

