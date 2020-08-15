#include<iostream>
#include<algorithm>
#include<vector>
#include<memory>

using namespace std;

struct Node {
	int val;
	shared_ptr<Node> left = nullptr;
	shared_ptr<Node> right = nullptr;
	Node(int v) : val(v)
	{}
};

auto SearchInorder(vector<int> in, int key, vector<int>::iterator startIndex, vector<int>::iterator endIndex) -> decltype(startIndex)
{
	auto it = find(startIndex, endIndex, key);
	return it;
}

std::shared_ptr<Node> BuildTree(vector<int> in, vector<int> post, vector<int>::iterator startIndex, vector<int>::iterator endIndex, vector<int>::iterator pIndex)
{
	if (startIndex > endIndex)
		return nullptr;

	std::shared_ptr<Node> node = make_shared<Node>(*(pIndex));
	--pIndex;

	if (*startIndex == *(endIndex-1))
		return node;

	auto pos = SearchInorder(in, node->val, startIndex, endIndex);

	node->right = BuildTree(in, post, pos+1, endIndex, pIndex);
	node->left = BuildTree(in, post, startIndex, pos-1, pIndex);

	return node;
}

void preOrder(shared_ptr<Node> node)
{
	if (node == NULL)
		return;
	cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);
}

int main()
{
	vector<int> in = { 4, 8, 2, 5, 1, 6, 3, 7 };
	vector<int> post = { 8, 4, 5, 2, 6, 7, 3, 1 };

	auto root = BuildTree(in, post, in.begin(), in.end(), post.end()-1);
	preOrder(root);
}