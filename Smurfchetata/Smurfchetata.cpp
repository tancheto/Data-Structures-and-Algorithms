// Smurfchetata.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

struct node {

	char ch;
	node* next;
	node* prev;
};

struct charList {

	node* head = nullptr;
	node* tail = nullptr;
	node* cursor = nullptr;
	char last =']';

	void toBegin() {	

		/*
		if(head!=nullptr) {

			cursor = head;		
		}*/

		last = '[';
	}
	void toEnd() {

		/*
		if (head != nullptr) {

			cursor = tail;
		}
		*/

		last = ']';
	}

	void write(char ch)
	{
		node* temp = new node;
		temp->ch = ch;

		if (head == nullptr) {

			head = temp;
			tail = temp;
			cursor = temp;
			temp = nullptr;
		}

		else {

			if (last == '[') {

				temp->next = head;
				head->prev = temp;
				head = head->prev;
				cursor = head;

				last = ch;
			}

			else if(last == ']') {

				temp->prev = tail;
				temp->next = nullptr;
				tail->next = temp;
				tail = tail->next;
				cursor = tail;

			}

			else {

				temp->prev = cursor;
				temp->next = cursor->next;
				cursor->next = temp;
				cursor = cursor->next;
			}
		}

	}

	void output() {

		node* temp = head;

		while (temp!=nullptr) {
			std::cout << temp->ch;
			temp = temp->next;
		}
	}

};

int main()
{
	int q;

	std::cin >> q;

	std::string str;

	charList myList;

	for (int i = 0; i < q; i++)
	{
		std::cin >> str;

		for (int i = 0; i < str.length(); i++) 
		{
			if (str[i] == '[') {

				myList.toBegin();
			}

			else if (str[i] == ']') {

				myList.toEnd();
			}

			else {

				myList.write(str[i]);
			}
		}

		myList.output();

	}
    return 0;
}

