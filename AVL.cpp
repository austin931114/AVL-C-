#include "NodeInterface.h"
#include "Node.h"
#include "AVL.h"
#include <algorithm>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

NodeInterface * AVL::getRootNode() const {
	return root;
}

bool AVL::add(int data) {
	addFunction(root, data);
}

bool AVL::addFunction(Node*& temp, int data) {
		/* 
		The node *& is a reference to a pointer 

		Ex:
		int a =5
		int& b = a;
		b = 7;
		because b is a reference to a, so a will also become 7

		(change the memory address pointed to by the pointer), 
		whereas node* is simply a pointer.  
		*/
		if(temp == NULL) { // previous temp does not have "child"
			// cout << "add valuye" << endl;
			temp = new Node(data);
			return true;
		}

			if (data < temp->data) {
				// cout << "left" << endl;
			return addFunction(temp->left, data);
			calc_height(temp);
		}
			else if (data > temp->data) {
				// cout << "right" << endl;
			return addFunction(temp->right, data);
			calc_height(temp);
		}
			else  {
				// cout << "wrong" << endl;
				return false;
			}
	
}
int AVL::get_height(Node* node) {
	if(node == nullptr) {
		return (0);
	}
	else {
		return node->getHeight();
	}
}
void AVL::calc_height(Node* node) {
	if(node == nullptr) {
		return;
	}
	int max = 0;
	if(get_height(node->getLeftChild()) > max) {
		max = get_height(node->getLeftChild());
	}
	if(get_height(node->getRightChild()) > max) {
		max = get_height(node->getRightChild());
	}
	node->setHeight(max + 1);
	cout << "calc_height" << node->getData() << "=";
	cout << node->getHeight() << endl;
}

bool AVL::remove(int data) {

}

void AVL::clear() {

}

void AVL::rotateLeft(Node*& local_root) {
	Node* temp = local_root->left;
  local_root->left = temp->right;
  temp->right = local_root;
  local_root = temp;
}

void AVL::rotateRight(Node*& local_root) {
	Node* temp = local_root->right;
	local_root->right = temp->left;
	temp->left = local_root;
	local_root = temp;
}