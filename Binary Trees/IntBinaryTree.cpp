// Joseph Reed
// member function definitions

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

//**************************************************
// insert accepts a TreeNode pointer and a pointer *
// to a node. The functino inserts the node into   *
// the tree pointed to by the TreeNode pointer.    *
//**************************************************

void IntBinaryTree::insert(TreeNode *&nodeptr, TreeNode *&newNode) {
	if(nodeptr == NULL)
		nodeptr = newNode;					// insert the node
	else if(newNode->id < nodeptr->id)
		insert(nodeptr->left, newNode);		// search the left branch
	else
		insert(nodeptr->right, newNode);	// search the right branch
}

//**************************************************
// insertNode creates a new node to hold data      *
// passed into it and passes the new node to the   *
// insert function.                                *
//**************************************************

void IntBinaryTree::insertNode(int i, string n, string a, double g) {
	// pointer to new node
	TreeNode *newNode = NULL;

	// create a node and store data in it
	newNode = new TreeNode;
	newNode->id = i;
	newNode->name = n;
	newNode->address = a;
	newNode->grade = g;
	newNode->left = newNode->right = NULL;

	// insert function call. root declared in class 
	// member variables
	insert(root, newNode);
}

//**************************************************
// destroySubTree is called by the destructor. It  *
// deletes all nodes in the tree.                  *
//**************************************************

void IntBinaryTree::destroySubTree(TreeNode *nodePtr) {
	if(nodePtr) {
		// recursively move throughout tree
		if(nodePtr->left)
			destroySubTree(nodePtr->left);
		if(nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//**************************************************
// searchNode determines whether an id is present  *
// in the tree. If so, the function returns true.  *
// Otherwise, it returns false.                    *
//**************************************************

bool IntBinaryTree::searchNode(int i) {
	// start at root node
	TreeNode *nodePtr = root;

	// traverse tree until num is found or 
	// you run out of nodes
	while(nodePtr) {
		if(nodePtr->id == i) {
			cout << "Found!\n";
			cout << "-----------------------\n";
			cout << nodePtr->id << endl;
			cout << nodePtr->name << endl;
			cout << nodePtr->address << endl;
			cout << nodePtr->grade <<endl;
			cout << "-----------------------\n";
			return true;
		}
		else if(i < nodePtr->id)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	cout << "Not Found!\n";
	return false;
}

//**************************************************
// remove calls deleteNode to delete the node whose*
// id member is the same as id.                    *
//**************************************************

void IntBinaryTree::remove(int id) {
	deleteNode(id,root);
}

//**************************************************
// deleteNode deletes the node whose id member is  *
// the same as id.                                 *
//**************************************************

void IntBinaryTree::deleteNode(int id, TreeNode *&nodePtr) {
	if(id < nodePtr->id)
		deleteNode(id, nodePtr->left);
	else if(id > nodePtr->id)
		deleteNode(id, nodePtr->right);
	else 
		makeDeletion(nodePtr);
}

//**************************************************
// makeDeletion takes a reference to a pointer to  *
// the node that is to be deleted. The node is     *
// removed and the branches of the tree below the  *
// node are reattached.                            *
//**************************************************

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
	// define a temporary pointer to use in reattaching
	// the left subtree
	TreeNode *tempNodePtr = NULL;

	if(nodePtr == NULL)
		cout << "Cannot delete empty node.\n";
	else if(nodePtr->right == NULL) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;		// reattach the left child
		delete tempNodePtr;
	}
	else if(nodePtr->left == NULL) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;		// reattach the right child
		delete tempNodePtr;
	}
	// if the node has two children - left and right
	else {
		// move one node to the right
		tempNodePtr = nodePtr->right;
		// go to the end left node
		while (tempNodePtr->left) 
			tempNodePtr = tempNodePtr->left;
		// reattach the left subtree
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// reattach the right subtree
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//**************************************************
// displayInOrder displays the values in the       *
// subtree pointed to by nodePtr, via inorder      *
// traversal.                                      *
// InOrder Traversal                               *
// 1. The current node's left subtree is traversed *
// 2. The current node's data is processed         *
// 3. The current node's right subtree is traversed*
//**************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
	if(nodePtr) {
		displayInOrder(nodePtr->left);
		cout << "--------------------\n";
		cout << nodePtr->id << endl;
		cout << nodePtr->name << endl;
		cout << nodePtr->address << endl;
		cout << nodePtr->grade << endl;
		cout << "--------------------\n";
		displayInOrder(nodePtr->right);
	}
}

//**************************************************
// displayPreOrder displays the values in the      *
// subtree pointed to by nodePtr, via preorder     *
// traversal.                                      *
// PreOrder Traversal                              *
// 1. The current node's data is processed         *
// 2. The current node's left subtree is traversed *
// 3. The current node's right subtree is traversed*
//**************************************************

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
	if(nodePtr) {
		cout << "--------------------\n";
		cout << nodePtr->id << endl;
		cout << nodePtr->name << endl;
		cout << nodePtr->address << endl;
		cout << nodePtr->grade << endl;
		cout << "--------------------\n";
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//**************************************************
// displayPostOrder displays the values in the     *
// subtree pointed to by nodePtr, via postorder    *
// traversal.                                      *
// PostOrder Traversal                             *
// 1. The current node's left subtree is traversed *
// 2. The current node's right subtree is traversed* 
// 3. The current node's data is processed         *
//**************************************************
void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
	if(nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << "--------------------\n";
		cout << nodePtr->id << endl;
		cout << nodePtr->name << endl;
		cout << nodePtr->address << endl;
		cout << nodePtr->grade << endl;
		cout << "--------------------\n";
	}
}
