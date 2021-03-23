#pragma once
#include "NodeInterface.h"
// #include "AVLNode.h"
#include <iostream>
using namespace std;

class Node : public NodeInterface {

public:
	Node * left;
	Node * right;
	int data;
	int height;

	Node(int value) {
		// intialize each node to have "value" and two "sub-nodes" (left, right)
		data = value;
		height = 0;
		left = NULL;
		right = NULL;
	}
	~Node() {}

	int getData() const;

	Node * getLeftChild() const;

	Node * getRightChild() const;

	/*
	* Returns the height of this node. The height is the number of nodes
	* along the longest path from this node to a leaf.  While a conventional
	* interface only gives information on the functionality of a class and does
	* not comment on how a class should be implemented, this function has been
	* provided to point you in the right direction for your solution.  
	*
	* @return the height of this tree with this node as the local root.
	*/
	int getHeight();
	void setHeight(int val);
};