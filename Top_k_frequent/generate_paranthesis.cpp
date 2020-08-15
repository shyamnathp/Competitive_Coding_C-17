#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void addParanthesis(int pos, int n, int open, int close, vector<string>& v)
{
	static char str[100];
	if (close == n)
	{
		v.push_back(str);
	}
	else
	{
		if (open > close)
		{
			str[pos] = ')';
			addParanthesis(pos + 1, n, open, close + 1, v);
		}

		if (open < n)
		{
			str[pos] = '(';
			addParanthesis(pos + 1, n, open + 1, close, v);
		}
	}
}
vector<string> generateParenthesis(int n) {
	vector<string> v;
	if (n == 1)
	{
		v = {"()"};
	}
	if (n != 0)
		addParanthesis(0, n, 0, 0, v);
	return v;
}

int main()
{
	int n = 4;
	string l = "test strng";
	vector<string> para = generateParenthesis(n);
}