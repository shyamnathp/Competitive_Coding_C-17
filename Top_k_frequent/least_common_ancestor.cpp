#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Node
{
	struct Node *left, *right;
	int key;
};

// Utility function to create a new tree Node 
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

Node* findLCA(Node* current, int n1, int n2)
{
	if (current == NULL)
		return NULL;

	if (current->key == n1 || current->key == n2)
		return current;
	Node* leftLCA = findLCA(current->left, n1, n2);
	Node* rightLCA = findLCA(current->right, n1, n2);

	if (leftLCA && rightLCA)
		return current;
 
	return (leftLCA != NULL) ? leftLCA : rightLCA;
}
int main()
{
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
	cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
	cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
	cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
	return 0;
}