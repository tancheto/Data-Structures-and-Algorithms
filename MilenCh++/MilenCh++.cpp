// MilenCh++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

struct node {

	int data;
	node* next;
	node* prev;
};

struct list {

	node* head = nullptr;
	node* tail = nullptr;
	node* mid = nullptr;

	int size;
	int count = 0;

	list(int size) {
		this->size = size;
	}

	void add(int n) {

		count++;
		node* temp = new node;
		temp->data = n;

		if (head == nullptr) {

			head = temp;
			tail = temp;
			mid = temp;
			temp = nullptr;
		}
		else {

			temp->next = nullptr;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			temp = nullptr;

			if (count % 2 == 0) {
				mid = mid->next;
			}
		}
	}

	void gun() {

		count--;

		if (count == 0) {
			head = nullptr;
			tail = nullptr;
			mid = nullptr;
		}
		else if (count == 1) {			
			head->next = nullptr;
			tail = head;
			mid = head;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;

			if (count % 2 == 1) {

				mid = mid->prev;
			}
		}
	}

	void milen() {

		if (count == 2) {
			node* temp;
			temp = head;
			head = tail;
			tail = temp;
			head->prev = nullptr;
			head->next = tail;
			tail->next = nullptr;
			tail->prev = head;
			mid = tail;
			temp = nullptr;
		}

		else if (count > 2) {

			node* newMid;

			if (count % 2 == 0) {
				newMid = head;
			}

			else {
				newMid = tail;
			}

			tail->next = head;
			head->prev = tail;

			head = mid;
			tail = mid->prev;

			mid = newMid;
			newMid = nullptr;

			head->prev = nullptr;
			tail->next = nullptr;
		}
	}

	void output() {

		node* temp = head;

		if (count == 0) {
			std::cout << 0;
		}

		else {
		std::cout << count << std::endl;
		//std::cout << "mid= " << mid->data << std::endl;		
			
			while (temp != tail) {
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << temp->data << " ";
		}

		std::cout << std::endl;
	}

};

int main()
{
	int n;

	std::cin >> n;

	std::string temp;

	list myList(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;

		if (temp == "add")
		{
			int x;
			std::cin >> x;

			myList.add(x);
		}

		else if (temp == "gun") {
			myList.gun();
		}

		else if (temp == "milen") {
			myList.milen();
		}

		//myList.output();

	}

	myList.output();

	return 0;
}