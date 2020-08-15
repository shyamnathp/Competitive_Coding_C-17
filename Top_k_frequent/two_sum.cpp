#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k;
	vector<int> nums(n, 0);
	for (auto& i : nums)
	{
		cin >> i;
	}

	int target;
	cin >> target;
	target = target - 30;

	map<int, int> numMap;

	int maxi = 0;
	pair<int, int> result = make_pair(0,0);
	for (int i=0;i<nums.size();++i)
	{
		int complement = target - nums[i];
		if (numMap.find(nums[i]) != numMap.end())
		{
			if (nums[i] > maxi && complement > maxi)
			{
				result.first = nums[i];
				result.second = complement;
				maxi = max(nums[i], complement);
			}
		}
		else
			numMap.insert(complement,i);
	}

}