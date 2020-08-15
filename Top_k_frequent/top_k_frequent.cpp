#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<map>

using namespace std;

int main()
{
	std::vector<std::string> vecMain = {"Anacell provides the best services in the city anacell", "betacellular has awesome services", "Best services provided by anacell, everyone should use anacell"};
	std::vector<std::string> vecWords = {"anacell", "cetracular", "betacellular"};
	vector<pair<string, int>> mapWords;

	//copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(vecMain));
	//copy(istream_iterator<string>(iss1), istream_iterator<string>(), back_inserter(vecWords));

	for (const auto& word : vecWords)
	{
		int count = 0;
		int cou = std::count_if(vecMain.begin(), vecMain.end(), [&](string review)
		{   
			std::transform(review.begin(), review.end(), review.begin(), ::tolower);
			istringstream s(review);
			
			int c = std::count(istream_iterator<string>(s), istream_iterator<string>(), word);
			if (c > 0)
				count = count + 1;
			return true;
		});
	    mapWords.emplace_back(make_pair(word, count));
	}

	sort(mapWords.begin(), mapWords.end(), [](pair<string, int> s, pair<string, int> s1) {
		return ((s.second > s1.second) || ((s.second == s1.second) && (s.first > s1.first)));
	});

	auto mapIterator = mapWords.begin();
	int n = 2;
	vector<string> mostK(n);
	for (int i=0; i<n;++i)
	{
		auto mapWord = *mapIterator;
		mostK[i]=(mapWord.first);
		mapIterator = mapIterator + 1;
	}
	int test = 1;
}