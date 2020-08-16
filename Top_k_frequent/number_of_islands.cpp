#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<map>

using namespace std;

typedef vector<vector<int>> vec2d;

template<typename T>
void BfsUtil(const T& island, const T& visited, pair<int, int> index)
{
	static vector<pair<int, int>> movements = { {1,0},{0,1},{-1,0},{0,-1} };
	queue<pair<int, int>> q;
	q.push(index);

	while (!q.empty())
	{
		auto [i,j] = q.front();
		q.pop();

		for (const auto& [m_i, m_j] : movements)
		{
			if (i + m_i < island.size() && j + m_j < island[0].size() && island[i + m_i][j + m_j] == 1)
			{
				visited[i + m_i][j + m_j] == true;
				q.push({i+m_i, j+m_j});
			}
		}
	}
}

int FindIslands(const vec2d& island)
{
	vec2d visited(island.size(), vector<int>(island[0].size(),0));
	auto count = 0;
	for(int i=0; i<island.size(); ++i)
		for (int j = 0; j < island.size(); ++j)
		{
			if (!visited[i][j])
			{
				++count;
				BfsUtil(island, visited, make_pair(i,j));
			
			}
		}
	return count;
}

int main()
{
	vec2d island = { {1, 1, 1, 1, 0},
								   {1, 1, 0, 1, 0},
								   {1, 1, 0, 0, 0},
								   {0, 0, 0, 0, 0}};
	int count = FindIslands(island);
}