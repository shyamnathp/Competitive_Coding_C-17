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
	int32_t num = 1534236469;
	string numString = to_string(num);
	string revNumString(numString.rbegin(), numString.rend());

	long long revNum = stoi(revNumString);
	if (num < 0)
		return -revNum;

	return revNum;
}