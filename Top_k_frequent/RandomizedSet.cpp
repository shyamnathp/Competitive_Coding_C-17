#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

class RandomizedSet {
	map<int, int> m;
	vector<int> arr;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		//auto test = m.find(val);
		if (m.find(val) != m.end())
			return false;
		int index = arr.size();
		arr.emplace_back(val);
		m.insert(make_pair(val, index));
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (m.find(val) == m.end())
			return false;

		int index = m[val];
		m.erase(val);

		int last = arr.size() - 1;
		swap(arr[index], arr[last]);
		arr.pop_back();
		if (m.size() != 0)
		{
			m[arr[index]] = index;
		}
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		//srand(time(NULL));
		int index = rand() % arr.size();
		return arr[index];
	}
};

int main()
{
	 RandomizedSet* obj = new RandomizedSet();
	 bool param_1, param_2;
	 int param_3;
	 param_2 = obj->remove(0);
	 param_2 = obj->remove(0);
	 param_1 = obj->insert(0);
	 param_3 = obj->getRandom();
	 param_2 = obj->remove(0);
	 param_1 = obj->insert(0);
}