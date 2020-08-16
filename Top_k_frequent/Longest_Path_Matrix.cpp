#include<iostream>
#include<vector>

using namespace std;
using Vec = vector<vector<int>>;

int LongestPathSum(Vec matrix, int n, int m, int i, int j)
{
    if (i + 1 < n && j + 1 < m && matrix[i + 1][j] > matrix[i][j] && matrix[i][j + 1] > matrix[i][j])
        return 1 + max(LongestPathSum(matrix, n, m, i + 1, j), LongestPathSum(matrix, n, m, i, j + 1));
    else if (i + 1 < n && matrix[i + 1][j] > matrix[i][j])
        return 1 + LongestPathSum(matrix, n, m, i + 1, j);
    else  if (j + 1 < n && matrix[i][j + 1] > matrix[i][j])
        return 1 + LongestPathSum(matrix, n, m, i, j + 1);
    else
        return 1;
}

int main()
{
    vector<vector<int>> matrix= {
        { 1, 2, 3, 4 },
        { 2, 2, 3, 4 },
        { 3, 2, 3, 4 },
        { 4, 5, 6, 7 },
    };
    int n = 4, m = 4;

    cout<< LongestPathSum(matrix, n, m, 0, 0);
    return 0;
}