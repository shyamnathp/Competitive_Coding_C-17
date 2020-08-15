#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//This is actually the code for bridges

typedef vector<vector<int>> vecpair;

void findAPTarjans(int vertex, vector<int>& disc, vector<int>& low, vector<bool>& visited, vector<int>& parent, vector<vector<int>>& bridges, vector<vector<int>>& adj)
{
	static int time = 0;
	visited[vertex] = true;
	disc[vertex] = low[vertex] = ++time;
	vector<int>::iterator i;
	for (i = adj[vertex].begin(); i < adj[vertex].end(); ++i)
	{
		int current = *i;
		if (!visited[current])
		{
			parent[current] = vertex;
			findAPTarjans(current, disc, low, visited, parent, bridges, adj);

			low[vertex] = min(low[vertex], low[current]);

			if (low[current] > disc[vertex])
				bridges.push_back({ vertex, current });
		}
		else if (current != parent[vertex])
		{
			low[vertex] = min(low[vertex], disc[current]);
		}
	}
}


vector<vector<int>> findAP(vecpair& v, int numNodes)
{
	vector<int> disc(numNodes, 0);
	vector<int> low(numNodes, 0);
	vector<bool> visited(numNodes, false);
	vector<int> parents(numNodes, -1);
	vector<vector<int>> bridges;

	for (int i = 0; i < numNodes; ++i)
	{
		if (!visited[i])
			findAPTarjans(i,disc,low,visited, parents, bridges, v);
	}

	return bridges;
    
}

int main()
{
	int numNodes, numEdges;
	numNodes = 5;

	vecpair v = { {1, 2}, { 1, 3 }, { 3, 4 }, { 1, 4 }, { 4, 5 } };
	//{ {1, 2}, { 1, 3 }, { 3, 4 }, { 1, 4 }, { 4, 5 }};
	//v[0].push_back(1);
	//v[0].push_back(2);
	//v[1].push_back(2);
	//v[1].push_back(0);
	//v[2].push_back(1);
	//v[2].push_back(0);
	//v[3].push_back(1);
	//v[1].push_back(3);

	//for (int i = 0; i < numEdges; ++i)
	//{
	//	auto a=0, b=0;
	//	cin >> a >> b;
	//	v[a].push_back(b);
	//	v[b].push_back(a);
	//}

	vector<vector<int>> adj(numNodes);

	for (int i = 0; i < v.size(); ++i)
	{
		int first = (v[i][0]);
		int second = v[i][1];
		first -= 1;
		second -= 1;
		adj[first].push_back(second);
		adj[second].push_back(first);
	}

	auto bridge = std::move(findAP(adj, numNodes));
}