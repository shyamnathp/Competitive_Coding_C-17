#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<locale>

using namespace std;

typedef set<vector<int>> setvec;

vector<int> NextState(vector<int>& currenState)
{
	vector<int> temp = currenState;
	temp[0] = currenState[1] ? 1 : 0;
	temp[currenState.size() - 1] = currenState[currenState.size() - 2] ? 1 : 0;
	for (int i = 1; i < (currenState.size() - 1); ++i)
	{
		if ((currenState[i - 1] == 1 && currenState[i + 1] == 1) || (currenState[i - 1] == 0 && currenState[i + 1] == 0))
		{
			temp[i] = 0;
		}
		else
		{
			temp[i] = 1;
		}
	}

	/*temp[0] = temp[currenState.size() - 1] = 0;*/

	return temp;
}

vector<int> FindNState(vector<int>& initialState, int N)
{
	vector<int> nthState(initialState.size());
	setvec uniqueStates;
	vector<int> current = initialState;
	set<vector<int>> ::iterator iter = uniqueStates.begin();
	int cyclePosition = 0, posLen = 0;
	bool cycle = false;
	for (int i = 0; i < N; ++i)
	{
		set<vector<int>> ::iterator found = uniqueStates.find(current);
		if (found != uniqueStates.end())
		{//already exists;
			cyclePosition = std::distance(uniqueStates.begin(), found);
			posLen = i - cyclePosition;
			cycle = true;
			break;
		}
		else
		{
			uniqueStates.insert(current);
			current = NextState(current);
		}
	}
	uniqueStates.insert(current);

	if (cycle)
	{
		N = N - cyclePosition;
		N %= posLen;
		int toMove = cyclePosition + N;
		iter = uniqueStates.begin();
		advance(iter, toMove);
		nthState = *iter;
	}
	else
	{
		return current;
	}

	return nthState;
}

int main()
{
	int cells[] = {1, 1, 1, 0, 1, 1, 1, 1};
	int *p = cells;
	vector<int> cellStates;
	while (*p == 0 || *p ==1)
	{
		cellStates.push_back(*p);
		p = p + 1;
	}
	int N = 2;

	vector<int> nthState = FindNState(cellStates, N);
}