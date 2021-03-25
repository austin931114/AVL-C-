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
		//cout << "add " << data << endl;
		if(temp == NULL) { // previous temp does not have "child"
			// cout << "add valuye" << endl;
			temp = new Node(data);
			//cout << "   add <" << data << endl;
			//calc_height(temp);
			//cout << "FINISH ADD" << endl;
			return true;
		}

		if (data < temp->data) {
				// cout << "left" << endl;
				bool rval = addFunction(temp->left, data);
					//cout << "add <" << data << endl;
					calc_height(temp->left);
					isBalanced(temp);
				return rval;
		}
		else if (data > temp->data) {
				//cout << "right" << endl;
				bool rval = addFunction(temp->right, data);
				//cout << "add >" << data << endl;
				// cout << "CAL HEIGHT for" << temp->data << endl;
					calc_height(temp->right);
					isBalanced(temp);
				return rval;
		}
		else  {
				// cout << "wrong" << endl;
				return false;
		}
	
}

int AVL::get_height(Node*& node) {
	if(node == nullptr) {
		return (0);
	}
	else {
		return node->getHeight();
	}
}
void AVL::calc_height(Node*& node) {
	if(node == nullptr) {
		return;
	}
	int max = 0;
	if(get_height(node->left) > max) {
	//	cout << "LEFT node" << node->left->data << " = " << get_height(node->left) << endl;
		max = get_height(node->left);
	}
	if(get_height(node->right) > max) {
	//	cout << "RIGHT node" << node->right->data << " = " << get_height(node->right) << endl;
		max = get_height(node->right);
	}
	node->setHeight(max + 1);
	//cout << "calc_height " << node->getData() << " = ";
	//cout << node->getHeight() << endl;
}

void AVL::isBalanced(Node*& node) {
	int rightBal;
	int leftBal;
	int bal = get_balance(node);
	cout << "My Balance "  << node->data << " = " << bal << endl;

	if (node->right != NULL) {

		rightBal = get_balance(node->right);
		//cout << "                        rightBa " << rightBal << endl;
	}
	else {
		rightBal = 0;
	//	cout << "My rightBa " << rightBal << endl;
	}
	if (node->left != NULL) {
		leftBal = get_balance(node->left);
	//	cout << "                        leftBa " << leftBal << endl;
	}
	else {
		leftBal = 0;
	//	cout << "My leftBa " << leftBal << endl;
	}

	if (bal == -2) {
		if (leftBal == 1) {
			rotateLeft(node->left);
			cout << "  rotate left " <<  node->data << endl;
			rotateRight(node);
			cout << "  rotate right" << node->data << endl;
		}	
		else {
			rotateRight(node);
			cout << "  rotate right" << node->data << endl;
		}
	}
	else if (bal == 2) {
		if (rightBal == -1) {
			rotateRight(node->right);
			cout << "  rotate right " << node->data << endl;
			rotateLeft(node);
			cout << "  rotate left " <<  node->data << endl;
		}	
		else {
			cout << "  rotate left " <<  node->data << endl;
			rotateLeft(node);
			//--node->height;
			//cout << node->data << " height = " << node->height << endl;
			return;
		}
	}
	else {
		return;
	}
}

int AVL::get_balance(Node* node) {
	int rightHeight;
	int leftHeight;
	// Node* myRight = node->right;
	if(node->right != NULL) {
		rightHeight = node->right->height;
	//	cout << "...RIGHT height" << rightHeight << endl;
	}
	else {
		rightHeight = 0;
	}
	if(node->left != NULL) {
		leftHeight = node->left->height;
		//cout << "...LEFT height" << leftHeight << endl;
	}
	else {
		leftHeight = 0;
	}
	int bal = rightHeight - leftHeight;
	 //cout << "My Balance" << bal << endl;
	return bal;
}

bool AVL::remove(int data) {
	return removeFunction(root, data);
}

bool AVL::removeFunction(Node*& temp, int data) {
	if (temp == NULL) {
		return false;
	}
	else {
			if (data < temp->data) {
				bool rval = removeFunction(temp->left, data);
				calc_height(temp->left);
				isBalanced(temp);
				return rval;
		  }
			else if (data > temp->data) {
				bool rval = removeFunction(temp->right, data);
				calc_height(temp->right);
				isBalanced(temp);
				return rval;
			}
			else { // item is the tempRoot
				Node* oldRoot = temp; // copy root to prevent memory mulfunction
				// if (temp->left == NULL && temp->right == NULL) {
				// 	cout << "DELETE " << temp->data << endl;
				// 	temp = NULL;
				// 	delete oldRoot;
				// }
				// else 
				if (temp->left == NULL) {
						cout << "DELETE " << temp->data << endl;
						// cout << "remove one child " << data << endl;
						temp = temp->right;
						// because tempRoot is a reference to its partent
						// when tempRoot set to right, its parent will reference to right
						// and omit tempRoot
						delete oldRoot; // prevent memory leak
				}
				else if (temp->right == NULL) {
					cout << "DELETE " << temp->data << endl;
					// cout << "remove one child" << data << endl;
					temp = temp->left;
					//* set the parent of tempRoot ro reference to "left child"
					delete oldRoot;
			}
			else {
				cout << "DELETE BOTH " << temp->data << endl;
				// cout << "remove 2 children " << data << endl;
				replace(oldRoot, temp->left);
				calc_height(temp->left);
				isBalanced(temp);
				// return true;
			}
			//delete oldRoot;
			return true;
	}
	}


	// else if (temp->data == data) {
	// 	if (temp->left == NULL && temp->right == NULL) {

	// 	}

	// }

}
void AVL::replace(Node*& oldRoot, Node*& temp) {
		// find right most root, because right most root is the biggest value that smaller than oldRoot
		if (temp->right != NULL) {
			replace(oldRoot, temp->right);
		}
		else {
			// set the oldRoot value to right most root's value
			oldRoot->data = temp->data;
			// remove the right most root
			removeFunction(oldRoot->left, temp->data);
			
			//isBalanced(oldRoot);
			
		}
	}


void AVL::clear() {
	recursiveClear(root);
	root = NULL;
}
void AVL::recursiveClear(Node*& temp) {
		if (temp != NULL) {
			// clear from small value to large value
			recursiveClear(temp->left);
			recursiveClear(temp->right);
			delete temp;
		}
	}

void AVL::rotateLeft(Node*& local_root) {
	
	Node* temp = local_root->right;
	local_root->right = temp->left;
	temp->left = local_root;
	local_root = temp;
	calc_height(temp->left);
}

void AVL::rotateRight(Node*& local_root) {
	Node* temp = local_root->left;
	local_root->left = temp->right;
	temp->right = local_root;
	local_root = temp;
	calc_height(temp->right);
}