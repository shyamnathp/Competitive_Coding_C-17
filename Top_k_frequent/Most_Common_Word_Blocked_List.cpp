#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<locale>

using namespace std;

int main()
{
	string paragraph = "Bob hit a ball, the hit BALL flew,far,after it was hit. flew ball flew it flew";
	std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
		[](unsigned char c) { return tolower(c); });
	/*paragraph.erase(std::remove_if(paragraph.begin(), paragraph.end(),
		[](char c) { return !(isspace(c) || isalpha(c)); }),
		paragraph.end());*/
	std::replace_if(paragraph.begin(), paragraph.end(),
		[](const char& c) { return !(isspace(c) || isalpha(c)); }, ' ');

	stringstream para(paragraph);
	string inputWord;
	vector<string> banned = { "hit" };
	map<string, int> mWords;
	int max = 0;
	string sMax = "";
	while (para >> inputWord)
	{
		auto checkWord = std::find_if(banned.begin(), banned.end(), [inputWord](const string& ban) {return ban == inputWord; });
		if (checkWord == banned.end())
		{
			++mWords[inputWord];
			if (mWords[inputWord] > max)
			{
				sMax = inputWord;
				max = mWords[inputWord];
			}
   	    }
	}

}