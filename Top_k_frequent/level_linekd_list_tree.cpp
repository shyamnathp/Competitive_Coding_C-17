#include<iostream>
#include<memory>
#include<queue>

using namespace std;

struct Node {
	int val;
	shared_ptr<Node> left = nullptr;
	shared_ptr<Node> right = nullptr;
	shared_ptr<Node> nextRight = nullptr;
	Node(int v) : val(v)
	{}
};

void BuildLevel(shared_ptr<Node> current)
{
	queue<Node> q;
	q.push();
}

int main()
{
	auto root = make_shared<Node>(1);
	root->left = make_shared<Node>(2);
	root->right = make_shared<Node>(3);
	root->left->left = make_shared<Node>(4);
	root->left->right = make_shared<Node>(5);

}