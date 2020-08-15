#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> nums = {2,7,11,15};
	int target = 9;
	vector<int> result;
	map<int, pair<int, int>> number;

	for (int i = 0; i < nums.size(); ++i)
	{
		int targetNum = target - nums[i];
		if (number.find(nums[i]) == number.end())
		{
			number[targetNum] = make_pair(i, nums[i]);
		}
		else
		{
			result = { i, number[nums[i]].first };
			sort(result.begin(), result.end());
		}
	}
   
	int test = 0;
}