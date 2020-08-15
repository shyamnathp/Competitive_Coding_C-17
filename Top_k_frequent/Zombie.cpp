#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int Bfs(int rows, int colomns, vector<vector<int>>& grid)
{
	vector<int> v(rows*colomns, 0);
	queue<pair<int,int>> q;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; i < colomns; ++j)
		{
			if (grid[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	int size = q.size();
	int i = 1;
	int iteration = 1;
	while (q.size() != 0)
	{
		pair<int,int> current = q.front;
		q.pop();
		int first = current.first;
		int second = current.second;

		vector<pair<int, int>> dirs{make_pair(-1,0),make_pair(0,1),make_pair(0,-1),make_pair(1,0)};
		for (const auto &dir : dirs)
		{
			int tempFirst = first + dir.first;
			int tempSecond = second + dir.second;
			if ((rows >= tempFirst >= 0) && (colomns >= tempSecond >= 0))
			{
				grid[tempFirst][tempSecond] = 1;
				q.push(make_pair(tempFirst, tempSecond));
			}
		}

		if (i == size)
		{
			++iteration;
			i = 0;
			size = q.size();
		}

		++i;
	}

	return iteration;
}
int  main()
{
	int rows, colomns;
	cin >> rows >> colomns;
	vector<vector<int>> grid(rows, vector<int>(colomns));
	int iteration = Bfs(rows, colomns, grid);
	return iteration;
}