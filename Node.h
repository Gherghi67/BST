#pragma once
class BST;
class Node {
private:
	int value;
	Node* right;
	Node* left;
	static int objects;
public:
	Node();
	Node(int value, Node* right, Node* left);
	Node(Node &node);
	friend class BST;
	friend void printTree(BST bst);
};