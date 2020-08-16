#include<iostream>
#include<memory>

using namespace std;

struct Node {
	int val;
	shared_ptr<Node> left = nullptr;
	shared_ptr<Node> right = nullptr;
	Node(int v) : val(v)
	{}
};