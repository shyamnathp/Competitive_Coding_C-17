#include<iostream>
#include<vector>

using namespace std;

int KnapSack(vector<int> wt, vector<int> val, int W, int n)
{
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return KnapSack(wt, val, W, n - 1);
	else
		return max(val[n - 1] + KnapSack(wt, val, W - wt[n - 1], n - 1), KnapSack(wt, val, W, n - 1));
}

int main()
{
	vector<int> val = {60, 100, 120};
	vector<int> wt = { 10, 20, 30 };
	int W = 50;
	cout << KnapSack(wt, val, W, val.size());
}