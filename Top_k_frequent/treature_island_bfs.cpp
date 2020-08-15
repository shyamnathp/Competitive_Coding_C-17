#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<queue>

using namespace std;

int BfsUtil(vector<vector<char>>& island)
{
	int rowSize = island.size();
	int colSize = island[0].size();
	vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	island[0][0] = 'D';	
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
				if (row<0 || col<0 || row>=rowSize || col>=colSize || island[row][col] == 'D')
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
	vector<vector<char>> island = { {'O', 'O', 'O', 'O', 'O'},
								   {'D', 'D', 'D', 'O', 'O'},
								   {'O', 'O', 'O', 'O', 'D'},
								   {'O', 'D', 'X', 'D', 'O'} };
	int count = BfsUtil(island);
}
