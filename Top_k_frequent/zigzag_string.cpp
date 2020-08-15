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
	string s = "PAYPALISHIRING";
	int numRows = 3;
	vector<string> v(numRows, "");
	string out;

	if (numRows == 1)
	{
		int test = 0;
		//return s;
	}

	for (int i = 0, step=1, row=0; i < s.size(); ++i)
	{
		v[row] += s[i];
		if (row == 0)
			step = 1;
		if (row == numRows - 1)
			step = -1;
		row = row + step;
	}

	for (const auto& row : v)
		out += row;

	int test2 = 0;
}