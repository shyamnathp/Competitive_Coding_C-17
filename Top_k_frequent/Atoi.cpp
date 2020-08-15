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
	string s(" -000000000000001");
	/*auto ifNeg = s.find('-');
	s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }), s.end());

	if (ifNeg == string::npos)
		return stoi(s);
	else
		return -stoi(s);*/

	auto pos = s.find_first_not_of(" ");

	auto test1 = s[pos];

	for (; s[pos] == '0'; ++pos);

	if (pos == std::string::npos)
		return 0;

	if (isdigit(s[pos]) || (s[pos] == '-') || (s[pos] == '+'))
	{
		long long out=0;
		bool ifNeg = s[pos] == '-' ? true : false;
		bool ifPos = s[pos] == '+' ? true : false;
		/*s.erase(remove_if(s.begin(), s.end(), [](char c) { 
			return !isdigit(c); }), s.end());*/
		string newStr="";

		if (ifNeg)
			++pos;
		else if (ifPos)
			++pos;

		for (int i = pos; isdigit(s[i]); ++i)
		{
			newStr += s[i];
		}

		if (newStr.size() > 10)
		{
			if (ifNeg)
				return INT_MIN;
			else
				return INT_MAX;

		}
		
		for (int i = 0; i < newStr.size(); ++i)
		{
			int digit = (newStr[i] - '0');
			out = out + digit * pow(10, newStr.size()-i-1);
		}

		if (out > INT_MAX && !ifNeg)
			return INT_MAX;
		else if ((-out) < INT_MIN)
			return INT_MIN;

		if (ifNeg)
			return -out;
		else
			return out;
	
	}
	else
	{
		return 0;
	}

}