#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

using namespace std;

bool isUnique(string s)
{
	set<char> s1(s.begin(), s.end());
	return s.size() == s1.size();
}

int main()
{
	string s = "abcabc";
	int n = 3;
	vector<string> uniqueSub;

	for (int i = 0; i + n <= s.size(); ++i)
	{
		string sub = s.substr(i, n);
		if (isUnique(sub))
		{
			uniqueSub.push_back(sub);
		}
	}
}