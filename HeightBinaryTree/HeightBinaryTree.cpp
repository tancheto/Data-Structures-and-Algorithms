// HeightBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <stack>

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}


	/*The tree node has data, left child and right child
	class Node {
	int data;
	Node* left;
	Node* right;
	};

	*/
	int height(Node* root) {
		
		std::stack<Node*> stack;
		root->data = 0;
		stack.push(root);
		int maxHeight = 0;

		while (!stack.empty())
		{
			Node* temp = stack.top();
			if (temp->data > maxHeight)
			{
				maxHeight = temp->data;
			}
			stack.pop();
			if (temp->left != nullptr)
			{
				temp->left->data = temp->data + 1;
				stack.push(temp->left);
			}
			if (temp->right != nullptr)
			{
				temp->right->data = temp->data + 1;
				stack.push(temp->right);
			}
		}
	}

}; //End of Solution

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t--  > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	int height = myTree.height(root);

	std::cout << height;

	return 0;
}

