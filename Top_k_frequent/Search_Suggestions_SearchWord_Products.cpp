#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<queue>

using namespace std;

vector<string> suggestedProducts(vector<string>& products, string subWord) {
	int subWordSize = subWord.size();
	vector<string> suggestions;
	auto i = std::find_if(products.begin(), products.end(), [&](string& product) {
		string subProduct = product.substr(0, subWordSize);
		auto s1 = subProduct.c_str();
		auto s2 = subWord.c_str();
		int compare = strcmp(s1,s2);
		if (compare == 0)
		{
			suggestions.push_back(product);
			if (suggestions.size() == 3)
				return true;
		}
		return false;
	});

	return suggestions;
}

int main()
{
	vector<string> products = { "bags","baggage","banner","box","cloths" };
	std::sort(products.begin(), products.end());
	string searchWord = "tatiana";
	int searchWordSize = searchWord.size();
	vector<vector<string>> listPorducts(searchWord.size());
	for (int i = 1; i <= searchWordSize; ++i)
	{
		string subSearchWord = searchWord.substr(0, i);
		listPorducts[i-1] = suggestedProducts(products, subSearchWord);
	}
}