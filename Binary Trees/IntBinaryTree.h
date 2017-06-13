// Joseph Reed
// IntBinaryTree.h
// binary tree class definition

#include <iostream>
using namespace std;

class IntBinaryTree {
	private:
		struct TreeNode {
			int id;
			string name;
			string address;
			double grade;
			TreeNode *left; 	// left child pointer
			TreeNode *right;	// right child pointer
		};
		TreeNode *root;			// root pointer

		//private member functions
		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		void deleteNode(int, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;
		void displayPreOrder(TreeNode *) const;
		void displayPostOrder(TreeNode *) const;

	public:
		// constructor
		IntBinaryTree() {
			root = NULL;
		}

		// destructor
		~IntBinaryTree() {
			destroySubTree(root);
		}

		// binary tree operations
		void insertNode(int, string, string, double);
		bool searchNode(int);
		void remove(int);
		void displayInOrder() const {
			displayInOrder(root);
		}
		void displayPreOrder() const {
			displayPreOrder(root);
		}
		void displayPostOrder() const {
			displayPostOrder(root);
		}
};