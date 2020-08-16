#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int FindLargestLength(map<string, string>& itemAssociation, string current)
{
	if (itemAssociation.find(current) == itemAssociation.end())
		return 0;
	return 1 + FindLargestLength(itemAssociation,itemAssociation[current]);
}

int main()
{
	map<string, string> itemAssociation= { {"item1", "item2"}, {"item3", "item4"}, {"item4", "item5"} };
	int length = INT_MIN;
	for (auto& [i, j]: itemAssociation)
	{
		length = 1 + max(length, FindLargestLength(itemAssociation, i));
	}
}