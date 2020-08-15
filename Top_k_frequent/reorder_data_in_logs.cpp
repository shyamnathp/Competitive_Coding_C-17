#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<queue>

using namespace std;

bool isNumber(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}

void reorderLogFiles(vector<string>& logs, vector<string>& digitLogs, vector<string>& letterLogs) {
 
	for (auto& log : logs)
	{
		stringstream logS(log);
		string word;
		logS >> word;
		while (logS >> word)
		{
			if (isNumber(word))
			{
				digitLogs.push_back(log); break;
			}
			else
			{
				letterLogs.push_back(log); break;
			}
		}
	}

	stringstream s1, s2;
	string top1, top2, str1, str2;
	std::sort(letterLogs.begin(), letterLogs.end(), [&](string a, string b) {
		stringstream s1(a);
		stringstream s2(b);
		string top1, top2;
		s1 >> top1; s2 >> top2;
		string str1 = a.substr(a.find_first_of(" \t") + 1);
		string str2 = b.substr(b.find_first_of(" \t") + 1);
		if (str1 == str2)
		{
			return top1 < top2;
		}
	    
		return str1 < str2;
	});

}

int main()
{
	//vector<string> logs = { "dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero", "let4 art zero" };
	vector<string> logs = {"mi2 jog mid pet", "wz3 34 54 398", "al alps cow bar", "x4 45 21 7"};
	vector<string> digitLogs, letterLogs;
	reorderLogFiles(logs, digitLogs, letterLogs);
	letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());
}