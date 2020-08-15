#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<list>
#include<queue>

using namespace std;

string longestPalindrome(string s)
{
	if (s.empty())return "";
	if (s.size() == 1) return s;

	int minBegin = 0, maxLen = 1;
	for (int i = 0; i < s.size(); )
	{
		if (s.size() - i <= maxLen / 2) break;
		int j = i, k = i;
		while (k < s.size() - 1 && s[k + 1] == s[k]) 
			++k;
		i = k + 1;
		while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) 
		{ 
			++k; 
			--j; 
		} // Expand.
		int new_len = k - j + 1;
		if (new_len > maxLen) { 
			minBegin = j; 
			maxLen = new_len; 
		}
	}
	return s.substr(minBegin, maxLen);
}

int main()
{
	string s = "hellomalayalammymother";
	string longPal = longestPalindrome(s);
}