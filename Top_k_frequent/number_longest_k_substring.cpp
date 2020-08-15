# include <string>
# include <iostream>
# include <unordered_map>
using namespace std;

// the number of subarrays with at most K distinct elements
int most_k_chars(string &s, int k) {
	if (s.size() == 0) {
		return 0;
	}
	unordered_map<char, int> table;
	int num = 0, left = 0;
	for (int i = 0; i < s.size(); i++) {
		table[s[i]]++;
		while (table.size() > k) {
			table[s[left]]--;
			if (table[s[left]] == 0) {
				table.erase(s[left]);
			}
			left++;
		}
		num += i - left + 1;
		cout << s.substr(left, i)<<"\n";
	}
	return num;
}

int exact_k_chars(string &s, int k) {
	return most_k_chars(s, k) - most_k_chars(s, k - 1);
}

int main() {
	string s1 = "pqpqs";
	cout << "Answer should be 7: " << exact_k_chars(s1, 2) << endl;
	string s2 = "aabab";
	cout << "Answer should be 0: " << exact_k_chars(s2, 3) << endl;
}