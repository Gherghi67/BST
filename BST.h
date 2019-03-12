#pragma once
#include "Node.h"
class BST {
private:
	Node* root;
	unsigned int count = 0;
	Node* insert(int x, Node* node);
	Node* remove(int x, Node* node);
	Node* findMin(Node* node);
	unsigned int depth(Node* node);
public:
	BST();
	BST(BST &bst);
	void insert(int x);
	void remove(int x);
	friend void printTree(BST bst);
	static int* preorder(BST bst);
	static int* postorder(BST bst);
	static void print(BST bst, int x);
	int height();
};