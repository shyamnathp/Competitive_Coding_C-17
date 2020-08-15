#include<iostream>
#include<memory>

using namespace std;

struct Node {
	int val;
	shared_ptr<Node> left=nullptr;
	shared_ptr<Node> right=nullptr;
	Node(int v) : val(v)
	{}
};

int FindDepth(shared_ptr<Node> current)
{
	if (current == nullptr)
		return 0;

	auto leftNode = FindDepth(current->left);
	auto rightNode = FindDepth(current->right);

	return leftNode > rightNode ? leftNode+1 : rightNode+1;
}

int FindNodeLevel(shared_ptr<Node> current, int n)
{
	if (current == nullptr)
		return INT_MIN;

	if (current->val == n)
		return 0;

	auto leftNode = FindNodeLevel(current->left, n);
	auto rightNode = FindNodeLevel(current->right, n);

	return leftNode > rightNode ? leftNode + 1 : rightNode + 1;
}

int SumNodes(shared_ptr<Node> current)
{
	if (current == nullptr)
		return 0;

	return current->val + SumNodes(current->left) + SumNodes(current->right);
}

//LeetCode
//void flatten(TreeNode* root) {
//	if (!root) return;
//	flatten(root->left);
//	flatten(root->right);
//	TreeNode *tmp = root->right;
//	root->right = root->left;
//	root->left = nullptr;
//	while (root->right)
//		root = root->right;
//	root->right = tmp;
//}

bool IsSumTree(shared_ptr<Node> current)
{
	if ((current->left == nullptr && current->right == nullptr) || (current == nullptr)) return true;

	if (current->val == (SumNodes(current) / 2))
		return true;
	else
		return false;

	return IsSumTree(current->left) && IsSumTree(current->right);
}

int main()
{
	auto root = make_shared<Node>(1);
	root->left = make_shared<Node>(2);
	root->right = make_shared<Node>(3);
	root->left->left = make_shared<Node>(4);
	root->left->right = make_shared<Node>(5);

	auto test = FindDepth(root);
	auto testLevel = FindNodeLevel(root, 4);
	auto testSum = SumNodes(root);
	auto testSumTree = IsSumTree(root);
}
