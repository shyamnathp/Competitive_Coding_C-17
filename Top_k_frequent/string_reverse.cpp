#include<iostream>
#include<string>
#include<sstream>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string text = "my name is shyam";
	istringstream s(text);

	vector<string> textWords{ istream_iterator<string>(s), istream_iterator<string>() };
	reverse(textWords.begin(), textWords.end());
}