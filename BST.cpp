#include "BST.h"
#include <iostream>
using namespace std;
BST::BST() {
	root = NULL;
}
BST::BST(BST &bst) {
	root = NULL;
	Node** stack = new Node*[bst.count];
	unsigned int stack_size = 0;
	stack[stack_size++] = bst.root;
	while (stack_size > 0) {
		Node* p = stack[--stack_size];
		insert(p->value);
		if (p->right != NULL)
			stack[stack_size++] = p->right;
		if (p->left != NULL)
			stack[stack_size++] = p->left;
	}
	delete[] stack;
	count = bst.count;
}
void BST::insert(int x) {
	root = insert(x, root);
	count++;
}
Node* BST::insert(int x, Node* node) {
	if (node == NULL) {
		node = new Node;
		node->value = x;
		node->left = NULL;
		node->right = NULL;
	}
	else if (x < node->value) {
		node->left = insert(x, node->left);
	}
	else if (x > node->value) {
		node->right = insert(x, node->right);
	}
	return node;
}
Node* BST::remove(int x, Node* node) {
	Node* temp;
	if (node == NULL)
		return NULL;
	else if (x < node->value)
		node->left = remove(x, node->left);
	else if (x > node->value)
		node->right = remove(x, node->right);
	else if (node->left && node->right) {
		temp = findMin(node->right);
		node->value = temp->value;
		node->right = remove(node->value, node->right);
	}
	else {
		temp = node;
		if (node->left == NULL)
			node = node->right;
		else if (node->right == NULL)
			node = node->left;
		delete temp;
	}
	return node;
}
Node* BST::findMin(Node* node) {
	if (node == NULL)
		return NULL;
	else if (node->left == NULL)
		return node;
	else
		return findMin(node->left);
}
void BST::remove(int x) {
	root = remove(x, root);
	count--;
}
void printTree(BST bst) {
	if (bst.root == NULL)
		return;
	Node** stack = new Node*[bst.count];
	unsigned int stack_size = 0;
	Node* p = bst.root;
	while (p != NULL || stack_size > 0) {
		if (p != NULL) {
			stack[stack_size++] = p;
			p = p->left;
		}
		else {
			p = stack[--stack_size];
			cout << p->value << " ";
			p = p->right;
		}
	}
	delete[] stack;
}
int* BST::preorder(BST bst) {
	if (bst.root == NULL)
		return NULL;
	Node** stack = new Node*[bst.count];
	int* vector = new int[bst.count];
	int vector_size = 0;
	unsigned int stack_size = 0;
	stack[stack_size++] = bst.root;
	while (stack_size > 0) {
		Node* p = stack[--stack_size];
		vector[vector_size++] = p->value;
		if (p->right != NULL)
			stack[stack_size++] = p->right;
		if (p->left != NULL)
			stack[stack_size++] = p->left;
	}
	delete[] stack;
	return vector;
}
int* BST::postorder(BST bst) {
	if (bst.root == NULL)
		return NULL;
	Node** stack = new Node*[bst.count];
	int* vector = new int[bst.count];
	int vector_size = 0;
	unsigned int stack_size = 0;
	Node* p = bst.root;
	while (stack_size > 0) {
		while (p != NULL) {
			if (p->right != NULL)
				stack[stack_size++] = p->right;
			stack[stack_size++] = p;
			p = p->left;
		}
		p = stack[--stack_size];
		if (p->right != NULL && stack[stack_size - 1] == p->right) {
			stack[stack_size - 1] = p;
			p = p->right;
		}
		else {
			vector[vector_size++] = p->value;
			p = NULL;
		}
	}
	delete[] stack;
	return vector;
}
void BST::print(BST bst, int x) {
	int* v;
	if (x == 0)
		v = preorder(bst);
	else
		v = postorder(bst);
	int i;
	for (i = 0; i < bst.count; i++)
		cout << v[i] << " ";
	delete[] v;
}
unsigned int BST::depth(Node* node) {
	if (node == NULL)
		return 0;
	int r = depth(node->right);
	int l = depth(node->left);
	if (l > r)
		return l + 1;
	return r + 1;
}
int BST::height() {
	return depth(root);
}