#include<vector>
#include<limits.h>

using namespace std;

using graph_t = vector<vector<int>>;


int MinKey(vector<int>& key, vector<bool>& mstSet)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < key.size(); ++v)
	{
		if (mstSet[v] == false && key[v] < min)
		{
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}

void PrimMST(const graph_t& graph)
{
	int r_size = graph.size();

	vector<bool> mstSet(r_size, false);
	vector<int> parent(r_size);
	vector<int> key(5,INT_MAX);

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < r_size - 1; ++count)
	{
		int u = MinKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < r_size; ++v)
		{
			if (graph[u][v] & mstSet[v] == false & graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
		}
	}
}

int main()
{
	graph_t graph = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	PrimMST(graph);
}