#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

int KthElement(vector<int>::iterator a, int m, vector<int>::iterator b, int n, int k)
{
	if (m < n)
		return KthElement(b, n, a, m, k);

	if (n == 0)
		return *(a+k-1);

	if (k == 1)
		return min(*(a), *(b));

	int j = min(n, k / 2);
	int i = k - j;

	if (*(a + i - 1) > *(b + j - 1))
		return KthElement(a, i, b + j, n - j, k - j);
	return KthElement(a + i, m - i, b, n, k - i);
}

int main()
{
	vector<int> a = {1,2};
	vector<int> b = {3,4};
	int m = a.size();
	int n = b.size();
	int k = (m + n) / 2;
	int m1 = KthElement(a.begin(), m, b.begin(), n, k + 1);
	if ((m + n) % 2 == 0) {
		int m2 = KthElement(a.begin(), m, b.begin(), n, k);
		return ((double)m1 + m2) / 2.0;
	}
	return m1;
}