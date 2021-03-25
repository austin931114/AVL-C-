#include "Node.h"

int Node::getData() const
{
  //  cout << "getData"<<endl;
		return data;
}

Node * Node::getLeftChild() const
{
   // cout << "getLeftChild"<<endl;
		return left;
}

Node * Node::getRightChild() const
{
   // cout << "getRightChild"<<endl;
		return right;
}

	/*
	* Returns the height of this node. The height is the number of nodes
	* along the longest path from this node to a leaf.  While a conventional
	* interface only gives information on the functionality of a class and does
	* not comment on how a class should be implemented, this function has been
	* provided to point you in the right direction for your solution.  For an
	* example on height, see page 448 of the text book.
	*
	* @return the height of this tree with this node as the local root.
	*/
int Node::getHeight()
{
  //  cout << "getHeight"<<endl;
	return height;
}
void Node::setHeight(int val) {
	height = val;
}

