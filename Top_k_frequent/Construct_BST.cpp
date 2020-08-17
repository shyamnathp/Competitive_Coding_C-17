#include<algorithm>
#include<memory>
#include<vector>
#include<functional>

#include<range/v3/algorithm/sort.hpp>

struct Node {
	int val;
	std::shared_ptr<Node> left = nullptr;
	std::shared_ptr<Node> right = nullptr;
	Node(int v) : val(v)
	{}
};

std::shared_ptr<Node> Construct(const std::vector<int>& vec, int l, int r)
{
	if (l > r)
		return nullptr;

	int m = l + (r-l)/ 2;
	auto parent = std::make_shared<Node>(vec[m]); 

	parent->left = Construct(vec, l, m-1);
	parent->right = Construct(vec, m+1, r);
	
	return parent;
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};
	
	ranges::sort(vec);
	int m = vec.size() / 2;
	auto head = Construct(vec, 0, vec.size()-1);
}