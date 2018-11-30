
#include "stdafx.h"
#include <iostream>
#include <string>

struct node
{
	long data;
	struct node* next;
};

struct stack {

	node* head = nullptr;
	int size = 0;

	void push(long data)
	{
		node* tmp = new node;
		tmp->data = data;
		tmp->next = head;
		head = tmp;
		tmp = nullptr;
		size++;
	}

	long pop()
	{
		node* tmp = head;
		long element = head->data;
		head = head->next;
		tmp = nullptr;
		size--;
		return element;		
	}

	long peek()
	{
		return head->data;
	}

	bool empty()
	{
		return head == nullptr ? true : false;
	}

	void green(long k)
	{
		long long sum = 0;

		if (k > size) { k = size; }

		for (long i = 0; i < k; i++)
		{
			sum += pop();
		}

		push(sum);
	}

	void blue(long k)
	{
		long long max = peek();
		long long last;

		if (k > size) { k = size; }

		for (long i = 0; i < k; i++)
		{
			last = pop();
			if (max < last)
			{
				max = last;
			}
		}

		push(max);
	}


	void display()
	{
		node *current = head;
		if (current != nullptr)
		{
			do
			{
				std::cout << current->data << " ";
				current = current->next;
			} while (current != nullptr);
		}
		else
		{
			std::cout << "The Stack is empty";
		}
	}
};

int main()
{
	int n;

	std::cin >> n;

	long k;
	std::string str;
	stack myStack;

	for (int i = 0; i < n; i++)
	{
		std::cin >> str;
		std::cin >> k;

		if (str == "white")
		{
			myStack.push(k);
		}
		else if (str == "green")
		{
			myStack.green(k);
		}
		else if (str == "blue")
		{
			myStack.blue(k);
		}
	}

	stack anotherStack;
	int stackSize = myStack.size;

	for (int i = 0; i < stackSize; i++)
	{
		anotherStack.push(myStack.pop());
	}

	anotherStack.display();

	return 0;
}