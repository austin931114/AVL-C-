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
				bool rval = addFunction(temp->left, data);
				calc_height(temp);
				return rval;
		}
			else if (data > temp->data) {
				//cout << "right" << endl;
				bool rval = addFunction(temp->right, data);
				calc_height(temp);
				if (rval) {
					
					isBalanced(temp);
				}
				return rval;
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

void AVL::isBalanced(Node* node) {
	int rightBal;
	int leftBal;
	int bal = get_balance(node);

	if (node->right != NULL) {
		rightBal = get_balance(node->right);
	}
	else {
		rightBal = 0;
	}
	if (node->left != NULL) {
		leftBal = get_balance(node->left);
	}
	else {
		leftBal = 0;
	}

	if (bal == -2) {
		if (leftBal == 1) {
			rotateLeft(node->left);
			rotateRight(node);
		}	
		else {
			rotateRight(node);
		}
	}
	else if (bal == 2) {
		if (rightBal == -1) {
			rotateRight(node->right);
			rotateLeft(node);
		}	
		else {
			rotateLeft(node);
		}
	}
	// else {
	// 	return true;
	// }
}

int AVL::get_balance(Node* node) {
	int rightHeight;
	int leftHeight;
	// Node* myRight = node->right;
	if(node->right != NULL) {
		rightHeight = node->right->height;
	}
	else {
		rightHeight = 0;
	}
	if(node->left != NULL) {
		leftHeight = node->left->height;
	}
	else {
		leftHeight = 0;
	}
	int bal = rightHeight - leftHeight;
	cout << "My Balance" << bal << endl;
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