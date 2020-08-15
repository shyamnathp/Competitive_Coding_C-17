#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<list>
#include<queue>

using namespace std;

int main()
{
	vector<int> nums = {2,1,1,2};
	if (nums.empty())
		return 0;
	//else if (nums.size() == 1)
	//	return nums[0];
	//else if (nums.size() == 2)
	//	return max(nums[0], nums[1]);


	vector<int> dp(nums.size()+1, 0);
	dp[0] = 0;
	dp[1] = nums[0];

	for (int i = 2; i <= nums.size(); ++i)
	{
		dp[i] = max(dp[i - 2] + nums[i-1], dp[i - 1]);
	}
	
	int test = dp[nums.size()];
}