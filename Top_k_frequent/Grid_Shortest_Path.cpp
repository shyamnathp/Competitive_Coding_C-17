#include<iostream>
#include<vector>
#include<algorithm>
#include<optional>
#include<queue>

using namespace std;

std::optional<int> minDistance(const vector<vector<char>>& grid)
{
	using matbool = vector<vector<bool>>;
	matbool visited(grid.size(), vector<bool>(grid[0].size(),false));
	pair source = make_pair(INT_MAX, INT_MAX);

	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == '0')
				visited[i][j] = true;

			if (grid[i][j] == 's')
				source = { i,j };
		}
	}

	queue<pair<int, int>> q;
	q.push(source);

	while (!q.empty())
	{
		auto[i, j] = q.front();
		q.pop();

		//moving right
		if (j < grid[0].size() - 1 && grid[i][j + 1] == '*')
		{
			q.push(make_pair(i, j + 1));
			visited[i][j + 1] = true;
		}

		//moving left
		if (j >= 0 && grid[i][j - 1] == '*')
		{
			q.push(make_pair(i, j - 1));
			visited[i][j - 1] = true;
		}

		//moving up
		if (i < grid.size() - 1 && grid[i - 1][j] == '*')
		{
			q.push(make_pair(i - 1, j));
			visited[i - 1][j] = true;
		}

		//moving down
		if (j < grid.size() - 1 && grid[i + 1][j] == '*')
		{
			q.push(make_pair(i + 1, j));
			visited[i + 1][j] = true;
		}
	}
	return std::nullopt;
}

int main()
{
	vector<vector<char>> grid = { { '0', '*', '0', 's' },
					   { '*', '0', '*', '*' },
					   { '0', '*', '*', '*' },
					   { 'd', '*', '*', '*' } };
	if (auto ans = minDistance(grid))
	{
		cout << ans.value();
	}
	return 0;
}