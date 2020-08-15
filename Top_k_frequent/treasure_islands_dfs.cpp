#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef vector<vector<int>> vecpair;

int IsSafe(const vecpair& M, vecpair& visited, int nRow, int nCol)
{
	int rows = M.size();
	int colomns = M[0].size();

	return ((nRow >= 0) && (nRow < rows) && (nCol >= 0) && (nCol < colomns) && ((!visited[nRow][nCol]) && M[nRow][nCol]));
}

void DFS(const vecpair& M, vecpair& visited, int r, int c)
{
	/*static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };*/

	static int rowNbr[] = { -1, 0, 1, 0};
	static int colNbr[] = { 0, -1, 0, 1};
	visited[r][c] = 1;

    //change to 8 for all adjacents
	for (int i = 0; i < 4; ++i)
		if (IsSafe(M, visited, r + rowNbr[i], c + colNbr[i]))
			DFS(M, visited, r + rowNbr[i], c + colNbr[i]);
}

int countIslands(vector<vector<int>>& M)
{
	int rows = M.size();
	int colomns = M[0].size();
	vector<vector<int>> visited = vector<vector<int>>(rows, vector<int>(colomns, 0));
	int count = 0;
	for(int i=0; i<rows;++i)
		for(int j=0; j<colomns;++j)
			if (!visited[i][j] && M[i][j])
			{
				DFS(M, visited, i, j);
				++count;
			}

	return count;
}

int main()
{
	vector<vector<int>> M= { { 1, 1, 0, 0, 0 },
						   { 1, 1, 0, 0, 0 },
					       { 0, 0, 1, 0, 0 },
					       { 0, 0, 0, 1, 1 }};

	cout << "Number of islands is: " << countIslands(M);
}