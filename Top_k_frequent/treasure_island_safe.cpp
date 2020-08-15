#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<queue>

using namespace std;

int BfsUtil(pair<int,int> start, vector<vector<char>> island ) //, vector<pair<int, int>>& X)
{
	int rowSize = island.size();
	int colSize = island[0].size();
	vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	queue<pair<int, int>> q;
	q.push(start);
	island[start.first][start.second] = 'D';
	int count = 1;

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			auto front = q.front();
			q.pop();

			for (auto& dir : dirs)
			{
				int row = front.first + dir.first;
				int col = front.second + dir.second;
				if (row < 0 || col < 0 || row >= rowSize || col >= colSize || island[row][col] == 'D')
					continue;
				if (island[row][col] == 'X')
					return count;
				q.push(make_pair(row, col));
				island[row][col] = 'D';
			}
		}
		++count;
	}
	return -1;

}
int main()
{
	vector<vector<char>> island = { {'S', 'O', 'O', 'S', 'S'},
									{'D', 'O', 'D', 'O', 'D' },
									{'O', 'O', 'O', 'O', 'X' },
									{'X', 'D', 'D', 'O', 'O'},
									{'X', 'D', 'D', 'D', 'O' }};
	vector<pair<int, int>> S;
	vector<pair<int, int>> X;
	for (int i = 0; i < island.size(); ++i)
	{
		for (int j = 0; j < island[0].size(); ++j)
		{
			/*if (island[i][j] == 'X')
			{
				X.push_back(make_pair(i, j));
			}*/
			if (island[i][j] == 'S')
			{
				S.push_back(make_pair(i,j));
			}
		}
	}

	int count = INT_MAX;
	for (auto& s : S)
	{
		count = min(count, BfsUtil(s, island));
	}
}
