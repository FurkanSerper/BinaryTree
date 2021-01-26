// M_Interview_FurkanSerper.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
// it is a Binary Tree Search algorithm project created by Furkan Serper 27.01.2021
// there is a reference value in algorithm. program prints a value which is the closest and bigger and than reference value.

#include <iostream>
using namespace std;

// main components of the algorithm. 
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// it is for creating  new node. it is called when the node is NULL
struct Node* newNode(int val) {
	struct Node* str = (struct Node*)malloc(sizeof(struct Node));
	str->data = val;
	str->left = NULL;
	str->right = NULL;
	return str;
}

// adds desire value in node
struct Node* addNewValue(struct Node* node, int addVal) {
	// Return a new node if the tree is empty
	if (node == NULL) {

		return newNode(addVal);
	}
	// adds the value depending on node value. if it is bigger than the node value, it will be placed to right
	if (addVal < node->data) {
		node->left = addNewValue(node->left, addVal);
	}
	else {
		node->right = addNewValue(node->right, addVal);
	}
	return node;
}

// it provides to sort small to big
// first left branch then right branch, because left one is less than right one.
void sortStoB(struct Node* root) {
	if (root != NULL) {
		//  left branch
		sortStoB(root->left);

		cout << root->data << " --> ";

		// right branch
		sortStoB(root->right);
	}
}

// ref is the reference value.
int findBiggerAndClosestValue(struct Node* root, int ref) {

	static bool flagControl = false;		//it is set true when result is found! Helps to avoid update result in if statement
	static int result = 0;					//it stores the result

	if (root != NULL) {

		findBiggerAndClosestValue(root->left, ref);

		if ((ref < root->data) && (flagControl == false)) {  //if the value in the node is bigger than ref, it is the target value. Needed to avoid update after reaching the desired value

			flagControl = true;
			result = root->data;
		}
		findBiggerAndClosestValue(root->right, ref);
	}
	return result;
}
int main()
{

	int referenceValue = 13;
	struct Node* root = NULL;

	// these are the value that will be added in binary tree.
	root = addNewValue(root, 8);
	root = addNewValue(root, 12);
	root = addNewValue(root, 1);
	root = addNewValue(root, 7);
	root = addNewValue(root, 27);
	root = addNewValue(root, 22);
	root = addNewValue(root, 16);
	root = addNewValue(root, 19);

	cout << "Sorted value: ";
	sortStoB(root); // sorts small to big

	//it prints the value that is bigger than the reference and the closest value in the node.
	cout << "\n\nresult: " << findBiggerAndClosestValue(root, referenceValue) << endl;

}

