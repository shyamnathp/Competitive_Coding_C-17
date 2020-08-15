#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//TreeNode* SearchTree(TreeNode* root, int val)
//{
//	if (root == NULL)
//		return NULL;
//
//	TreeNode* node = SearchTree(root->left, val);
//
//	if (root->val == val)
//		return root;
//
//	if (node != nullptr)
//		return node;
//	
//	return SearchTree(root->right, val);;
//}
//
//int size(TreeNode* node)
//{
//	if (node == NULL)
//		return 0;
//	else
//		return(size(node->left) + 1 + size(node->right));
//}
//
//bool isSubtree(TreeNode* s, TreeNode* t) {
//
//	TreeNode* rootSubtree = SearchTree(s, t->val);
//	if (rootSubtree == NULL)
//		return false;
//	int sizeT = size(t);
//	int sizeS = size(rootSubtree);
//
//	return sizeT == sizeS;
//
//}
//
//int main()
//{
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(4);
//	root->left->left = new TreeNode(1);
//	root->left->right = new TreeNode(2);
//	root->right = new TreeNode(5);
//
//	TreeNode* subRoot = new TreeNode(4);
//	subRoot->left = new TreeNode(1);
//	subRoot->right = new TreeNode(2);
//
//	isSubtree(root, subRoot);
//
//	return 0;
//}

bool equal(TreeNode* s, TreeNode* t)
{
	if (s == NULL && t == NULL)
		return true;
	if (s == NULL || t == NULL)
		return false;

	return (s->val == t->val) && equal(s->left, t->left) && equal(s->right, t->right);
}

bool traverse(TreeNode* s, TreeNode* t)
{
	return s != NULL && (equal(s, t) || traverse(s->left, t) || traverse(s->right, t));
}

bool isSubTree(TreeNode* s, TreeNode* t)
{
	bool isSame = traverse(s, t);
}

 