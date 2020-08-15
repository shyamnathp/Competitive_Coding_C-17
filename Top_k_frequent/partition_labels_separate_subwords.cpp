#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<locale>

using namespace std;

typedef map<char, pair<int, int>> lettermap;

vector<int> FindSubStrings(string s)
{
	vector<int> subStrings;
	lettermap letterMap;

	for (int i = 0; i < s.size(); ++i)
	{
		auto iter = letterMap.find(s[i]);
		if (iter != letterMap.end())
		{
			//map already contains the letter
			letterMap[s[i]].second = i;
		}
		else
		{
			letterMap[s[i]] = pair<int, int>(i, i);
		}
	}

	int first = letterMap[s[0]].first, last = letterMap[s[0]].second;
		
	vector<int> positions;
	if (first == last)
		positions.push_back(0);

	for (int i = 1; i < s.size(); ++i)
	{
		int firstOfLetter = letterMap[s[i]].first;
		int lastOfLetter = letterMap[s[i]].second;
		if (lastOfLetter > last)
		{
			last = lastOfLetter;
		}
		if (i == last)
		{
			if (i + 1 < (s.size()))
			{
				positions.push_back(i);
				first = letterMap[s[i + 1]].first;
				last = letterMap[s[i + 1]].second;
				//++i;
			}
			else
			{
				positions.push_back(i);
			}
		}
	}
	int startIndex = 0;
	//string test1 = s.substr(9, 12);
	//string test2 = s.substr(15, 23);
	for (auto& endIndex : positions)
	{
		string test = s.substr(startIndex, endIndex+1);
		subStrings.push_back(s.substr(startIndex, endIndex+1 - startIndex).size());
		startIndex = endIndex + 1;
	}
	return subStrings;
}

int main()
{
	string s = "ababcbacadefegdehijhklij";
	//s = "abacbdedfgeelmnopn";
	//string test1 = s.substr(14, 15);
	vector<int> subStrings = FindSubStrings(s);
}