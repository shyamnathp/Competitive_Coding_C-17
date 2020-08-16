#include<iostream>
#include<string>
#include<tuple>
#include<optional>

using namespace std;

tuple<int, std::optional<int>> FindRepeatLength(const string& str, int position)
{
	int newPositon = 0;
	char current = str[position];
	int count = 1;

	for (int i=position+1;i<str.size();++i)
	{
		if (str[i] == current)
			++count;
		else
			break;
	}

	return make_tuple(count, make_optional<int>(position + count));
}

string RLE(const string& str)
{
	int count = 0;
	string newString = "";
	//std::optional<int> newPos = std::nullopt;
	for (int i = 0; i < str.size(); i = i + count)
	{
		auto [c, newPos] = FindRepeatLength(str, i);
		count = c;
		newString += str[i] + to_string(count);
	}
	return newString;
}

int main()
{
	string str = "wwwwaaadexxxxxxywww";
	cout << RLE(str);
}