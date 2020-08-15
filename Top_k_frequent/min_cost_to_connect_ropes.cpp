#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>

using namespace std;

int main()
{
	vector<int> ropeLengths = { 8, 4, 6, 12 };
	std::priority_queue<int, vector<int>, std::greater<int>> ropes(ropeLengths.begin(), ropeLengths.end());

	int cost = 0;
	while (ropes.size() != 1)
	{
		int first = ropes.top();
		ropes.pop();
		int second = ropes.top();
		ropes.pop();
		cost += (first + second);
		ropes.push(first + second);
	}
}