#include "Node.h"
#include <iostream>
using namespace std;
Node::Node() {
	value = 0;
	right = NULL;
	left = NULL;
}
Node::Node(int value, Node* right, Node* left) {
	this->value = value;
	this->right = right;
	this->left = left;
}
Node::Node(Node &node) {
	this->value = node.value;
	this->right = node.right;
	this->left = node.left;
}
int Node::objects = 0;